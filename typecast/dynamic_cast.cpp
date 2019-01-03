#include <iostream>
#include <string>
using namespace std;
class Base
{ //有虚函数，因此是多态基类
  public:
    virtual ~Base() {}
};
class Derived : public Base
{
};
int main()
{
    Base b;
    Derived d;
    Derived *pd;
    pd = reinterpret_cast<Derived *>(&b);
    if (pd == NULL)
        //此处pd不会为 NULL。reinterpret_cast不检查安全性，总是进行转换
        cout << "unsafe reinterpret_cast" << endl; //不会执行
    pd = dynamic_cast<Derived *>(&b);
    if (pd == NULL)                             //结果会是NULL，因为 &b 不指向派生类对象，此转换不安全
        cout << "unsafe dynamic_cast1" << endl; //会执行
    pd = dynamic_cast<Derived *>(&d);           //安全的转换
    if (pd == NULL)                             //此处 pd 不会为 NULL
        cout << "unsafe dynamic_cast2" << endl; //不会执行
    return 0;
}