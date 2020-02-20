在公有派生的情况下
- 派生类的指针可以直接赋值给基类指针，但不能通过基类指针访问基类没有而派生类中有的成员
- 不能将基类指针直接赋值给派生类指针（语法上就不允许）
- 通过强制类型转换将基类指针先转换为派生类指针再赋值的话，这种用法很危险，也不符合生活习惯，在程序设计上会给程序员带来困扰
-  如果基础类和衍生类定义了相同名称的成员函数，那么通过对象指针调用成员函数时，到底调用那个函数要根据指针的原型来确定，而不是根据指针实际指向的对象类型确定。

```cpp
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class CBase
{
protected:
    int n;

public:
    CBase(int i)
        : n(i)
    {
    }
    void Print()
    {
        cout << "CBase:n = " << n << endl;
    }
};

class CDerived : public CBase
{
public:
    int v;
    CDerived(int i)
        : CBase(i), v(2 * i)
    {
    }
    void Func(){};
    void Print()
    {
        cout << "CDerived:n = " << n << endl;
        cout << "CDerived:v = " << v << endl;
    }
};

int main(void)
{
    CDerived objDerived(3);
    CBase    objBase(5);

    CBase *pBase = &objDerived;  // 基类指针指向派生类对象
    pBase->Print();
    cout << "1)------------" << endl;
    //CDerived * pDerived = & objBase; //错，不能将基类指针赋值给派生类指针
    CDerived *pDerived = (CDerived *)(&objBase);
    pDerived->Print();  //慎用，可能出现不可预期的错误
    cout << "2)------------" << endl;
    objDerived.Print();
    cout << "3)------------" << endl;
    pDerived->v = 128;  //往别人的空间里写入数据，会有问题
    objDerived.Print();
    return 0;
}
```