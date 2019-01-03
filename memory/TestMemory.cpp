#include <stdio.h>
using namespace std;

int main()
{
    // std::auto_ptr<Investment>
    printf("hello memory");
    
    //如果在一个方法里面创建一个对象,作为返回,那么应该使用new, 另外记得delete c就比较蛋疼了一大把申请内存的方法,导致混淆
    return 0;
}