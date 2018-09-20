# 参考文档
* ug835 ug835-vivado-tcl-commands
* ug888 vivado-design-flows-overview-tutorial.
* ug892 vivado-design-flows-overview
* ug939 vivado-designing-with-ip-tutorial

# Non-project模式流程
将下面所有步骤的内容放到一个文件
## step0 设置输出文件目录，使用器件等信息
```tcl
set top_module_name top
set outputDir ./synth_tmp
file mkdir $outputDir
set_part xc7z020clg400-1
```
## step1 读取工程使用到的源文件
```tcl
read_verilog [ glob ./src/*.v ]
read_xdc ./pin.xdc
# read_vhdl
# read_edif
# read_ip(.xci or .xco)
# read_bd
```

## step2 synthesis 且将相关报告写入文件
```tcl
synth_design -top $top_module_name    
write_checkpoint -force $outputDir/post_synth
report_timing_summary -file $outputDir/post_synth_timing_summary.rpt
report_power -file $outputDir/post_synth_power.rpt
report_clock_interaction -delay_type min_max -file $outputDir/post_synth_clock_interaction.rpt
report_high_fanout_nets -fanout_greater_than 200 -max_nets 50 -file $outputDir/post_synth_high_fanout_nets.rpt
```
## step3 placement和逻辑优化
```tcl
opt_design
place_design
phys_opt_design
write_checkpoint -force $outputDir/post_place
report_timing_summary -file $outputDir/post_place_timing_summary.rpt
```
## step4 布线
```tcl
route_design
write_checkpoint -force $outputDir/post_route
report_timing_summary -file $outputDir/post_route_timing_summary.rpt
report_timing -max_paths 100 -path_type summary -slack_lesser_than 0 -file $outputDir/post_route_setup_timing_violations.rpt
report_clock_utilization -file $outputDir/clock_util.rpt
report_utilization -file $outputDir/post_route_util.rpt
report_power -file $outputDir/post_route_power.rpt
report_drc -file $outputDir/post_imp_drc.rpt
write_verilog -force $outputDir/bft_impl_netlist.v
write_xdc -no_fixed_only -force $outputDir/bft_impl.xdc
```
## step5 生成bit文件
```tcl
write_bitstream -force $outputDir/$top_module_name.bit
```

# FAQ
Q：如何打开tcl窗口?

Q: 如何运行tcl文件？
打开tcl窗口后，cd到工作目录，运行`source flow.tcl`

`launch_sdk -workspace D:/tmp/dma_loop/dma_loop.sdk -hwspec D:/tmp/dma_loop/dma_loop.sdk/cpu_wrapper.hdf`