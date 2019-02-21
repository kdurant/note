1. clocking只能在module/interface/checker/program中声明，不能在function/task/package中。

2. clocking块是声明和例化一体的(类似always块没有例化语句)

3. clocking块是对所在的module/interface/checker/program里的信号的采样或驱动的timing属性进行声明，也可以通过hierarchy引用的方式作用于其他模块的信号。

4.  同一个module/interface/checker/program中声明多个clocking块，同一个信号也可以出现在不同的clocking块中。

# 作用
