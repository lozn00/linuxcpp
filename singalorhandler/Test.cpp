#include <csignal>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
/*

SIGABRT =6	程序的异常终止，如调用 abort。
SIGFPE =8	错误的算术运算，比如除以零或导致溢出的操作。
SIGILL =4	检测非法指令。
SIGINT =2 	接收到交互注意信号。
SIGSEGV =11	非法访问内存。
SIGTERM	=15 发送到程序的终止请求。
*/
void myHandler(int signum)
{
    string str;
    switch (signum)
    {
    case SIGINT:
        str.append("交互信号");
        break;
    case SIGILL:
        str.append("非法指令");
        break;
    case SIGABRT:
        str.append("程序异常终止");
        break;
    case SIGSEGV:
        str.append("非法访问内存");
        break;
    case SIGTERM:
        str.append("发送到程序的终止请求。");
        break;
    default:
        str.append("unknown signal");
        break;

    }
    
        char numberStr[2];
        sprintf(numberStr, "(singaltype:%d)", signum);
        string temp = numberStr;
        str.append(temp);
    printf("receive signal %s  \n", str.c_str());
    exit(signum);
}
int main()
{

    cout << "test" << endl;
    int trysignalType = SIGABRT;
    signal(trysignalType, myHandler);
    // signal(SIGINT, myHandler);
    int i = 0;
    while (true)
    {
        i++;

        // if(i==100){
        // signal(100);
        sleep(1);
        // usleep(100000);
        // }
        printf(" index=%d \n", i);
        if (i == 5)
        {
            raise(trysignalType); //如果没有用signal 捕获,那么将抛出异常 这里是发送信号
            // raise(SIGILL);

        } //也可以写死循环终止控制台也会受到信号
    }
}