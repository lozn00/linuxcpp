#include "VirtualObj.cpp"
#include <stdio.h>
#include <stdlib.h>
class MyVirtualObj : public VirtualObj
{
    public:
    void call1()
    {
        printf("child call 1 \n");
    }
    bool call2()
    {

        printf("child call 2\n");

    }
    
};
int main()
{
    /**
     * 
     这个demo演示了,子类对象 指针父类指针,无法直接实现父类,但是可以实现 .


     * 
     * */
    MyVirtualObj myVirtualObj;
    myVirtualObj.call1();

    VirtualObj* parent=&myVirtualObj;
    parent->call1();
    parent->call2();
    parent->normalCall();//访问父类的 方法需要include cpp,否则 头文件夹就行
    // parent.call1();
    // VirtualObj parent;
    printf("test call virtual impl\n");
}