msgpack和json一样是是存储和交换文本信息的语

> 所谓序列化就是将特定对象转化为一串字节序列,用以存储,作为配置文件或者传输.它的反向操作被称为反序列化.

# 序列化为bytes

```python
pack = msgpack.packb([1, 2, 3])
>>> print(pack)
b'\x93\x01\x02\x03'

>>> msgpack.unpackb(pack)
[1, 2, 3]

msgpack.unpackb(pack, use_list=False)# 指定use_list为False则会返回tuple
(1, 2, 3)
```

## 反序列化为字符串
```python
pack = msgpack.packb(["你", "我", "他"])
>>> pack
b'\x93\xa3\xe4\xbd\xa0\xa3\xe6\x88\x91\xa3\xe4\xbb\x96'
>>> msgpack.unpackb(pack,encoding='utf-8')
['你', '我', '他']
```