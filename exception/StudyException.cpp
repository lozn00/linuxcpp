#include <iostream>
#include <exception>
using namespace std;
struct MyException : public exception
{
	const char *echoException()
	{
		//		const char * echoException() const throw(){//wufa lijie zhe juhua
		return "My exception";
	}
	//reload method
	const char *what()
	{

		return "re load??";
	}
};

class MyException1
{
  private:
	const char *_message;

  public:
	MyException1(const char *message) : _message(message)
	{
		//	this->_message=message;
		(*this)._message = message;
	}
	MyException1(const MyException1 &other) : _message(other._message)
	{
		cout << "Copy MyException ..." << endl;
	}

	const char *getMesage()
	{
		return (*this)._message;
	}
};
int division(int a, int b)
{
	if (b == 0 || a == 0)
	{
		throw "cannot / 0";
	}
	else
	{
		return b / a;
	}
}
int main()
{
	cout << "wellcome study exception \n";
	try
	{
		cout << "will throw exception" << endl;
		throw MyException();
		cout << " normal " << endl;
	}
	catch (MyException e)
	{

		cout << " exectipn try ->" << e.echoException() << "what : " << e.what() << endl;
	}
	try
	{
		int a;
		cout << "please enter a number \n";
		cin >> a;
		int result = division(a, 10);
		cout << "calc result \n"
			 << result << endl;
	}
	catch (const char *msg)
	{
		cout << "catch exception :" << msg << endl;
	}

	try
	{
		throw MyException1("test exception");
	}
	catch (MyException1 e)
	{
		cout << "crach custom exception " << e.getMesage() << endl;
	}
}

//ctrl +b  run
//ctrl +shift+p open command

/**
	this names of class and ctract can't be the same so i define MyException1 not defined MyException
**/
