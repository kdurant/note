# vsim
 - nowarn, 关键编译时的一些警告信息
    +nowarnTFMPC   +nowarn3017

# vopt
1. 通过使用无参数的+acc选项，优化mydesin并保持设计中所有对象可见
`vopt +acc mydesign -o mydesign_opt`

2. mydesign中名为mod1的模块所有对象可见
`vopt top +acc+mod1 mydesign -o mydesign_op`

# 仿真优化流程

## 三步走
1. vlog文件
2. vopt
