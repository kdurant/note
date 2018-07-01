```python
import csv
```

# 读文件

```python
csv_reader = csv.reader(open('data.file', encoding='utf-8'))
for row in csv_reader:
    print(row)
```

* csv文件中的每行数据转化成一个list
* csv文件中的每个数据是list中一个单独的字符串

