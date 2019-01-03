#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<array>
int main(){
    //如果 泛型参数的值和 后面的成员总数不一致,会抛出错误 too many initializers for ‘std::array<int, 2ul>’
    std::array<int,3> my={10,30,150};
    for(std::array<int,2>::size_type i=0;i<my.size();i++){
        printf(" index %d value %d \n",(int)i,my[i]);
    }


    for(auto it=my.begin();it!=my.end();++it){
        printf(" it value %d\n",(int)(*it));
    }
}