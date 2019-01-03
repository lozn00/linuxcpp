#include <iostream>
#include <algorithm>
using namespace std;
void test1()
{

    int a[4] = {1, 2, 3, 4};
    int total = 0;
    for_each(a, a + 4, [&](int &x) { total += x; x *= 2; });
    cout << total << endl; //输出 10
    for_each(a, a + 4, [=](int x) { cout << x << " "; });
}
void test2()
{
    int x = 100, y = 200, z = 300;
    auto ff = [=, &y, &z](int n) {
        cout << x << endl;
        y++;
        z++;
        return n * n;
    };
    cout << ff(15) << endl;
    cout << y << "," << z << endl;
}
void test3()
{
    int a[4] = {11, 2, 33, 4};
    sort(a, a + 4, [=](int x, int y) -> bool { return x % 10 < y % 10; });
    for_each(a, a + 4, [=](int x) { cout << x << "----------"; });
}
int main()
{
    test2();
    test3();
    return 0;
}