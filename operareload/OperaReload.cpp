#include <iostream>
using namespace std;
class Complex
{
  public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex operator-(const Complex &c);
};
Complex operator+(const Complex &a, const Complex &b)
{
    return Complex(a.real + b.real, a.imag + b.imag); //返回一个临时对象
}
Complex Complex::operator-(const Complex &c)
{
    return Complex(real - c.real, imag - c.imag); //返回一个临时对象
}

class MyA
{
  public:
    int value;
    MyA(int value) : value(value)
    {
    }

    MyA operator+(const MyA &a)
    { //如果没有定义强制 访问 提示  error: no match for ‘operator+’
        MyA temp(a.value + this->value);
        return temp;
    }
    MyA operator-(MyA &a)
    {
        return MyA(this->value - a.value);
    }
    MyA operator*(MyA &a)
    {
        return MyA(this->value * a.value);
    }
    MyA operator/(MyA &a)
    {
        return MyA(this->value / a.value);
    }
    MyA operator%(MyA &a)
    {
        return MyA(this->value % a.value);
    }
    //$#@!~~:等非运算 的都不支持
    MyA operator=(MyA &a)
    {
        return MyA(this->value * a.value * a.value);
    }
    MyA operator!=(MyA &a)
    {
        return MyA(this->value * a.value * a.value);
    }
    MyA operator==(MyA &a)
    {
        return MyA(this->value == a.value);
    }
    MyA operator<(MyA &a)
    {
        return MyA(this->value == a.value);
    }
    MyA operator>(MyA &a)
    {
        return MyA(this->value == a.value);
    }
    MyA operator<<(MyA &a)
    {
        return MyA(this->value << a.value);
    }
    MyA operator>>(MyA &a)
    {
        return MyA(this->value >> a.value);
    }

    MyA operator|(MyA &a)
    {
        return MyA(this->value | a.value);
    }
    MyA operator&(MyA &a)
    {
        return MyA(this->value & a.value);
    }
    MyA operator<=(MyA &a)
    {
        return MyA(this->value * this->value * a.value);
    }
    MyA operator>=(MyA &a)
    {
        return MyA(this->value * this->value * a.value);
    }
    MyA operator^(MyA &a)
    {
        return MyA(this->value * this->value * a.value);
    }
    MyA operator++()
    {
        this->value++;
        return *this;
    }
       MyA operator--()
    {
        this->value--;
        return *this;
    }
    //   MyA operator>=(MyA &a)
    // {
    //     return MyA(this->value * this->value * a.value);
    // }
};

/*
ambiguous overload for ‘operator>>’ (operand types are ‘MyA’ and ‘MyA’) 模棱两可含糊的定义原因是全局和非全局度存在
     value = (temp1 >> temp2).value;
     */
// MyA operator >> (MyA &a, MyA &b){
//     printf(" call MyA >> global\n");
//     return MyA(a-b);
// }
class MyB
{
  public:
    int value;
    MyB(int value) : value(value)
    {
    }
};

int main()
{
    Complex a(4, 4), b(1, 1), c;
    c = a + b; //等价于 c = operator + (a,b); +是全局的没有使用::,
    cout << c.real << "," << c.imag << endl;
    //同字段和同字段相减,4-1=3
    cout << (a - b).real << "," << (a - b).imag << endl; //a-b等价于a.operator - (b)
    MyA temp1(20);
    MyA temp2(5);
    int value = (temp1 + temp2).value;
    printf("a(%d) + b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 - temp2).value;
    printf("a(%d) - b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 * temp2).value;
    printf("a(%d) x b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 / temp2).value;
    printf("a(%d) ÷ b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 = temp2).value;
    printf("a(%d) = b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 != temp2).value;
    printf("a(%d) != b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 << temp2).value;
    printf("a(%d) << b(%d) =%d\n", temp1.value, temp2.value, value);
    value = (temp1 >> temp2).value;
    printf("a(%d) >> b(%d) =%d\n", temp1.value, temp2.value, value);

    MyA temp3(5);
    temp3++;
    printf("自增\n", temp1.value, temp2.value, value);

    return 0;
}