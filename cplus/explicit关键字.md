explicit关键字用来修饰类的构造函数，表明构造函数是显示的，相对的是implicit关键字。
首先这个关键字只能用在类内部的构造函数声明上，而不能用在类外部的函数定义上，它的作用是不能进行隐式转换。
类构造函数默认情况下即声明为implicit(隐式).

> 隐式转换 : 类的构造函数只有单个需要初始化的参数（不包括有默认值的参数)时才可能是隐式转换

```cpp
#include <iostream>

using namespace std;
class Student
{
public:
    int m_size;
    //explicit Student(int size)
    Student(int size)
    {
        m_size = size;
    }
};

int main(void)
{
    Student t1(10); // 显示转换
    Student t2 = 20;    // 隐式转换， 如果构造函数使用explicit修饰，则不能这样
    Student *t3 = new Student(30);

    cout << t1.m_size << endl;
    return 0;
}
```