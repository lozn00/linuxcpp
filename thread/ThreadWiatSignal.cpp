#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
// pthread_ttid sigset_test;
pthread_t tid;
sigset_t set;
 
void myfunc()
{
    printf("hello\n");
}
 
static void *mythread(void *p)
{
    int signum;
    while (1)
    {
              printf("subthread loop start...\n");
        sigwait(&set, &signum);
        if (SIGUSR1 == signum)
            myfunc();//收到信号,调用这个方法.但是不会退出.
        if (SIGUSR2 == signum)
 
        {
            printf("Iwillsleep2secondandexit\n");
            sleep(2);
            break;
        }
        printf("subthread loop end...\n");
    }
    printf("subthread exit....");
}
 
int main()
{
    char tmp;
    void *status;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    sigprocmask(SIG_SETMASK, &set, NULL);
    pthread_create(&tid, NULL, mythread, NULL);
    while (1)
    {
        printf(":");
        scanf("%c", &tmp);
        if ('a' == tmp)
        {
            pthread_kill(tid, SIGUSR1); //发送SIGUSR1，打印字符串。
        } else if ('b' == tmp)
        {
            pthread_kill(tid, 100);
            printf("send signal \n");
        }
        else if ('q' == tmp)
        {
            //发出SIGUSR2信号，让线程退出，如果发送SIGKILL，线程将直接退出。
            pthread_kill(tid, SIGUSR2);
            //等待线程tid执行完毕，这里阻塞。
            pthread_join(tid, &status);
            printf("finish\n");
            break;
        }
        else
            continue;
    }
    return 0;
}