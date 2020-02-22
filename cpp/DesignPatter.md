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


# [观察者模式](https://www.cnblogs.com/carsonzhu/p/5770253.html)
定义了一种一对多的依赖关系，让多个观察者对象同时监听某一主题对象，在主题对象的状态发生变化时,会通知所有的观察者。

观察者角色如下：
-  抽象主题（Subject）角色：抽象主题角色提供维护一个观察者对象集合的操作方法，对集合的增加、删除等。
-  具体主题（ConcreteSubject）角色：将有关状态存入具体的观察者对象；在具体主题的内部状态改变时，给所有登记过的观察者发通知。具体主题角色负责实现抽象主题中的方法。
- 抽象观察者（Observer）角色：为具体观察者提供一个更新接口。
- 具体观察者（ConcreteObserver）角色：存储与主题相关的自洽状态，实现抽象观察者提供的更新接口。

![](res/Observer.png)

> 在教室里老师还没有来，同学都在干着各的事情，小张正在打游戏，小李正在抄作业.....,  现在同学们要求班长当卧底，监视老师，当老师来了通知大家一声。然后打游戏的马上停止，抄作业的也停止。这里班长相当于是一个通知者， 小张、小李，以及其他同学显然是监听者，他们监听了班长那的消息，一旦老师来了马上采取相关的行动。

```cpp
#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;
class ITeacherListenner;
class ZhangSan;
class LiSi;
class INotifier;
class MonitorNotifier;

// 抽象观察者，为具体观察者提供一个更新借口
class ITeacherListenner
{
public:
    virtual void onTecherComming(int value) = 0;
};

// 抽象主题
class INotifier
{
    virtual void registerListenner(ITeacherListenner *l) = 0;
    virtual void removeListenner(ITeacherListenner *l)   = 0;
    virtual void notify()                                = 0;
};

// 具体主题
class MonitorNotifier : public INotifier
{
private:
    list<ITeacherListenner *> listenners;
    int                       mValue;

public:
    void registerListenner(ITeacherListenner *l)
    {
        listenners.push_back(l);
    }
    void removeListenner(ITeacherListenner *l)
    {
        list<ITeacherListenner *>::iterator it;
        for(it = listenners.begin(); it != listenners.end(); it++)
        {
            if(*it == l)
            {
                listenners.remove(l);
                break;
            }
        }
    }

    void notify()
    {
        list<ITeacherListenner *>::iterator it;

        for(it = listenners.begin(); it != listenners.end(); it++)
        {
            (*it)->onTecherComming(mValue);
        }
    }

    void setValue(int value)
    {
        mValue = value;
        notify();
    }
};

// 具体观察者
class ZhangSan : public ITeacherListenner
{
public:
    void stopCopyWork(int value)
    {
        cout << "zhangsan stop copy work + " << value << endl;
    }
    void onTecherComming(int value)
    {
        stopCopyWork(value);
    }
};

// 具体观察者
class LiSi : public ITeacherListenner
{
public:
    void stopCopyWork(int value)
    {
        cout << "lisi stop copy work + " << value << endl;
    }
    void onTecherComming(int value)
    {
        stopCopyWork(value);
    }
};

int main(void)
{
    cout << "Hello world 1---------------------" << endl;
    MonitorNotifier monitor;
    ZhangSan        zs;
    LiSi            ls;
    monitor.registerListenner(&zs);
    monitor.registerListenner(&ls);
    monitor.setValue(1);

    cout << "Hello world 2---------------------" << endl;
    monitor.removeListenner(&ls);
    monitor.setValue(2);
    return 0;
}
```