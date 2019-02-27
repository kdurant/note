1. 可以在包、模块、程序、接口或类中定义`coverage`
2. `coverage`中包含以下内容
    * clocking event
    * coverage points

# 如何报告
1. 在mpdf文件中设置`SVCovergroupPerInstanceDefault = 1`
2. `coverage save -assert -directive -cvg -codeAll file_name.ucdb`
3. `vcover report -details -html file_name.ucdb`