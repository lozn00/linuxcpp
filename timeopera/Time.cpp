#include <iostream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
// #include<stdlib.h>
using namespace std;
int main()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    //Mon Dec 24 09:54:44 2018
    printf("current date:%s \n", dt);
    long longtime = now; //timesamp
    printf("longtime: %ld \n", longtime);
    char temp[64];
    //:2018-12-24 09:58:46
    strftime(temp, sizeof(temp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("ymd format:%s\n", temp);
    tm *tm = localtime(&now);
    cout << "距离1980:" << tm->tm_year << endl
         << "现在是这一年的多少天了?" << tm->tm_yday << endl
         << "月:" << tm->tm_mon << endl
         << "日:" << tm->tm_mday << endl
         << "小时:" << tm->tm_hour << endl
         << "分:" << tm->tm_min << endl
         << "秒:" << tm->tm_sec << endl
         << "east second:" << tm->tm_gmtoff << endl
         << "夏令时:" << tm->tm_isdst << endl
         << endl;
    char *asctimestr = asctime(tm); // Mon Dec 24 10:21:30 2018
    printf("asctime %s \n", asctimestr);
    time_t timet = mktime(tm); //还是原来的时间戳,没啥变化.
    printf("time_t %ld\n", timet);
    long current = 1000000;
    long sleepSecond = 5;
    long calcSecond = current * sleepSecond;
    usleep(calcSecond);
    time_t now1 = time(0);
    double timediff = difftime(now1, now);//big time -short time
    printf("时间差:%f \n", timediff);
}