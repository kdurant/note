1. 接口里可以包含函数和任务
2. 可以使用`modport`给接口里的信号指定方向

# 使用interface的简单tb结构
1. 声明interface(midport)
2. 使用`program---endprogram`驱动信号
3. dut

```verilog
interface mem_if
(
    input logic clk
);
logic                       reset;
logic                       we_sys;
logic        cmd_valid_sys;
logic        ready_sys;
logic  [7:0] data_sys;
logic  [7:0] addr_sys;
logic        we_mem;
logic        ce_mem;
logic  [7:0] datao_mem;
logic  [7:0] datai_mem;
logic  [7:0] addr_mem;

modport system
(
    input                       clk, reset, we_sys, cmd_valid_sys, addr_sys, datao_mem,
    output                      we_mem, ce_mem, addr_mem, datai_mem, ready_sys, ref data_sys,
);

modport memory
(
    input                       clk, reset, we_mem, ce_mem, addr_mem, datai_mem,
    output                      datao_mem
);

modport tb
(
    input                       clk, ready_sys, 
    output                      reset, we_sys, cmd_valid_sys, addr_sys, ref data_sys
);

endinterface

module memory_model (mem_if.memory mif);
// Memory array
logic [7:0] mem [0:255];

always @ (posedge mif.clk)
 if (mif.ce_mem && mif.we_mem) begin
   mem[mif.addr_mem] <= mif.datai_mem;
 end

//=================================================
// Read Logic
//=================================================
always @ (posedge mif.clk)
 if (mif.ce_mem && ~mif.we_mem)  begin
   mif.datao_mem <= mem[mif.addr_mem];
 end

endmodule


`timescale  1 ns/1 ps

module memory_ctrl
(
    mem_if.system sif
);

typedef enum
{
    IDLE,
    WRITE,
    READ,
    DONE,
}fsm_t;
fsm_t      state;
always @ (posedge sif.clk)
  if (sif.reset) begin
    state         <= IDLE;
    sif.ready_sys <= 0;
    sif.we_mem    <= 0;
    sif.ce_mem    <= 0;
    sif.addr_mem  <= 0;
    sif.datai_mem <= 0;
    sif.data_sys  <= 8'bz;
end else begin
    case(state)
        IDLE :  begin
            sif.ready_sys <= 1'b0;
            if (sif.cmd_valid_sys && sif.we_sys) begin
                sif.addr_mem   <= sif.addr_sys;
                sif.datai_mem  <= sif.data_sys;
                sif.we_mem     <= 1'b1;
                sif.ce_mem     <= 1'b1;
                state          <= WRITE;
            end
            if (sif.cmd_valid_sys && ~sif.we_sys) begin
                sif.addr_mem   <= sif.addr_sys;
                sif.datai_mem  <= sif.data_sys;
                sif.we_mem     <= 1'b0;
                sif.ce_mem     <= 1'b1;
                state          <= READ;
            end
        end
        WRITE : begin
            sif.ready_sys  <= 1'b1;
            if (~sif.cmd_valid_sys) begin
                sif.addr_mem   <= 8'b0;
                sif.datai_mem  <= 8'b0;
                sif.we_mem     <= 1'b0;
                sif.ce_mem     <= 1'b0;
                state          <= IDLE;
            end
        end 
        READ : begin
            sif.ready_sys  <= 1'b1;
            sif.data_sys   <= sif.datao_mem;
            if (~sif.cmd_valid_sys) begin
                sif.addr_mem   <= 8'b0;
                sif.datai_mem  <= 8'b0;
                sif.we_mem     <= 1'b0;
                sif.ce_mem     <= 1'b0;
                sif.ready_sys  <= 1'b1;
                state          <= IDLE;
                sif.data_sys   <= 8'bz;
            end 
        end 
    endcase
end

endmodule

program test
(
    mem_if.tb tif
)

initial 
begin
    tif.reset <= 1;
    tif.we_sys <= 0;
    tif.cmd_valid_sys <= 0;
    tif.addr_sys <= 0;
    tif.data_sys <= 8'bz;
    #100 tif.reset <= 0;
    for (int i = 0; i < 4; i ++) begin
        @ (posedge tif.clk);
        tif.addr_sys <= i;
        tif.data_sys <= $random;
        tif.cmd_valid_sys <= 1;
        tif.we_sys <= 1;
        @ (posedge tif.ready_sys);
        $display("@%0dns Writing address %0d with data %0x", 
            $time, i,tif.data_sys);
        @ (posedge tif.clk);
        tif.addr_sys <= 0;
        tif.data_sys <= 8'bz;
        tif.cmd_valid_sys <= 0;
        tif.we_sys <= 0;
    end
    repeat (10) @ (posedge tif.clk);
    for (int i= 0; i < 4; i ++) begin
        @ (posedge tif.clk);
        tif.addr_sys <= i;
        tif.cmd_valid_sys <= 1;
        tif.we_sys <= 0;
        @ (posedge tif.ready_sys);
        @ (posedge tif.clk);
        $display("@%0dns Reading address %0d, Got data %0x", 
            $time, i,tif.data_sys);
        tif.addr_sys <= 0;
        tif.cmd_valid_sys <= 0;
    end
    #10 $finish;
end
endprogram


module interface_modports();

logic                       clk = 0;
always #10 clk++;

mem_if miff (clk); 
memory_ctrl U_ctrl(miff);
memory_model U_model(miff);
test U_test(miff);
endmodule
```

# 接口参数, 参数类及虚接口
带参数的virtual interface在class中时, 需要将class也有参数, 将class的参数传递给interface
1. 接口声明
```verilog
interface axi_stream_bfm #
(
    parameter WIDTH = 8
)
(
    input                               s_aclk,
    input                               s_aresetn
);

    logic                               m_axis_tvalid;
    logic                               m_axis_tlast;
    logic                               m_axis_tready;  // slave控制此端口
    logic [WIDTH-1:00]                  m_axis_tdata;
endinterface
```

2. 接口例化
```verilog
axi_stream_bfm #
(
    .WIDTH  (8)
)
axi_stream_if 
(
    .s_aclk       (    clk      ),
    .s_aresetn    (    rst_n    )
);
```

3. 参数类声明及虚接口
```verilog
class axi_stream_drive #(int width = 16);
    virtual axi_stream_bfm #(.WIDTH (width) )    bfm;
    /*
     * 静态属性
     */
    function new(virtual axi_stream_bfm #(.WIDTH (width) ) b);  // 需要赋初值的属性
        bfm = b;
    endfunction
```

4. 参数类例化
```verilog
axi_stream_drive #(8) axi_stream_drive_h;
```