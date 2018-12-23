```python
ss1 = pd.Series([1, 2, 'a3', 4.0, True, '2018-12-21'])
```
# 更改元素数据类型
TODO

# 遍历行列
```python
for col in df.columns:
    print(df[col])

for row in df.index:
    print(df.loc[row])
```

# 删除行或列
```python
df = pd.DataFrame(np.arange(24).reshape(6,4), columns=['A', 'B', 'C', 'D'])
```
1. 删除行时，指定index
`df.drop([1], axis=0, inplace=True)`

2. 删除行时，指定行序号
`df.drop([1])`

3. 删除列时，指定columns
`df.drop(['B','D'], axis=1, inplace=True)`

4. 删除列时，指定列序号
`df.drop(df.columns[1], axis=1)`

# 过滤数据
1. 根据单列值选择DataFrame数据
```python
df[df.A > 10]
`df[df.A != 'X']    # A列中是'X'的行不会被选择
```

2. 根据类型选择Series数据
```python
s = pd.Series(['foo', 'bar', 42, True, 3.33])

# 过滤掉s中是字符串的元素
s[s.apply(type) != str]
s[s.str.isnumeric().isnull()]
s[pd.to_numeric(s, errors='coerce').notnull()]

```