#include <iostream>
#include <stack> //使用stack需要包含此头文件
using namespace std;
int main()
{
    int n, k;
    stack<int> stk;
    cin >> n >> k; //将n转换为k进制数
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    while (n)
    {
        stk.push(n % k);
        n /= k;
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}