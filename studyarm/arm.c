#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void myFunctiontrue1()
{
}
void myFunctionfalse1()
{
}
void myFunctiontrue2()
{
}
void myFunctionfalse2()
{
}
void myFunctiontrue3()
{
}
void myFunctionfalse3()
{
}
void myFunctiontrue4()
{
}
void myFunctionfalse4()
{
}
void myFunctiontrue5()
{
}
void myFunctionfalse5()
{
}
int myfunc6True()
{
    int random = rand() % time(0);
    if (random > 10)
    {
        return 20;
    }
    return 1;
}

int main()
{
    int random = rand() % time(0);
    printf("hello random %d\n", random);
    int a = random;
    int b = 2;
    int c = 5;
a:
    if (a - 2 > 2)
    {
        myFunctiontrue1();
    }
    else
    {
        myFunctionfalse1();
    }
    int jumpBool = a - 2 > 2;
    if (jumpBool)
    {
        myFunctiontrue2();
    }
    else
    {
        myFunctionfalse2();
    }
    jumpBool = a - 2 > 2;
    if (jumpBool > 5)
    {
        myFunctiontrue3();
    }
    else
    {
        myFunctionfalse3();
    }
    jumpBool = a - 2 > 2;
    if (jumpBool < 5)
    {
        myFunctiontrue4();
    }
    else
    {
        myFunctionfalse4();
    }

    if (jumpBool > 5 || jumpBool < 2)
    {
        myFunctiontrue5();
    }

    int bb=myfunc6True();

myb:
    c++;

    if (c < 10)
    {
        printf("%d<10, gotb ++\n", c);
        goto myb;
    }
    else
    {
        if (c < 15)
        {
            printf("%d<15, gotb ++ \n", c);
            goto myb;
        }
    }
    printf(" end %d" ,bb);

    return 0;
}