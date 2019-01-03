#include <stdio.h>
#include <stdlib.h>

/*

（1）以引用返回函数值，定义函数时需要在函数名前加 &

（2）用引用返回一个函数值的最大好处是，在内存中不产生被返回值的副本。

引用作为返回值，必须遵守以下规则：

（1）不能返回局部变量的引用。主要原因是局部变量会在函数返回后被销毁，因此被返回的引用就成为了"无所指"的引用，程序会进入未知状态。
 （2）不能返回函数内部new分配的内存的引用。虽然不存在局部变量的被动销毁问题，可对于这种情况（返回函数内部new分配内存的引用），又面临其它尴尬局面。例如，被函数返回的引用只是作为一 个临时变量出现，而没有被赋予一个实际的变量，那么这个引用所指向的空间（由new分配）就无法释放，造成memory leak。
 （3）可以返回类成员的引用，但最好是const。主要原因是当对象的属性是与某种业务规则（business rule）相关联的时候，其赋值常常与某些其它属性或者对象的状态有关，因此有必要将赋值操作封装在一个业务规则当中。如果其它对象可以获得该属性的非常 量引用（或指针），那么对该属性的单纯赋值就会破坏业务规则的完整性。

 */
void testVarReference()
{
    int a = 1;
    int b = 1;
    int &useA = a; //地址指向a,是引用,因此地址也一样.
    int useA1 = a; //克隆一个值 所以地址也不一样

    printf("test a:%d  b:%d\n", a, b);
    printf("真实a值:%d,地址%#x,引用的a值:%d,地址:%#x ,拷贝的a值:%d,地址:%#x\n", a, (unsigned int)(long)&a, useA, (unsigned int)(long)&useA, useA1, (unsigned int)(long)&useA1);

    //真实a值:1,地址0xe93c552c,引用的a值:1,地址:0xe93c552c ,拷贝的a值:1,地址:0xe93c5530

    /*

     warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 3 has type ‘int*’ [-Wformat=]
    解决办法

 &a修改为 (unsigned int)(long)&a
     */
}
/**
 *本方法实现了直接操作内存进行交换.
 *  
 */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;    //去除数据 修改它指向的数据
    b = temp; //去除数据修改指向的数据
}

void testParamReference()
{
    int a = 10;
    int b = 15;
    printf("swap before:a:%d b:%d \n", a, b);
    swap(a, b);
    printf("swap after: a:%d b:%d \n", a, b);
}
int resultArr[3] = {0};
int &addCalcByArr(int a, int b)
{
    //因为 result是局部的,返回不合法会提示 warning: reference to local variable ‘result’ returned [-Wreturn-local-addr]
    int result = a + b;
    resultArr[1] = result;
    printf("%d +%d =%d,  address  %#x \n", a, b, result, (unsigned int)(long)&resultArr[1]);
    int &current = resultArr[1];
    return current;
    //静态 地址改变了, 数组 ,地址也改变了.
}
int &addCalcByStatic(int a, int b)
{
    int static value = a + b;
    printf("addCalcByStatic value %d address %#x \n", value, (unsigned int)(long)&value);
    return value;
}
void testReturnVlaueReference()
{
    // int result = addCalc(5, 6);
    // printf("return after:result %d  address %#x \n", result, (unsigned int)(long)&resultArr[1]);
    addCalcByArr(5, 6) = 160;                  //只有引用才能这样赋值,局部变量不能返回,静态变量也可以,但是记得返回的时候要取地址.
    printf("arr[1]的值:%d \n", resultArr[1]);  //结果必须是160
    int &referenceVar = addCalcByStatic(5, 6); //这里也需要定义引用,不然又创建一个拷贝了
    printf("value %d ,address %#x \n", referenceVar, (unsigned int)(long)&referenceVar);
}
int main()
{

    // testParamReference();
    testReturnVlaueReference();
}