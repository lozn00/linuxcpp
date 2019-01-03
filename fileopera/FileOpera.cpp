#include <iostream>
#include <fstream>
using namespace std;
// #include<string>
int main()
{
std:
    string a = "abc";
    a.append("defg");
    cout << "substr:\r\n"
         << a.substr(1, 2) << endl;
    printf("--------------------\n");
    ofstream myoutstream;   //输出表示输出到文件
    ifstream myinputstream; //输入
    myinputstream.open("1.txt", ios::in);
    char data[100];
    myinputstream >> data; //读入数据赋值给变量.
    printf("last  daa :%s \n", data);
    //------------
    myoutstream.open("1.txt", ios::out);          //文件必须存在
    myoutstream << "abcdefg" << endl; //写入
    myoutstream<<"ABCDEFG"<<endl;
    myoutstream<<"HIJKLMN"<<endl;
    printf("write data finish \n");

    myinputstream.close();
    myoutstream.close();
    //--------------------

    printf("end....\n");
    fstream twostream; //具有输入输出的功能.
    // twostream.open("1.txt", ios::in | ios::out);            //覆盖
    twostream.open("1.txt", ios::in | ios::out | ios::app); //追加到末尾
    twostream.seekg(0);                                     //seek到任何位置都是一样的.
    twostream << "hello world" << endl;          //在末尾insert 一行
    char data_current[10];
    twostream.seekg(0);
   twostream.seekg(-2, ios::end); //往前面移动 怎么移动度没有用 原来填写的值应该是负数.//-2为最后一个字符,可以表明,-1是结尾换行符.


    twostream >> data_current;
    printf("[write,read] data,  (%s) \n ", data_current);//
    // twostream<<endl;
    // twostream.seekg(ios::end);

    twostream.close();
    //=---------------------
    fstream twostream1;
    twostream1.open("1.txt");
    char data_current2[1024];//不够的时候出毛病了,实际上只能读入一行
    twostream1.seekg(1,ios::cur);//第一次读入,广播为1,移动之后那么就是2,所以第一个字母为 b


    twostream1 >> data_current2; //读入数据赋值给变量.只能读入一行,而且是完全读入.
    printf("read data :(%s) \n", data_current2);
    // twostream1.seekg(0);//再次移动到0 ,那么下一次读入的和这一次一样.
    twostream1>>data_current2;
    printf("read data :(%s) \n", data_current2);
    twostream1.seekg(-12,ios::end);
    twostream1>>data_current2;//移动之后只能读取几个字节了.原来是根据换号或者空格作为分割结尾的.
    printf("lastread data :(%s) \n", data_current2);

    //  myoutstream.open("FileOpera.cpp");

    // std::string

    /*

        compile exeover
        substr:
        bc
        --------------------
        last  daa :abcdefg
        write data finish
        end....
        [write,read] data,  (d)
        read data :(bcdefg)
        read data :(ABCDEFG)
        lastread data :(hello)
*/
}