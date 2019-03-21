#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    const char *fileName = "AAaaAaa333aA.txt";
    FILE *fp = fopen(fileName, "wr"); //r如果放前面,而这个时候文件不存在就会打开失败!
    if (fp == NULL)
    {
        perror("read fail ...");
        printf("create fp fail\n");
        return 0;
    }
    fputs("abbbcdefghijklmnopqrstuwxy", fp);
    fclose(fp);

    printf("write succ..\n");
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf(" two fopen fail \n ");
        return -1;
    }
    char buf[2048];
    fgets(buf, 2, fp);
    printf("read buf %s \n", buf);
    fclose(fp);

    fp = fopen("/proc/self/cmdline", "r");
    if (fp == NULL)
    {
        printf("read cmdline fail!");
        return 0;
    }
    memset(buf, '\0', sizeof(buf));
    fgets(buf, sizeof(buf), fp);
    printf("read cmdline %s \n", buf);

    if ((fp = popen("/usr/bin/uptime", "r")) == NULL)
    {
        sprintf(buf, "error:%s\n", strerror(0));
    }
    else
    {
        memset(buf, '\0', sizeof(buf));
        while(!feof(fp)){

        fgets(buf, sizeof(buf), fp);
        printf("popen time %s \n",buf);
        pclose(fp);
        }
        printf(" read over \n");
    }
}