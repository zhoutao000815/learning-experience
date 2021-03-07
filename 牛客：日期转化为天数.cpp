//校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
//题目描述
//根据输入的日期，计算是这一年的第几天。。
//
//测试用例有多组，注意循环输入
//
//输入描述 :
//输入多行，每行空格分割，分别是年，月，日
//
//输出描述 :
//成功 : 返回outDay输出计算后的第几天;
//失败:返回 - 1
//
//	示例1
//	输入
//	2012 12 31、
//
//	输出
//	366

//题目链接：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&tqId=21296&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tab=answerKey
//用之前写的日期类解决
#include<iostream>
using namespace std;
class Date{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			day++;
		}
		return day;
	}
	// 全缺省的构造函数
	Date(int year, int month, int day)
	{
		if (year<1900 || month<1 || month>12 || day > GetMonthDay(year, month) || day < 0)
		{
			cout << "输入错误！" << endl;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	// 日期+=天数
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}
	// >运算符重载
	bool operator>(const Date& d)
	{
		//排除法
		if (this->_year < d._year)
		{
			return false;
		}
		if (this->_month < d._month && this->_year == d._year)
		{
			return false;
		}
		if (this->_day < d._day && this->_month == d._month && this->_year == d._year)
		{
			return false;
		}
		if (this->_day == d._day && this->_month == d._month && this->_year == d._year)
		{
			return false;
		}
		return true;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		if (this->_year == d._year && this->_month == d._month && this->_day == d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		if (*this > d || *this == d)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// <运算符重载
	bool operator < (const Date& d)
	{
		if (*this >= d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int count = 0;
		while ((Date)d > *this + count)
		{
			count++;
		}
		while ((Date)d + count < *this)
		{
			count++;
		}
		printf("%d\n", count);
		return count;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	int year_, month_, day_;
	while (cin >> year_ >> month_ >> day_)
	{
		Date d1(year_, month_, day_);
		Date d2(year_, 1, 1);
		int rel = 0;
		while (d1 >= d2 + rel)//求的是第几天，比如2012 01 01这是第一天！所以>=
		{
			rel++;
		}
		cout << rel << endl;
	}
	return 0;
}


//参考别人的答案写的简化版
#include<iostream>
using namespace std;
// 获取某年某月的天数
int GetMonthDay(int year, int month)
{
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		day++;
	}
	return day;
}
int main()
{
	int year_, month_, day_;
	while (cin >> year_ >> month_ >> day_)
	{
		int rel = 0;
		while (--month_>0)//前置--，rel先加前面月份天数和，最后加上当月天数即可。
		{
			rel += GetMonthDay(year_, month_);
		}
		cout << rel + day_ << endl;
	}
	return 0;
}
