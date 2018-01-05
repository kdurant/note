# 目录结构

## project.ip_user_files
生成IP时，可以重新生成此目录下的所有文件

## project.srcs/sources_1/ip/ip_name(fifo)

# 仿真
根据vivado文件目录的特点，决定将modelsim工程放在`project.sim/modelsim`目录下

1. 建立`demo.tcl`文件，保存仿真脚本

2. 添加编译需要的文件
`project.ip_user_files/sim_scripts/ip_name/modelsim/compile.do`文件里包含仿真所需要的文件，我们只需要将此文件里的相对路径修改下。将此文件里的内容复制到`demo.tcl`文件里。
