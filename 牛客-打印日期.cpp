//时间限制：C / C++ 1秒，其他语言2秒 空间限制：C / C++ 64M，其他语言128M 热度指数：18432
//本题知识点： 模拟
//算法知识视频讲解
//校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
//题目描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述 :
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述 :
//可能有多组测试数据，对于每组数据，
//按 yyyy - mm - dd的格式将输入中对应的日期打印出来。
//
//示例1
//
//输入
//2000 3
//2000 31
//2000 40
//2000 60
//2000 61
//2001 60
//
//输出
//2000 - 01 - 03
//2000 - 01 - 31
//2000 - 02 - 09
//2000 - 02 - 29
//2000 - 03 - 01
//2001 - 03 - 01
//链接:https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&tqId=29669&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fhust-kaoyan%2Fquestion-ranking&tab=answerKey

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
	int year, days;
	while (cin >> year >> days)
	{
		int month = 1, day = days;
		while (day>GetMonthDay(year, month))
		{
			day -= GetMonthDay(year, month);
			month++;
		}
		cout << year << "-";
		if (month<10)
		{
			cout << "0";
		}
		cout << month;
		cout << "-";
		if (day<10)
		{
			cout << "0";
		}
		cout << day << endl;
	}
	return 0;
}