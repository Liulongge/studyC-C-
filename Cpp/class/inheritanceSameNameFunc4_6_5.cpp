#include <iostream>
#include <string>

using namespace std;

// 继承是面向对象三大特征之一
// 有些类与类之间存在特殊的关系
// 我们发现定义这些类时，下级别的成员拥有上一级的共性，还有自己的特性
// 这时候我们就可以考虑利用继承技术，减少重复代码

// 继承的基本语法：
// 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中间内容不同
// 接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承的意义和好处

// 继承的好处：
// 减少重复的代码

// 语法：
// class 子类 ： 继承方式 父类
// 别称：
// 子类： 派生类
// 父类： 基类

// 派生类中的成员，包含两大部分
// 一类是基类继承过来的，一类是自己添加的成员
// 从基类继承过来的表现其共性，而新增的成员体现了其个性

// 继承的方式有三种：
// 1.公共继承
// 2.保护继承
// 3.私有继承

// ###### 继承中同名成员的处理方式 ######
// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据？
// 访问子类同名成员，直接访问即可
// 访问父类同名成员，需要加作用域

class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base - func()调用" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a)调用: " << a << endl;
    }

    int m_A;
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son - func()调用" << endl;
    }
    int m_A;
};

// 同名成员变量处理方式
void test01()
{
    Son s;
    cout << "Son 下 s.m_A = "<< s.m_A << endl;
    // 如果通过子类对象访问父类中的同名成员，需要加作用域
    cout << "Base 下 s.m_A = "<< s.Base::m_A << endl;
}

// 同名成员函数处理方式
void test02()
{
    Son s;
    // 直接调用，调用的是子类中的成员函数
    s.func();
    // 调用父类成员函数，加上作用域
    s.Base::func();
    // 如果子类中出现和父类同名成员函数，子类的同名成员会隐藏掉父类中所有同名成员
    // 全部隐藏掉，即使发生了重载
    // 需要加作用域
    s.Base::func(2);
}
int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}