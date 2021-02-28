#include"Date.h"

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

// ��ȡĳ��ĳ�µ�����
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

// ȫȱʡ�Ĺ��캯��
Date::Date(int year, int month, int day)
{
	if (year<1900 || month<1 || month>12 || day > GetMonthDay(year, month) || day < 0)
	{
		cout << "�������" << endl;
	}
	_year = year;
	_month = month;
	_day = day;
}

// �������캯��
// d2(d1)
Date:: Date(const Date& d)
{
	this->_year = d._year;
	_month = d._month;
	_day = d._day;
}

// ��ֵ���������
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

// ��������
Date::~Date()
{
	//�����裬malloc��new�Ĳ���Ҫ����ϵͳ�Զ�����������
}

// ����+=����
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

// ����+����
Date Date::operator+(int day)
{
	//�߼����ӷ�������ע�⸴���ԣ�
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

// ����-����
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

// ����-=����
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

//Ϊ������ǰ�úͺ��ã������˺������أ����ú�����������һ��int
// ǰ��++
Date& Date::operator++()
{
	this->_day += 1;
	return *this;
}

// ����++
Date Date::operator++(int)
{
	Date temp(*this);
	this->_day += 1;
	return temp;
}

// ����--
Date Date::operator--(int)
{
	Date temp(*this);
	this->_day -= 1;
	return temp;
}

// ǰ��--
Date& Date::operator--()
{
	this->_day -= 1;
	return *this;
}

// >���������
bool Date::operator>(const Date& d)
{
	//��һ���жϷ������ų���
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

	//�ڶ����жϷ���������ȷ�Ϸ�
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

// ==���������
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

// >=���������
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

// <���������
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

// <=���������
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

// !=���������
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

// ����-���� ��������
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
	printf("���%d��\n", count);
	return count;
}