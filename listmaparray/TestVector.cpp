#include <vector>
#include <stdlib.h>
#include<iostream>
#include <stdio.h>
using namespace std;
struct  MyData{
    int a=1;
};
int main()
{
    vector<double> doublelist;
    // vector<int> intlist;
    vector<int> intlist{5}; //warning: extended initializer lists only available with解决方法 编译改成c++11 -std=c++11 or -std=gnu++11 [enabled by default]
    intlist.push_back(3);
    intlist.push_back(5);
    printf("main ...\n");
    vector<struct MyData> datalist;
    struct MyData data1;
    data1.a=1;
    datalist.push_back(data1);
    //warning: comparison between signed and unsigned integer expressions [-Wsign-compare] 解决办法把init i=0改成std::vector<int>::size_type i=0
    for (std::vector<int>::size_type i = 0; i < intlist.size(); i++)
    {
        printf("index  value %d value: %d \n ", (int)i, intlist[i]);
    }
    //结构体的遍历方法.
    for(auto it=datalist.begin();it!=datalist.end();++it){
            cout<<"structdata:"<<it->a<<""<<endl;
    }
        
        //基本类型的的迭代获取
    for (auto it = intlist.begin(); it != intlist.end(); ++it)
    // for (std::vector<int>::iterator it = intlist.begin(); it != intlist.end(); ++it)
    {
        cout<<"data:"<<(*it)<<endl;
        int dataValue=(*it);
        printf("value %d",dataValue);
        // cout<<"it"<<it<<","<<endl;
        // it.
        // printf("index  value %d value: %d \n ", value);
    }
    // for(int i=0;i<intlist.size();i++){  
    // : warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘std::vector<int>::size_type {aka long unsigned int}’ [-Wformat=]
    // int result=intlist[i];
    // int currentI=i;  [-Wunused-variable] 提示没有使用的变量,也就是没有使用的话可以删除了.
    /*
         expects argument of type ‘int’, but argument 2 has type ‘std::vector<int>::size_type {aka long unsigned int}’ [-
         解决办法  转换为int再进行传递,否则怎么弄都会报错.
         
         */
}