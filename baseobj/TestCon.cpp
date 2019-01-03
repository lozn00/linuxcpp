
#include <iostream>
#include <stdio.h>
using namespace std;

class MyObj
{
  private:
  const  char *_str; //这里有没有const都一样.
    int value1;

  public:
    MyObj()
    {
        char mychar[] = "prison break";
        this->_str = "default";
        cout << "create default" << endl;
    }
    MyObj(char *str) : _str(str)
    {
        cout << "create->str:" << str << endl;
    }
    ~MyObj()
    {
        cout << "destory->str:" << _str << endl;
        // cout << "destory,name:"<<_str<< endl;
    }
    MyObj hello()
    {
        cout << "call hello" << endl;
        // return "NEW"; //create MyObj("str");等效下面这句话
        return MyObj("NEW");//出方法堆栈会自动删除
    }
};
int main()
{
    MyObj myObj;
    MyObj newObj = myObj.hello();
    printf("obj 1 %p obj 2 %p\n", &myObj, &newObj);
    MyObj *newObj1 = new MyObj("bb");
    delete newObj1; //这种new的方式必须释放 没有参数就没有括号.
  //  delete &newObj;//: free(): invalid pointer: 0x00007ffeb0c53dc0 ***不是new的不能删除
    printf("main_call over\n");
     /*
      
        create default
        call hello
        create->str:NEW
        obj 1 0x7ffc0dd61780 obj 2 0x7ffc0dd61790
        create->str:bb
        destory->str:bb
        main_call over
        destory->str:NEW
        destory->str:default

    // delete &myObj;

    这里有很多和java不一样的地方, 不是new的对象不能delete
    无参数构造初始化和java不一样,java需要Obj();而c++是 Obj;  c++如果用new则需要delete,否则就不要new
    返回一个对象可以返回其他字符串,实现自动把字符串放到返回值的对象的构造参数中,而且也可以自动释放.
   return "NEW"; == return MyObj("NEW");
  
  
   */
   
}
