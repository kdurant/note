interface axi4_bfm;
    logic                       s_aclk;
    logic                       s_aresetn;

    logic   [03:00]             s_axi_awid;
    logic   [31:00]             s_axi_awaddr;
    logic   [07:00]             s_axi_awlen;
    logic   [02:00]             s_axi_awsize;
    logic   [01:00]             s_axi_awburst;
    logic                       s_axi_awvalid;
    logic                       s_axi_awready;

    logic   [31:00]             s_axi_wdata;
    logic   [03:00]             s_axi_wstrb;
    logic                       s_axi_wlast;
    logic                       s_axi_wvalid;
    logic                       s_axi_wready;

    logic   [03:00]             s_axi_bid;
    logic   [01:00]             s_axi_bresp;
    logic                       s_axi_bvalid;
    logic                       s_axi_bready;

    logic   [03:00]             s_axi_arid;
    logic   [31:00]             s_axi_araddr;
    logic   [07:00]             s_axi_arlen;
    logic   [02:00]             s_axi_arsize;
    logic   [01:00]             s_axi_arburst;
    logic                       s_axi_arvalid;
    logic                       s_axi_arready;

    logic   [03:00]             s_axi_rid;
    logic   [31:00]             s_axi_rdata;
    logic   [01:00]             s_axi_rresp;
    logic                       s_axi_rlast;
    logic                       s_axi_rvalid;
    logic                       s_axi_rready;

    initial
    begin
        s_aresetn = 1; #100ns;
        s_aresetn = 0; # 1us;
        s_aresetn = 1;
    end
    initial
    begin
        s_aclk = 0;
        forever
        begin
            #(1s/100_000_000/2) s_aclk = ~s_aclk;
        end
    end
endinterface: axi4_bfm

`ifndef AXI4_DRIVE_H
`define AXI4_DRIVE_H

class axi4_drive;
    virtual axi4_bfm bfm;
    //rand bit [31:00] data;

    //constraint c
    //{
        //data.size() == 5;
        //foreach(data[i])
            //data[i] inside {[0:65535]};
    //}

    function new(virtual axi4_bfm b);
        bfm = b;
    endfunction
    extern task init();
    /*-------------------------------------------------------------------------
    //description   :   配置写操作相关参数
    -------------------------------------------------------------------------*/
    extern task write_config();
    /*-------------------------------------------------------------------------
    //description   :   配置读操作相关参数
    -------------------------------------------------------------------------*/
    extern task read_config();
    /*-------------------------------------------------------------------------
    //description   :   指定位置写入一个单位数据
    -------------------------------------------------------------------------*/
    extern task write_byte(int addr, bit [31:00] data);
    /*-------------------------------------------------------------------------
    //description   :   指定位置写入len长度单位数据
    -------------------------------------------------------------------------*/
    extern task write_burst(int addr, int len);
    extern task read_byte(int addr);
    extern task read_burst(int addr, int len);
endclass

task axi4_drive::init();
    bfm.s_axi_awid = 0;
    bfm.s_axi_awaddr = 0;
    bfm.s_axi_awvalid = 0;
    bfm.s_axi_wdata = 0;
    bfm.s_axi_wstrb = 0;
    bfm.s_axi_wlast = 0;
    bfm.s_axi_wvalid = 0;
    bfm.s_axi_bready = 1;
    bfm.s_axi_arid = 0;
    bfm.s_axi_araddr = 0;
    bfm.s_axi_arlen = 0;
    bfm.s_axi_arsize = 0;
    bfm.s_axi_arburst = 0;
    bfm.s_axi_arvalid = 0;
    bfm.s_axi_rready = 0;
endtask

task axi4_drive::write_config();
    bfm.s_axi_awlen = 0;
    bfm.s_axi_awsize = 3'b010;
    bfm.s_axi_awburst = 2'b01;
endtask

task axi4_drive::read_config();
    bfm.s_axi_arlen = 0;
    bfm.s_axi_arsize = 3'b010;
    bfm.s_axi_arburst = 2'b01;
endtask

task axi4_drive::write_byte(int addr, bit [31:00] data);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_awid = 0;
    bfm.s_axi_wstrb = 4'b1111;

    bfm.s_axi_awvalid = 1;
    bfm.s_axi_awaddr = addr;
    bfm.s_axi_wdata = data;
    bfm.s_axi_wvalid = 1;
    bfm.s_axi_wlast = 0;

    wait (bfm.s_axi_awready & bfm.s_axi_wready);
    if(bfm.s_axi_awlen == 0)
    begin
        bfm.s_axi_wlast = 1;
        @ (posedge bfm.s_aclk);
        bfm.s_axi_awvalid = 0;
        bfm.s_axi_awaddr = 0;
        bfm.s_axi_wdata = 0;
        bfm.s_axi_wvalid = 0;
        bfm.s_axi_wlast = 0;
    end
    wait (bfm.s_axi_bready & bfm.s_axi_bvalid);

endtask

task axi4_drive::write_burst(int addr, int len);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_awid = 0;
    bfm.s_axi_wstrb = 4'b1111;

    bfm.s_axi_awlen = len - 1;
    bfm.s_axi_awvalid = 1;
    bfm.s_axi_awaddr = addr;
    //bfm.s_axi_wdata = data;
    //bfm.s_axi_wvalid = 1;
    bfm.s_axi_wlast = 0;

    fork
        begin
            wait(bfm.s_axi_awready)
            @ (posedge bfm.s_aclk);
            bfm.s_axi_awvalid = 0;
            bfm.s_axi_awaddr = 0;
        end
    join/*_any or _none*/
    begin
        bfm.s_axi_wvalid = 1;
        wait(bfm.s_axi_wready)
        for(int i = 0; i < len; i = i + 1 )
        begin
            bfm.s_axi_wdata = $urandom_range(0, 65535);
            if(i == len-1)
                bfm.s_axi_wlast = 1;
            @ (posedge bfm.s_aclk);
        end
        bfm.s_axi_wdata = 0;
        bfm.s_axi_wvalid = 0;
        bfm.s_axi_wlast = 0;
    end
endtask

task axi4_drive::read_byte(int addr);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_arid = 0;
    bfm.s_axi_araddr = addr;
    bfm.s_axi_arlen = 0;
    bfm.s_axi_arvalid = 1;
    wait (bfm.s_axi_arready);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_arvalid = 0;

    bfm.s_axi_rid = 1;
    bfm.s_axi_rready = 1;
    wait (bfm.s_axi_rvalid);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_rready = 0;
endtask

task axi4_drive::read_burst(int addr, int len);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_arid = 0;
    bfm.s_axi_araddr = addr;
    bfm.s_axi_arlen = len-1;
    bfm.s_axi_arvalid = 1;

    wait (bfm.s_axi_arready);
    @ (posedge bfm.s_aclk);
    bfm.s_axi_arvalid = 0;
    bfm.s_axi_araddr = 0;

    bfm.s_axi_rready = 1;
    wait (bfm.s_axi_rready);
    repeat(len)
    begin
        @ (posedge bfm.s_aclk);
    end
    bfm.s_axi_rready = 0;
endtask

`endif

