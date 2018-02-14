非连续存储结构，具有双链表结构，每个元素维护一对前向和后向指针，因此支持前向/后向遍历。支持高效的随机插入/删除操作，但随机访问效率低下，且由于需要额外维护指针，开销也比较大。每一个结点都包括一个信息快Info、一个前驱指针Pre、一个后驱指针Post。可以不分配必须的内存大小方便的进行添加和删除操作。使用的是非连续的内存空间进行存储。
优点：
1. 不使用连续内存完成动态操作。
2. 在内部方便的进行插入和删除操作
3. 可在两端进行push、pop

缺点：
1. 不能进行内部的随机访问，即不支持[ ]操作符和vector.at()
2. 相对于verctor占用内存多

使用区别：
1. 如果你需要高效的随即存取，而不在乎插入和删除的效率，使用vector
2. 如果你需要大量的插入和删除，而不关心随机存取，则应使用list
3. 如果你需要随机存取，而且关心两端数据的插入和删除，则应使用deque

[list 使用](https://www.cnblogs.com/lalalabi/p/5060210.html)
# 构造方法
```cpp
list<int> c0;   // 空链表
list<int> c1(3);    // 建一个含三个默认值是0的元素的链表
list<int> c2(5, 2); // 建一个含五个元素的链表，值都是2
list<int> c3(c2);   // 建一个c2的copy链表
list<int> c4(c1.begin(), c1.end())  // c4含c1一个区域的元素[_First, _Last)

# 添加元素
```cpp
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void)
{

    list<int> c0;
    c0.push_back(3);    // 链表末尾添加元素
    c0.push_front(4);   // 链表前端添加元素
    c0.assign(3, 10);   // 清空链表，并添加3个值为10的元素

    for (list<int>::iterator iter = c0.begin(); iter != c0.end(); iter++)
        cout << *iter << endl;
    return 0;
}
```