以下操作在完成对axi4-lite总线初始配置的情况下
# 从axi4_lite_uart中读出uart接受到的数据
1. `CTRL_REG(0CH)`写入0x00000010，使能中断
2. 等待`interrupt`信号有效后去读取数据
> 如果`interrupt`有效时，数据没有被及时读出，下一个叔叔到达时interrupt不会再次有效
3. 从`Rx FIFO(00H)`地址处读取收到的数据
> 00, 01, 02, 03地址都可以读到正确的数据

4. `s_axi_rvalid`和`s_axi_rready`同时有效时输出数据
> interrupt无效，读数据时，`s_axi_rdata == 8'hxx; s_axi_rresp = 2`
> `s_axi_rdata`的低8位为接收到的有效数据

# uart发送数据
1. `CTRL_REG`写入0x00000001, 复位`Tx FIFO`
2. `Tx FIFO(04H)`写入数据
3. 写地址和写数据需要同时给出信号
> `s_axi_wstrb`无效，不论是全0还是全1，皆是`s_axi_wdata`的低8位写到`tx`引脚上

[axi4_uartlite仿真](https://coding.net/u/kdurant/p/axi4_lite_uart/git?public=true)