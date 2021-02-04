#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 这里会发现下面的程序会崩溃掉？这里就需要我们以后学的深拷贝去解决。

//拷贝构造浅拷贝引起的问题
class String
{
public:
	String(const char* str = "jack")  //全省构造函数是默认构造函数。
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
// 默认构造函数重复的问题
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
}
int main()
{
	String s1("hello");
	String s2(s1);
}

//你会发现会报了，出现一个断点的崩溃，为什么呢？
//编译器自动生成的默认拷贝构造函数，只是拷贝值，s2拷贝了s1的值，s1储存的是字符串的地址，那拷贝完后，s1、s2，都指向了同一个字符串地址.
//释放的时候调用析构函数~，释放s2，s1，重复释放，崩溃。
//注意：由于函数在(虚拟内存)-栈上运行，栈先进后出，后进先出。所以，s1，s2的顺序如下。
//创建s1，创建s2，释放s2，释放s1。