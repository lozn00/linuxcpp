#include <stdio.h>
#include <stdlib.h>

/*
g++ TestDefine.cpp  -save-temps 保存  ii文件
.h	C或者C++源代码头文件
.ii	C++源代码（不需编译预处理）
.o	对象文件
.s	汇编语言代码
.so	动态库
<none>	标准C++系统头文件
g++ TestDefine.cpp  -E 会直接生成预处理的结果在控制台可以>写到文件
g++ file -S 生产汇编
g++  file -c 生产目标文件.o

宏定义中#s表示 把这个用字符串""包裹
##s表示这个名字和前面的某个东西链接 ,比如_##p 传递一个值为a,那么变成了_a 那么如果没有##那么是无法识别的,所以这就是他的作用.

举例  

举例  
#define CALL(f,p) printf("Call function %s\n", _##p)
  CALL(abs,10);
 printf("Call function %s\n", _10);
 举例
#define CALL(f,p) printf("Call function %s\n", #p)
  CALL(abs,10);
  printf("Call function %s\n", "10");
错误举例
#define CALL(f,p) printf("Call function %s\n", _p)
    CALL(abs,10);
    printf("Call function %s\n", _p);
这里无法识别p参数.

android日志举例 
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s]" "bb", "文件名宏定义", "函数名宏定义", "bb1");
    //输出 [文件名宏定义:函数名宏定义]bb 这里我当时比较困惑的是为什么两个字符串在一起拼写，这明显的语法错误么，其实这可以这么写的，    

所以
#define LOGV(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s]" fmt,"文件名宏定义", "函数名宏定义",##__VA_ARGS__)
调用LOGV("AAA") 那么第一个参数fmt就被替换了, 也就输出了[文件名:函数名] aaa  
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s]" "bb","文件名宏定义", "函数名宏定义");
调用LOGW("AAA %s","BBB")
转换的结果是 

    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s]" "AAA %s","文件名宏定义", "函数名宏定义","bb1");
如果删掉让我疑惑的双引号其实就是
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s] AAA %s","文件名宏定义", "函数名宏定义","bb1");

其中... 被分别替换成 ##__VA_ARGS__ 所以传递多个参数也是可以的.

*/
#define CALL(f,p) printf("Call function %s\n", _p)
#define testFunc(funcname,value) printf("%calc number :%d result %d",value,funcname) funcname(value))

   //__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s]" "bb",TF(), __FUNCTION__);
#define LOGV(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%s:%s]" fmt,"文件名宏定义", "函数名宏定义",##__VA_ARGS__)


int main()
{

    printf("hello ");
   // testFunc(square,5);
}