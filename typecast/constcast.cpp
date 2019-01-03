#include <string>
#include<iostream>
using namespace std;
int main()
{
    const string s = "Inception";
    string &p = const_cast<string &>(s);
    string *ps = const_cast<string *>(&s); // &s 的类型是 const string*
    return 0;
}