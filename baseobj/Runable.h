#ifndef TEST_INTERFACE
#define TEST_INTERFACE
class Runable
{

  public:
  
  //  Runable();
    virtual void run();
    virtual int hashCode();
    //如果 纯虚函数,那么是()=0;而且实现是子类吧.
};
 #endif