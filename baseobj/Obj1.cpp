#include "Obj1.h"
#include <stdio.h>
void Obj1::hello()
{
    printf("hello\n");
}
//implicitly 隐式
 Obj1::Obj1()//头文件 必须定义Obj1否则 提示definition of implicitly-declared 
{
    printf("construct\n");
}

int main()
{
    Obj1 myObj;
    myObj.hello();
    printf("main \n");
}