// http://c.biancheng.net/cplus/80/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
int main()
{
    printf("main: %s", "aa");
    printf("...");
    const char *str = strstr("aaabbbaaa", "bb"); //接受结果必须为常量. 返回从这个字符串开始的所有字符串.
    const char *str1 = strcasestr("aaaBBBBB", "bb");
    printf(" str bb after: %s\n", str);
    printf(" str bb_ignoarecase after: %s\n", str1);           //忽略大小写
    const char *strchrresult = strchr("aaaaaabbaaalbaa", 'b'); //返回从某个字符开始的指针,失败返回NULL
    printf("strchr result %s \n", strchrresult);

    printf("strrchr result  从字符串中查找字符,从末尾开始查找,找到返回从这个回执开始的指针:\n %s\n\n", strrchr("aaaabbaaaabb----", 'b'));

    char src[40];
    // char *src;//may be used uninitialized in this function [-Wmaybe-uninitialized]
    char dest[100];

    memset(dest, '\0', sizeof(dest));
  char *resultcpy=  strcpy(src, "hello");
    printf("strcpy %s  result %s\n", src,resultcpy);
    // char* mystr="abcdefg";//ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
    const char *mystr = "abcdefg";
    memset(src, '\0', sizeof(src)); //src 如果不清空,那么 src之前也有,不会截断的. ,
    memccpy(src, mystr, 'd', 2);    //如果已经超过指定长度 那么 'd'还没找到,那么就只从mystr赋值这么多,后面的也不会设置\0
    printf("mem[c]cpy %s \n", src);
    // memccpy(src, mystr, 'd', strlen(mystr));//这里应该是输出abcd,
    memset(src, '\0', sizeof(src));
    void *result;
    const char *mystr1 = "abcd";
    result = mempcpy(src, mystr, 1); //返回值为地址 是mystr的 mystr起始地址移动到dest的结尾长度
    printf("[mem[p]cpy %s returnvalue %p ,src address %p endaddress %p]\n", src, &result, &mystr1,&mystr1+sizeof(mystr1));
    memset(src, '\0', sizeof(src));
    result = memcpy(src, "abcdefg", 3); //返回值就是参数1 也就是字符串
    printf("mem[]cpy %s returnvalue %s\n", src, (char *)result);

    int cmpresult=strncmp("abcdef1","abcdefg",7); //=0 相等,这里值如果只比对3个,所以应该等于0 ,如果改为7则等于 -1
    printf("str[n]cmp %d \n",cmpresult);
    cmpresult=strcmp("1","a");//equal =0 !equal = -1 or 1
    printf("strcmp result %d\n",cmpresult);

// char [30] mya;
//     strlcat(mya,"abcd",10);
    //    strcpy(src, "This is runoob.com");
    //    strcpy(dest, src);
}
