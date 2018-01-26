interface uart_bfm #
(
    parameter   int BAUDRATE = 230400
);
    logic                       rxd;   // 发送给待测模块
    logic                       txd;   // 从待测模块接受
    int                         baudrate;
    initial
    begin
        rxd = 1;
    end
endinterface: uart_bfm

`ifndef UART_SVH
`define UART_SVH

class uart_drive;
    virtual uart_bfm bfm;
    rand bit [07:00] data[];

    constraint c
    {
        data.size() == 5;
        foreach(data[i])
            data[i] inside {[1:255]};
    }

    function new(virtual uart_bfm b);
        bfm = b;
    endfunction

    //virtual function bit [07:00] calc_check(bit [07:00] data[]);
    //endfunction

    extern virtual task send_frame();

    /*-------------------------------------------------------------------------
    //description   :   按照指定波特率随机发送N个字节
    -------------------------------------------------------------------------*/
    extern task send_random_packet(int len);
    /*-------------------------------------------------------------------------
    //description   :   按照指定波特率发送一个字节
    -------------------------------------------------------------------------*/
    extern task send_byte(bit [07:00] data);
    /*-------------------------------------------------------------------------
    //description   :   打印出接收到的数据
    -------------------------------------------------------------------------*/
    extern task recv_byte();
endclass

task uart_drive::send_frame();
    assert(this.randomize());
    bfm.rxd = 1;
    #100ns
    for(int i = 0; i < $size(this.data); i = i + 1 )
    begin
        $display("uart write data is 0x%x", this.data[i]);
        send_byte(this.data[i]);
    end
endtask

task uart_drive::send_random_packet(int len);
    bit [07:00] data;
    for(int i = 0; i < len; i = i + 1 )
    begin
        data = $urandom_range(0, 255);
        $display("uart write data is 0x%x", data);
        send_byte(data);
    end
endtask

task uart_drive::send_byte(bit [07:00] data);
    // start bit
    bfm.rxd = 0; #(1s/bfm.BAUDRATE);
    // data
    bfm.rxd = data[0]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[1]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[2]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[3]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[4]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[5]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[6]; #(1s/bfm.BAUDRATE);
    bfm.rxd = data[7]; #(1s/bfm.BAUDRATE);
    // stop bit
    bfm.rxd = 1; #(1s/bfm.BAUDRATE);
endtask

task uart_drive::recv_byte();
    forever
    begin
        bit [07:00] data = 0;
        wait(~bfm.txd);
        #(1s/bfm.BAUDRATE/2);  // start bit
        #(1s/bfm.BAUDRATE);  data[0] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[1] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[2] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[3] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[4] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[5] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[6] = bfm.txd;
        #(1s/bfm.BAUDRATE);  data[7] = bfm.txd;
        #(1s/bfm.BAUDRATE);  // stop bit
        #(1s/bfm.BAUDRATE/2);  //本次数据时间全部结束

        $display("uart receive data 0x%x, baudrate is %d", data, bfm.BAUDRATE);
    end
endtask
`endif

/*
`include "./uart_bfm.sv"
uart_bfm #(.BAUDRATE(230400)) uart_bfm_i();
uart_drive  uart_drive_h;
initial
begin
    uart_drive_h = new(uart_bfm_i);
    assert(uart_drive_h.randomize());
    // user code
end
*/
