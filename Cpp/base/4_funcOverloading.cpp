#include<iostream>

using namespace std;

// 函数重载
// 作用：函数名可以相同，提高复用性
// 函数重载满足条件：
// 1.同一作用域下
// 2.函数名相同
// 3.函数参数类型不同，或者个数不同 或者顺序不同

// 注意：函数的返回值不可以作为函数重载的条件

void func(void)
{
    cout << "func 的调用" << endl;
}

void func(int a)
{
    cout << "func(int a)的调用" << endl;
}

void func(double a)
{
    cout << "func(int a)的调用" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int b)的调用" << endl;
}

void func(int a, double b)
{
    cout << "func(int a, double b)的调用" << endl;
}

// 无法重载仅按返回类型区分的函数
// double func(int a, double b)
// {
//     cout << "func(int a, double b)的调用" << endl;
// }

int main()
{
    func();
    func(10);
    func(3.14);
    func(3.14, 10);
    func(10, 3.14);
    return 0;
}