1. 为了将测试和设计分开, 引入了`program`

2. `program`中不能包含`always`
3. `module`中不可以调用`program`内的函数和任务, 但`program`可以调用`module`中的函数和任务
```verilog
`timescale  1 ns/1 ps

`include "uvm_macros.svh"

import uvm_pkg::*;

program test_program (); 
    initial
    begin
        #1us test.clk = 0;
        forever
            #10  test.clk = ~test.clk;         //only use initial block
    end
endprogram

module test (); 

logic                       clk;

test_program  tEx01();

endmodule
```
4. 
