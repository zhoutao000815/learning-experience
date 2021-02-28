#include"Date.h"

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month==2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		day++;
	}
	return day;
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	if (year<1900 || month<1 || month>12 || day > GetMonthDay(year, month) || day < 0)
	{
		cout << "输入错误！" << endl;
	}
	_year = year;
	_month = month;
	_day = day;
}

// 拷贝构造函数
// d2(d1)
Date:: Date(const Date& d)
{
	this->_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

// 析构函数
Date::~Date()
{
	//清理步骤，malloc和new的才需要清理，系统自动清理其他。
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
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
Date Date::operator+(int day)
{
	//逻辑冗杂繁复，多注意复用性！
	/*Date ret(*this);
	ret._day += day;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month == 13)
		{
			ret._year++;
			ret._month = 1;
		}
	}
	return ret;*/

	Date ret(*this);
	ret += day;
	return ret;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

//为了区分前置和后置，进行了函数重载，后置函数参数加了一个int
// 前置++
Date& Date::operator++()
{
	this->_day += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date temp(*this);
	this->_day += 1;
	return temp;
}

// 后置--
Date Date::operator--(int)
{
	Date temp(*this);
	this->_day -= 1;
	return temp;
}

// 前置--
Date& Date::operator--()
{
	this->_day -= 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	//第一种判断方法：排除法
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

	//第二种判断方法：条件确认法
	/*if (_year > d._year)
	{
	return true;
	}
	else if (_year == d._year)
	{
	if (_month > d._month)
	{
	return true;
	}
	else if (_month == d._month)
	{
	if (_day > d._day)
	{
	return true;
	}
	}
	}
	return false;*/
}

// ==运算符重载
bool Date::operator==(const Date& d)
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
inline bool Date::operator >= (const Date& d)
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
bool Date::operator < (const Date& d)
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

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	if (*this > d)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	if (*this == d)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int count = 0;
	while ((Date)d > *this+count)
	{
		count++;
	}
	while ((Date)d + count < *this)
	{
		count++;
	}
	printf("相差%d天\n", count);
	return count;
}