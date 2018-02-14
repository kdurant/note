vector是一个封装了动态数组的顺序容器，能够增加压缩数据
[C++三种容器：list、vector和deque的区别](http://blog.csdn.net/gogokongyin/article/details/51178378)
# 声明
```cpp
#include <vector>
vector<int> v;       //创建一个vector, int为数组元素的数据了下，v为动态数组名
vector<int> v2(v);   // v2是v的一个副本，拷贝构造函数
vector<int> v3(n, data);   // v3包含n个值为data的元素
vector<int> v4(n);  // v4含10个有值初始化为0的元素
vector<int> v5{1, 2, 3, 4}  // 构造大小为4，并初始化里面的各个元素
```

# vector元素个数
```cpp
v.size();
```

# 访问元素
## 下标
下标从0开始
```cpp
cout << v[0] << endl;
```
## 迭代器
```cpp
vector<int>::iterator it;
for(it = v.begin(); it != v.end(); it++)
    cout << *it << endl;
```
# 从尾部插入元素
```cpp
v.push_back(data);
```

# 从指定位置插入元素
在第i+1个元素前面插入data
```cpp
v.insert(v.begin()+i, data);
```
# 删除末尾数据
```cpp
v.pop_back();
```

# 从指定位置删除元素
```cpp
v.earse(v.begin()+i)
```

# 清空
```cpp
v.celar();
```

# vector状态
```cpp
v.empty() == true;
```

# 对元素排序
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> intVector(100);
int main(void)
{

    vector<int> v{5, 2, 3, 4};

    sort(v.begin(), v.end());
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}
```

# 反转容器
```cpp
reverse(v.begin(), v.end());
```

# 交换元素
```cpp
swap(v[m], v[n]);
```

# 注意
1. 如果表示的向量长度较长（需要为向量内部保存很多数），容易导致内存泄漏，而且效率会很低
2. vector作为函数的参数或者返回值时，需要注意它的写法
```cpp
double Distance(vector<int> &a, vector<int> &b);
3. 当vector元素是结构体时，结构体要定义为全局的，否则会出错
```



assign  清除矢量并将指定的元素复制到该空矢量。
at 	返回对矢量中指定位置的元素的引用。
back 	返回对向量中最后一个元素的引用。
begin 	对该向量中第一个元素返回随机访问迭代器。
capacity 	返回在不分配更多的存储的情况下向量可以包含的元素数。
cbegin 	返回指向向量中第一个元素的随机访问常量迭代器。
cend 	返回一个随机访问常量迭代器，它指向刚超过矢量末尾的位置。
crbegin 	返回一个指向反向矢量中第一个元素的常量迭代器。
crend 	返回一个指向反向矢量末尾的常量迭代器。
clear 	清除向量的元素。
data 	返回指向向量中第一个元素的指针。
emplace 	将就地构造的元素插入到指定位置的向量中。
emplace_back 	将一个就地构造的元素添加到向量末尾。
empty 	测试矢量容器是否为空。
end 	返回指向矢量末尾的随机访问迭代器。
erase 	从指定位置删除向量中的一个元素或一系列元素。
front 	返回对向量中第一个元素的引用。
get_allocator 	将对象返回到矢量使用的 allocator 类。
insert 	将一个元素或多个元素插入到指定位置的向量中。
max_size 	返回向量的最大长度。
pop_back 	删除矢量末尾处的元素。
push_back 	在矢量末尾处添加一个元素。
rbegin 	返回指向反向向量中第一个元素的迭代器。
rend 	返回一个指向反向矢量末尾的迭代器。
reserve 	保留向量对象的最小存储长度。
resize 	为矢量指定新的大小。
shrink_to_fit 	放弃额外容量。
size 	返回vector元素个数
swap 	交换两个向量的元素。 