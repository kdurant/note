# 软件环境
* vivado2017.4
* modelsim10.5
[ug973](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2017_1/ug973-vivado-release-notes-install-license.pdf)
> vivado2016.1 modelsim10.4d
> vivado2016.2 modelsim10.4d
> vivado2016.3 modelsim10.5c
> vivado2016.4 modelsim10.5c
> vivado2017.1 modelsim10.5c
> vivado2017.2 modelsim10.5c
> vivado2017.3 modelsim10.6b
> vivado2017.4 modelsim10.6b

# 准备工作
1. [使用vivado编译好modelsim仿真需要的库文件](http://blog.163.com/hardware_engineer/blog/static/25836606620168141519404?ignoreua)
2. 复制一份glbl.v到仿真库文件所在文件夹

# IP仿真文件
1. 打开`project.ip_user_files/sim_scripts/ip_name/modelsim/compile.do`
2. 在`vlog -work xil_defaultlib "glbl.v"`上方可以找到本IP仿真时使用的文件

# 仿真工程
在`project.sim`下建立`modelsim`文件夹

在`project.sim/modelsim/`目录下建立modelsim工程，不需要添加任何文件

# 脚本文件
在`project.sim/modelsim/`目录下建立`demo.tcl`文件

脚本文件框架如下
```tcl
# demo.tcl
quit -sim
set env(VIVADO_SIM)     F:/crack/vivado2017.4_lib      #仿真库文件所在目录
vmap secureip           $env(VIVADO_SIM)/secureip
vmap simprims_ver       $env(VIVADO_SIM)/simprims_ver
vmap unifast            $env(VIVADO_SIM)/unifast
vmap unifast_ver        $env(VIVADO_SIM)/unifast_ver
vmap unimacro           $env(VIVADO_SIM)/unimacro
vmap unimacro_ver       $env(VIVADO_SIM)/unimacro_ver
vmap unisim             $env(VIVADO_SIM)/unisim
vmap unisims_ver        $env(VIVADO_SIM)/unisims_ver

vlog -incr $env(VIVADO_SIM)/glbl.v
vlog -sv -incr ../../led.srcs/sim_1/new/top_tb.sv

# 有的IP没有`sim`目录
# 有的IP需要的不止一个文件
vlog -incr ../../led.srcs/sources_1/ip/fifo/sim/fifo.v 
# 其他工程所需文件

vsim -t ps -novopt +notimingchecks \
                                    -L secureip \
                                    -L simprims_ver \
                                    -L unifast -L unifast_ver \
                                    -L unimacro -L unimacro_ver \
                                    -L unisim -L unisims_ver \
                                    -L other_need_lib \
                                    glbl \
                                    work.top_tb

log -r /*
radix 16

run 10us
```

# modelsim工程
1. 输入`do demo.tcl`，脚本文件里包含了常用的库文件，但仿真IP时也可能会提示某些模块没法例化
2. 根据提示，在vsim后 添加`-L other_need_lib`，直到不提示确实仿真库为止