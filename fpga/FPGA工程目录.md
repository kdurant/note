# 项目工程目录结构

- doc  
- hdl
    * func1  功能1相关文件目录
    * func2  功能1相关文件目录
    * xxxx
- bench  测试相关代码(使用vivado时，tb放到指定的目录下？)
- modelsim 仿真工程相关文件
    * func1 功能1测试工程
    * func2 功能2测试工程
- ip        使用到的IP核相关文件
    - ip1
    - ip2 
- fpga 存放FPGA工程相关文件
    * others
- README.md  记录设计参数，系统结构，注意事项等等
- DEBUG.md 记录调试过程中的一些问题


# 自用模块工程目录结构

- doc  
- hdl
- ip        使用到的IP核相关文件
    - ip1
    - ip2 
- bench  测试相关代码
- modelsim 仿真工程相关文件

如果实际工程中使用到已经写好的模块，使用`git submodule`引入

# 工程参数
工程必须包含`bsp_parameter.vh`设置一些工程参数，例如：
* 条件编译参数
* 协议命令参数
* 功能设置参数
* 等等

# git子模块
核心功能，尽量放到一个git项目里去，单独仿真，以便服用
