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

// 继承实现页面
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

// 1.公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10;       // 父类中的公共权限成员 在子类中依然是公共权限
        m_B = 10;       // 父类中的保护权限成员 在子类中依然是保护权限
        // m_c = 10;    // 父类中的私有权限成员 在子类中访问不到
    }
};

// 2.保护继承
class Son2 : protected Base1
{
public:
    void func()
    {
        m_A = 10;       // 父类中的公共权限成员 在子类中变成了  保护权限
        m_B = 10;       // 父类中的保护权限成员 在子类中依然是保护权限
        // m_c = 10;    // 父类中的私有权限成员 在子类中访问不到
    }
};

// 3.私有继承
class Son3: private Base1
{
public:
    void func()
    {
        m_A = 10;       // 父类中的公共权限成员 在子类中变成了  私有权限
        m_B = 10;       // 父类中的保护权限成员 在子类中变成了  私有权限
        // m_c = 10;    // 父类中的私有权限成员 在子类中访问不到
    }
};

// 
class GrandSon3 : public Son3
{
public:
    void func()
    {
        // 访问不到
        // m_A = 10; // m_A 在Son3中变成了 私有权限，访问不到
        // m_B = 10; // m_B 在Son3中变成了 私有权限，访问不到
        // m_C = 10; //
    }
};

// 1.公共继承
void test01()
{
    Son1 s1;
    s1.m_A = 100;    // 到Son1中 m_A 是公共权限，类外可以访问
    // s1.m_B = 100; // 到Son1中 m_B 是保护权限，类外访问不到
}

// 2.保护继承
void test02()
{
    Son2 s2;
    // s2.m_A = 100; // 到Son2中 m_A 是保护权限，类外不可以访问
    // s2.m_B = 100; // 到Son2中 m_B 是保护权限，类外访问不到
}

// 2.私有继承
void test03()
{
    Son3 s3;
    // s3.m_A = 100; // 到Son3中 m_A 是私有权限，类外不可以访问
    // s3.m_B = 100; // 到Son3中 m_B 是私有权限，类外访问不到
}

int main(int argc, char *argv[])
{
    test01();
    test02();
    test03();
    return 0;
}