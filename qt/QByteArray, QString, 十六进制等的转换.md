
QByteArray, 主要用来存放原始字节数组；QString, 存放占用2个字节空间的QChar

```cpp
QByteArray ba("ab12");
// ba在内存中存放的是"ab12"对应的Ascii码，0x61, 0x62, 0x31, 0x32
QString s("ab12");
// s在内存中存放的是: 0x0061, 0x0062, 0x0031, 0x0032
```

# 普通十进制数字转换为QByteArray
```cpp
QByteArray c = QByteArray::number(31);
// c在内存中的数据是：0x33, 0x31
QByteArray d = QByteArray::number(31, 16);
// d在内存中的数据是：0x31, 0x66
```

# 普通字符串按照16进制转换为QByteArray
```cpp
QByteArray ba = QByteArray::fromHex("1234abc");
// "1234abd"的长度为奇数，会在前面补0，然后每2个字符分割，按照16进制存放到内存中
// ba在内存中的数据是： 0x01, 0x23, 0x4a, 0xbc
QByteArray ba1 = QByteArray::fromHex("1234abcd");
// ba在内存中的数据是： 0x12, 0x34, 0xab, 0xcd

QByteArray ba2 = QByteArray::fromHex("12aqqb");
// qq不是16进制字符，会被直接丢弃
// ba在内存中的数据是： 0x12, 0xab
```

# QByteArray转换成普通数字
```cpp
```

# QByteArray <=> QString
## QByteArray -> QString

* 方法1
```cpp
QByteArray ba("Hello");
QString s = ba;
```

* 方法2
```cpp
QByteArray ba("1234abcd");
QString s;  // 注意s要为空
s.prepend(ba);
```

* 方法3
```cpp
```

## QString -> QByteArray
* 方法1
```cpp
QString s("hello");
QByteArray ba = str.toUtf8();
```

* 方法2
```cpp
QString s("1234abcd");
QByteArray ba = QByteArray::fromStdString(ba.toStdString());
```

# toInt()
QByteArray和QString均有此函数，功能相同


```cpp
QByteArray ba("1234");
QString s("1234");
bool ok;
qDebug() << ba.toInt(&ok);
qDebug() << s.toInt(&ok);
qDebug() << ba.toInt(&ok, 16);
qDebug() << s.toInt(&ok, 16);
```

# toHex()
QByteArray有此函数，QString无此函数
> 将内存中的原始数据的Ascii码
```cpp
QByteArray ba("1234");
QByteArray bd = ba.toHex();
// bd在内存中的数据为: 0x33, 0x31, 0x33, 0x32, 0x33, 0x33, 0x33, 0x34
```

# fromStdString()
QByteArray和QString均有此函数
> StdString是指std::string
```cpp
QString s = QString::fromStdString("1234ab");
QByteArray ba = QByteArray::fromStdString("1234ab");
```
