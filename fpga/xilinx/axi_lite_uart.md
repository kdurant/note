# 读
1. `CTRL_REG`写入0x00000010，使能中断
2. 等待`interrupt`信号有效
3. `s_axi_arvalid`和`s_axi_rready`置1，`s_axi_araddr`为1（2,3）时可以读出接收到的数据
4. `s_axi_rvalid`和`s_axi_rready`同时有效时输出数据
> interrupt无效，读数据时，`s_axi_rdata == 8'hxx; s_axi_rresp = 2`
> `s_axi_rdata`的低8位为接收到的有效数据

# 写
1. `CTRL_REG`写入0x00000001, 复位`Tx FIFO`
2. `Tx FIFO`写入数据
3. 写地址和写数据需要同时给出信号
> `s_axi_wstrb`无效，不论是全0还是全1，皆是`s_axi_wdata`的低8位写到`tx`引脚上