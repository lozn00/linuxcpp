#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[7] = {'a', 'b', 'c', 'd', 'e', '\0', '0'};
    printf("str1: %s \n", str1); //print  abcde
    char str2[] = "abcdefg";
    printf("str2:%s \n", str2);
    //警告----------------
    char *str3 = "abcdefgh"; //warning: deprecated conversion from string constant to ‘char*’ 不推荐从字符串厂里转换为char*
    printf("str3:%s \n", str3);
    const char *str4 = "abcdefg";
    printf("str3:%s\n", str4);
    //警告-----------------
    char *str5 = {"abcdefg"}; //conversion from string constant to ‘char*’ [-Wwrite-strings] 依然是字面值常量
    printf("str5:%s\n", str5);

    char *str6 = new char[6]{'a', 'b', 'c', '\0'};
    printf("str6:%s\n", str6);
    const char *str7 = new char[6]{'x', 'y', 'z', '\0'};
    printf("str7:%s\n", str7);
    return 0;
}