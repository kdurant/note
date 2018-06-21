# 缩写
**I** 输入
**BUF** 缓冲
**G** 全局
**CE** 使能
**DS** 差分信号

IBUFG

IBUFGDS

BUFG

BUFGCE

BUFGMUX

BUFGP

BUFGDLL

DCM

物理约束从布局开始
您可能出于多种原因想对布局进行约束，例如帮助达到时序要求，或者在设计的不同区域间实现隔离。就此而言，有三种类型的约束很重要：
• BEL –将网表单元放在 slice 中的基本的逻辑元素。
• LOC –将网表的单元放在器件内的一个位置。
• PBlock – 可使用物理(或“P”)block 将逻辑 block 约束到 FPGA 的一个区域。

因此，LOC 允许在器件内定义一个 slice 或其它位置；BEL 约束可用来定义触发器在 slice 中使用的更精细粒度。当对设计的大面积区域进行分段时，PBlock 可用来将逻辑集合在一起。PBlock 的另一个用途是在执行部分重配置时定义逻辑区域。