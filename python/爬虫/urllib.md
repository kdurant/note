# 爬取网页内容
```python
file = urllib.request.urlopen("http://www.baidu.com")
```

# 读取网页内容
```python
data = file.read()
```

# 将内容保存到文件
```python
html = open('baidu.html', 'wb')
html.write(data)
html.close()
```