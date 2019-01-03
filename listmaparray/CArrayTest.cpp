#include<stdio.h>
#include<stdlib.h>
int main()
{
    int temp[100] = {10}; //数组 一旦初始化不能重新赋值,但是可以逐个对元素进行赋值.
    //c 11不需要=
    int temp2[3]{10, 1, 5};


    printf("test... temp:%p temp2:%p \n",&temp,&temp2);
    return 0;
}