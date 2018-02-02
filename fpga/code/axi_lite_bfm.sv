interface axi_lite_bfm;
    logic                       s_axi_aclk;
    logic                       s_axi_aresetn;

    logic   [03:00]             s_axi_awaddr;
    logic                       s_axi_awvalid;
    logic                       s_axi_awready;

    logic   [31:00]             s_axi_wdata;
    logic   [03:00]             s_axi_wstrb;
    logic                       s_axi_wvalid;
    logic                       s_axi_wready;

    logic   [01:00]             s_axi_bresp;
    logic                       s_axi_bvalid;
    logic                       s_axi_bready;

    logic   [03:00]             s_axi_araddr;
    logic                       s_axi_arvalid;
    logic                       s_axi_arready;

    logic   [31:00]             s_axi_rdata;
    logic   [01:00]             s_axi_rresp;
    logic                       s_axi_rvalid;
    logic                       s_axi_rready;

    initial
    begin
        s_axi_awaddr = 0;
        s_axi_awvalid = 0;

        s_axi_wdata = 0;
        s_axi_wvalid = 0;

        s_axi_bready = 0;

        s_axi_aresetn = 1; #100ns;
        s_axi_aresetn = 0; # 1us;
        s_axi_aresetn = 1;
    end
    initial
    begin
        s_axi_aclk = 0;
        forever
        begin
            #(1s/100_000_000/2) s_axi_aclk = ~s_axi_aclk;
        end
    end
endinterface: axi_lite_bfm


`ifndef AXI_LITE_SVH
`define AXI_LITE_SVH

class axi_lite;
    virtual axi_lite_bfm bfm;
    //rand bit [31:00] data;

    //constraint c
    //{
        //data.size() == 5;
        //foreach(data[i])
            //data[i] inside {[0:65535]};
    //}

    function new(virtual axi_lite_bfm b);
        bfm = b;
    endfunction
    //extern task axi_lite_write(byte data);
    extern task write_byte(int addr, bit [31:00] data);
    extern task read_byte(int addr);
endclass

//task axi_lite::axi_lite_write(byte data);
    //assert(this.randomize());
    //for(int i = 0; i < $size(this.data); i = i + 1 )
//endtask

task axi_lite::write_byte(int addr, bit [31:00] data);
    //#2us;
    bfm.s_axi_wstrb = 4'b0000;
    bfm.s_axi_awaddr = addr;
    bfm.s_axi_awvalid = 1;
    bfm.s_axi_wdata = data;
    bfm.s_axi_wvalid = 1;
    wait(bfm.s_axi_awready & bfm.s_axi_wready);
    @ (posedge bfm.s_axi_aclk);

    bfm.s_axi_bready = 1;
    wait(bfm.s_axi_bvalid);
    @ (posedge bfm.s_axi_aclk);

    bfm.s_axi_awaddr = 0;
    bfm.s_axi_awvalid = 0;

    bfm.s_axi_wdata = 0;
    bfm.s_axi_wvalid = 0;

    bfm.s_axi_bready = 0;
endtask

task axi_lite::read_byte(int addr);
    bfm.s_axi_araddr = addr;
    bfm.s_axi_arvalid = 1;
    wait(bfm.s_axi_arready)
    @ (posedge bfm.s_axi_aclk);
    bfm.s_axi_arvalid = 0;

    bfm.s_axi_rready = 1;
    wait(bfm.s_axi_rvalid)
    @ (posedge bfm.s_axi_aclk);
    bfm.s_axi_rready = 0;
    //bfm.s_axi_araddr = addr;
    //bfm.s_axi_arvalid = 1;
    //bfm.s_axi_rready = 1;
    //wait(bfm.s_axi_arready & bfm.s_axi_rvalid)
    //@ (posedge bfm.s_axi_aclk);
    //bfm.s_axi_arvalid = 0;
    //bfm.s_axi_rready = 0;
endtask
`endif
