![list](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1547288195361&di=0bbe813fc771d930f710d9038b617cfe&imgtype=0&src=http%3A%2F%2Fs1.knowsky.com%2F20150728%2F131304006207720.png)

# 术语
1. 结点(Node)
   
   包括数据域和指针域

2. 头结点
   - 为了操作的统一和方便而设立，放在第一个元素(首结点)之前
   - 数据域一般不存储任何信息(也可以用来存放聊表的长度)
   - 不是链表的必须要素

3. 头指针
   - 无论链表是否为空，`头指针均不为空`
   - 指向链表第一个结点的指针，若链表有头结点，则是指向头结点的指针
   - 头指针具有标识作用，所以常用头指针冠以链表的名字