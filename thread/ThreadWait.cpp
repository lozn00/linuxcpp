#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
 
using namespace std;
 
#define NUM_THREADS    30
 
void *wait(void *t)
{
   int i;
   long tid;
 
   tid = (long)t;
 
   sleep(2);
   cout << "Sleeping in thread " << endl;
   cout << "Thread with id : " << tid << "  ...exiting " << endl;
   pthread_exit(NULL);
}
 
int main ()
{

    /*

    pthread_join的应用
pthread_join使一个线程等待另一个线程结束。
代码中如果没有pthread_join主线程会很快结束从而使整个进程结束，从而使创建的线程没有机会开始执行就结束了。加入pthread_join后，主线程会一直等待直到等待的线程结束自己才结束，使创建的线程有机会执行。


所有线程都有一个线程号，也就是Thread ID。其类型为pthread_t。通过调用pthread_self()函数可以获得自身的线程号。


在Linux中，默认情况下是在一个线程被创建后，必须使用此函数对创建的线程进行资源回收，
但是可以设置Threads attributes来设置当一个线程结束时，直接回收此线程所占用的系统资源，详细资料查看Threads attributes。
*/
   int createResult;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;
 //pthread_join 之后主进程不会死去,除非子进程死去.
   // 初始化并设置线程为可连接的（joinable）
//    pthread_attr_init(&attr);
//    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
   for( i=0; i < NUM_THREADS; i++ ){
      cout << "main() : creating thread, " << i << endl;
      createResult = pthread_create(&threads[i], NULL, wait, (void *)&i );
      usleep(5000);
      if (createResult){
         cout << "Error:unable to create thread," << createResult << endl;
         exit(-1);
      }
   }
 
   // 删除属性，并等待其他线程
//    pthread_attr_destroy(&attr);
   for( i=0; i < NUM_THREADS; i++ ){
      createResult = pthread_join(threads[i], &status);
      if (createResult){
         cout << "Error:unable to join," << createResult << endl;
        //  exit(-1);
      }
      cout << "Main: completed thread id :" << i ;
      cout << "  exiting with status :" << status << endl;
   }
 
   cout << "Main: program exiting." << endl;
   pthread_exit(NULL);
}