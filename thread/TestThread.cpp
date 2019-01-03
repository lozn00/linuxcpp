#include <pthread.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

// g++ TestThread.cpp -o thread -lpthread
int i = 0;
void *myrun(void *arg)
{
    while (true)
    {
        i++;
        printf("myrun call %d \n ", i);
        sleep(1);
        if (i > 100)
        {
            break;
        }
    }
}
void *myrun1(void *arg)
{
    while (true)
    {
        i++;
        printf("myrun call %d sleep .... \n ", i);
        sleep(2);
        if (i > 5)
        {
            printf("subthread will exit_start\n");
            // pthread_exit(NULL);//执行到这里之后下面不会执行. 子进程写不写没有任何关系.
            printf("subthread will exit_end\n");
            break;
        }
    }
}
void *runparam(void *arg)
{
    int *intp = (int *)arg; //转换为int指针
    int intValue = *intp;   //解指针
    printf("subthread  param %d \n", intValue);
}
struct ThreadData
{
    int threadId;
    char *threadName;
};
void *runparamstruct(void *arg)
{
    struct ThreadData *data = (struct ThreadData *)arg; //转换为int指针
    printf("subthread  threadid %d,name %s\n", data->threadId,data->threadName);
}
void keepMain()
{
    pthread_t threadid;
    // void *(*__start_routine) (void *)
    pthread_create(&threadid, NULL, myrun, NULL);
    sleep(1);
    printf("main over \n");
    pthread_exit(NULL); //加上这个之后就不会随着子线程的死去而死去.
}
void testCreateMUltiThread()
{
    for (int i = 0; i < 15; i++)
    {

        pthread_t threadid;
        usleep(10000);
        pthread_create(&threadid, NULL, myrun1, NULL);
    }
    printf("MAIN OVER_WILL \n");
    pthread_exit(NULL); //下面的话不会再执行.
    printf("MAIN OVER \n");
}

void testCreateMUltiThreadParam()
{
    for (int i = 0; i < 15; i++)
    {
        pthread_t threadid;
        usleep(10000);
        int copyi = i;
        pthread_create(&threadid, NULL, runparam, &copyi);
    }
    printf("MAIN OVER_WILL \n");
    pthread_exit(NULL); //下面的话不会再执行.
    printf("MAIN OVER \n");
}

void testCreateMUltiThreadParamStruct()
{
    for (int i = 0; i < 15; i++)
    {
        pthread_t threadid;
        usleep(10000);
        int threadIdInt = i;
        struct ThreadData currentThreadData;
        currentThreadData.threadId=threadIdInt;

        // char* name;
        char name[15];
        sprintf(name,"线程%d",threadIdInt);
        currentThreadData.threadName=name;
        // currentThreadData.threadName=name;
        pthread_create(&threadid, NULL, runparamstruct, &currentThreadData);
    }
    printf("MAIN OVER_WILL \n");
    pthread_exit(NULL); //下面的话不会再执行.
    printf("MAIN OVER \n");
}

void joinThreadTest(){
    
}
int main()
{
    // keepMain();
    // testCreateMUltiThread();
    // testCreateMUltiThreadParam();
    // testCreateMUltiThreadParamStruct();
    /*
    while (true)
    {
        sleep(1);
        if (i > 5)
        {
            printf("cal pthread_exit \n");
            pthread_exit(NULL);
            break;
        }else{
            printf("main i %d \n",i);
        }
    }
    */
}
