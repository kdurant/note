[xlrd](https://www.cnblogs.com/insane-Mr-Li/p/9092619.html)
```python
import xlrd
file = 'NIOS.xlsx'
wb = xlrd.open_workbook(filename=file)

# Excel里的sheet列表
wb.sheets()  

# 选择某个具体sheet有三种方式
table = wb.sheets()[0]
table = data.sheet_by_index(0)) 
table = data.sheet_by_name(sheet_name)

# 表格有多少行内容
table.nrows

#返回由该行中所有的单元格对象组成的列表
table.row(row_num)
```