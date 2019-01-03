#include <iostream>
using namespace std;
class CDemo
{
  private:
    int n;

  public:
    CDemo(int i = 0) : n(i) {}
    CDemo &operator++();   //用于前置形式
    CDemo operator++(int); //用于后置形式
    operator int() { return n; }
    friend CDemo &operator--(CDemo &);
    friend CDemo operator--(CDemo &, int);
};
CDemo &CDemo::operator++()
{ //前置 ++
    n++;
    return *this;
}
CDemo CDemo::operator++(int k)
{                     //后置 ++
    CDemo tmp(*this);//记录修改前的对象 另外这里会自动调用 一个int参数的够赞
    n++; //5,6,7,7 屏蔽就变成了55 xx++无效了,但是无法理解做了什么鬼操作.
    return tmp; //返回修改前的对象
}
CDemo &operator--(CDemo &d)
{ //前置--
    d.n--;
    return d;
}
CDemo operator--(CDemo &d, int)
{ //后置--
    CDemo tmp(d);
    d.n--;
    return tmp;
}
int main()
{
    CDemo d(5);
    cout << (d++) << ","; //等价于 d.operator++(0);
    cout << d << ",";
    cout << (++d) << ","; //等价于 d.operator++();
    cout << d << endl;
    cout << (d--) << ","; //等价于 operator-(d,0);
    cout << d << ",";
    cout << (--d) << ","; //等价于 operator-(d);
    cout << d << endl;
    return 0;
}