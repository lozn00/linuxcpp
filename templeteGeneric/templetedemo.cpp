/*
优先级顺序是先找普通函数匹配的然后找函数匹配的,还是没找到就报错了.
c++的这种和java不同,c++可以随便定义模板函数,而java只能定义泛型类.
*/
#include <stdio.h>
#include <stdlib.h>
template <class T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}
void swap(float& b,float &c){
    float& temp=b;
    b=c;
    c=temp;
    printf("swap normal method call \n");
}
int main()
{
    printf("templete \n");
    int a = 1;
    int b = 3;
    float c=4;
    float d=5;
    swap(a, b);
    swap(c,d);
   // swap<int>(a, b);//正常
    //swap(a, c);// deduced conflicting types for parameter ‘T’ (‘int’ and ‘float’)
    printf("a=%d,b=%d  c=%.2f\n", a, b,c);
}