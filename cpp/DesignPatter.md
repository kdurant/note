# 继承规则
![](https://pics0.baidu.com/feed/bd3eb13533fa828bff67f961a072e830960a5a59.jpeg?token=d3d8e16f4e4565e25a8db3c5dc92b146&s=0E2476227F2965092A65B06B0200D07B)

#  模板模式
在软件构建过程中，对于某一项任务，他常常有稳定的整体操作结构，但各个子步骤却有很多改变的需求，或者由于固有的原因（比如框架与应用之间的关系）而无法和任务的整体结构同时实现。如何在确定稳定操作结构的前提下，来灵活应对各个子步骤的变化？

- 结构化软件设计流程：
![](https://pic1.zhimg.com/80/v2-aea586194de9564775657dc1bbd753f4_hd.png)

- 面向对象软件设计流程：
![](https://pic3.zhimg.com/80/v2-7b4291598dd44f3ae53319a34d09f0fe_hd.png)

```cpp
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class AbstractClass
{
private:
public:
    void TemplateMethod()
    {
        PrimitiveOperation1();
        cout << "Fixed step." << endl;
        PrimitiveOperation2();
    }

protected:
    virtual void PrimitiveOperation1()
    {
        cout << "Default Operation1" << endl;
    }
    virtual void PrimitiveOperation2()
    {
        cout << "Default Operation2" << endl;
    }
};

class ConcreteClassA : public AbstractClass
{
protected:
    virtual void PrimitiveOperation1()
    {
        cout << "ConcreteA Operation1" << endl;
    }
    virtual void PrimitiveOperation2()
    {
        cout << "ConcreteA Operation2" << endl;
    }
};

class ConcreteClassB : public AbstractClass
{
protected:
    virtual void PrimitiveOperation1()
    {
        cout << "ConcreteB Operation1" << endl;
    }
    virtual void PrimitiveOperation2()
    {
        cout << "ConcreteB Operation2" << endl;
    }
};

int main(void)
{
    AbstractClass* pAbstractA = new ConcreteClassA;
    pAbstractA->TemplateMethod();

    AbstractClass* pAbstractB = new ConcreteClassB;
    pAbstractB->TemplateMethod();

    if(pAbstractA)
        delete pAbstractA;
    if(pAbstractB)
        delete pAbstractB;
    return 0;
}
```