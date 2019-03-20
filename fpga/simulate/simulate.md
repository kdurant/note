# modelsim 文件路径
在文件中包含的文件路径，大部分以`*.mpf`文件为起点

# 信息的显示和输出

## $display()
每个时钟都显示出变量的值，且每次自动换行。
可以使用条件语句控制需要显示的值

## $write()
每个时钟都显示出变量的值，但不换行

## $strobe()
`$strobe`命令会在当前时间部结束时完成；而`$display`是只要仿真器看到就会立即执行。

## $monitor()
监视的任一信号变化时，就会输出信号的值，自动换行。
**$monitor需要写到initial语句块里**，上面的三个系统任务需要根据时钟的触发

# 从文件读取数据
```verilog 
    integer code;
    integer fd;
    bfm.adc_din = '0;
    fd = $fopen("landRadarSignal.txt", "r");
    while(!$feof(fd))
    begin
        wait(bfm.trg_in);
        for(int i = 0; i < 8000; i = i + 1 )
        begin
            @ (posedge bfm.data_clk);
            code = $fscanf(fd, "%d", bfm.adc_din); 
            //code = $fscanf(fd, "%d %d %d", d1, d2, d3); 
        end
        @ (posedge bfm.data_clk);
        bfm.adc_din = '0;
    end
    $fclose(fd);
    bfm.adc_din = '0;
```

# 将数据写入文件
```verilog
fd = $fopen("xxxx.txt");
$fwrite(fd,"%b\n", reg1); 
$fclose(fd);
```

## $fdisplay()
```verilog
integer fd;
initial
begin
    fd = $fopen("xxxx.txt", "w");
end

always @( posedge clk)
begin
    //$fdisplay(...)
end
```

# 使用systemverilog使用DPI调用C函数
1. 准备C函数
```c
int factorial(int i)
{
    if(i <= 1)
    {
        return i;
    }
    else 
        return i * factorial(i - 1);
}
```
2. 在systemverilog里导入
```verilog
import "DPI-C" function int factorial(input int i);

program automatic study ();
    initial
    begin
        for(int i = 0; i < 15; i = i + 1 )
        begin
            $display("%0d != %0d", i, factorial(i));
        end
    end

endprogram
```

3. 编译. 最关键的一步
```
vlog hello.c
vlog -sv -incr sv_st.sv
```

# Tips

Q: 如何不修改HDL代码的情况下，改变参数以便更好的仿真
A: 使用defparam
`defparam path.reg = value;`
