#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 1;
    int b = 1;

    printf("address %#x %#x\n",(unsigned int)(long)&a, (unsigned int)(long)&b);
    printf("address %#x \n",(unsigned int)(long)&a); //如果直接转为 (unsigned int)会提示 丢失精度precision  cast from ‘int*’ to ‘unsigned int’ loses precision [-fpermissive] 所以需要多重转换
    return 0;
}