使用基类的的引用或者指针调用虚成员函数时，会发生动态绑定

```cpp
#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;
class A
{
public:
    void func()
    {
        cout << "A::func()" << endl;
    }
    virtual void vfunc()
    {
        cout << "virtual A::func()" << endl;
    }
};

class B : public A
{
public:
    void func()
    {
        cout << "B::func()" << endl;
    }

    virtual void vfunc()
    {
        cout << "virtual B::func()" << endl;
    }
};

class C : public A
{
public:
    void func()
    {
        cout << "C::func()" << endl;
    }

    virtual void vfunc()
    {
        cout << "virtual C::func()" << endl;
    }
};

int main(void)
{
    // pc的静态类型是C*, 动态类型也是C*
    C *pc = new C();
    // pc的静态类型是B*, 动态类型也是B*
    B *pb = new B();
    // pa的静态类型是A*, 动态类型是C*
    A *pa = pc;

    pa->func();
    pb->func();
    pc->func();

    pa->vfunc();
    pb->vfunc();
    pc->vfunc();

    return 0;
}
```