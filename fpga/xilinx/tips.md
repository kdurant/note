# axi-strem FIFO
1. 多次带s_axi_tlast的写操作后读取数据时，m_axi_tlast也会出现多次
2. m_axis_tvalid有效时，最先写入的数据已经出现在总线上
3. m_axis_tready有效的下一个周期，读取的数据才会出现在总线上
4. 单次读取数据时，