#include <iostream>
using namespace std;
class A
{
  public:
    operator int() { return 1; }
    operator char *() { return NULL; }
};
int main()
{
    A a;
    int n;
    char *p = "New Dragon Inn";
    n = static_cast<int>(3.14); // n 的值变为 3
    n = static_cast<int>(a);    //调用 a.operator int，n 的值变为 1
    p = static_cast<char *>(a); //调用 a.operator char*，p 的值变为 NULL
   // n = static_cast<int>(p);    //编译错误，static_cast不能将指针转换成整型
    //p = static_cast<char *>(n); //编译错误，static_cast 不能将整型转换成指针
    return 0;
}