#include <iostream>
#include <stdio.h>
#include "VirtualObj.h"

void VirtualObj::call1()
{
//这里是没有意义的,似乎永远无法访问到.
}

void VirtualObj::normalCall(){
    printf(" VirtualObj normal Call");
}

 bool VirtualObj::call2()
{

    printf(" 定义有意义吗?你能够访问到我吗?不能吧");
 }
int main1()
{
    
    /*
    object of abstract class type 
    "VirtualObj" is not allowed:
     -- function "VirtualObj::call1" is a pure virtual
      function -- function 
      "VirtualObj::call2"  is a pure virtual function
      抽象类 是无法实例化,必须用子类, 可以通过指针把指针强转为父类.
   VirtualObj obj; //这样是错误的.
    */
    printf("virtual Obj");
}