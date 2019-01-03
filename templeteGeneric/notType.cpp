#include <iostream>
#include <stdio.h>
using namespace std;
template <class T, int size>
class CArray
{

  public:
    T array[size];
    T t;
    CArray(){}
    CArray(int arg[]) : array(arg)
    {
    }
      CArray(T arg) : t(arg)
    {
    }
    void Print()
    {
        for (int i = 0; i < size; ++i)
            cout << "[" << array[i] << "]" << endl;
    }
};
class CArray1
{
  public:
    int size = 5;
    int _array[5];
    int intvalue;
    CArray1()
    {
        printf("默认构造call\n");
    }
    CArray1(int intvaluearg) : intvalue(intvaluearg)
    {
        //class内部访问成员  this是一个指针
        printf("int构造初始化 value %d\n", this->intvalue); //expression must have a class type” - c++  SO ->
    }
    CArray1(int arr[] ) : _array() //初始化列表里面传递也不行,invalid initializer for array member
    {
        // error: incompatible types in assignment of ‘int*’ to ‘int [5]’
        // _array =arr; //expression must be a modifiable lvalue 也不行,无法赋值
    }
    void Print()
    {
        for (int i = 0; i < size; ++i)
            cout << "[" << _array[i] << "]" << endl;
    }
};
int main()
{
    int aaa[6] = {3, 5, 6, 4, 4,7};
    int b = 5;
    CArray1 arr;
    CArray1 arr1 = CArray1();
    CArray1 arr2 = CArray1(6);
    CArray1 arr3 = CArray1(aaa);


    CArray<int,5> arra;
    // int* a=aaa;//正常
    int* a=aaa;
    CArray<int,5> arrb= CArray<int,5>(a);//error: incompatible types in assignment of ‘int’ to ‘int [5]
    arrb.Print();
    printf("  a: %#x\n",a);
    // arr.array=aaa;
    // CArray<int, 5> myarr ;//= CArray<int, 5>(33);
    // myarr.array= aaa;
    //  myarr.Print();
}