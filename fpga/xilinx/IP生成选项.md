# Global
每次工程综合的时候，IP核都会和工程一起综合，这样综合的时间就很长，而且Global选项不会产生.dcp文件，因为工程综合的时候是对IP核的源码进行综合的

例如fifo IP，目录结构如下
> doc
> hdl
> sim
> simulation
> synth
> ip_name.veo
> ip_name.vho
> ip_name.xci
> ip_name.xml

# Out of context(OOC) per IP
指让vivado在综合的时候对IP进行单独综合，生成.dcp文件，然后再工程要用到IP的时候，只需从.dcp文件中解析出对应IP的网表文件即可，而不需对IP进行重新综合，这样的方式可以加快综合的速度

例如fifo IP，使用`Out of context per IP`选项
> ip_name.dcp
> ip_name_ooc.xdc
> ip_name_sim_netlist.v
> ip_name_sim_netlist.vhdl
> ip_name_stub.v
> ip_name_vhdl

###
对于vivado来说，只需要保留`ip_name.xci`即可，其他文件都可以根据`ip_name.xci`重新生成