//题目描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//输入描述 :
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//输出描述 :
//每组数据输出一行，即日期差值
//
//示例1
//输入
//20110412
//20110422
//
//输出
//11
//链接:https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&tqId=29468&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fsju-kaoyan%2Fquestion-ranking&tab=answerKey
#include<iostream>
#include<string.h>
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
//int 数组，每个数组三个元素，顺序为年-月-日。
void days(int *bigDate, int *smallDate)
{
	int rel = 0;
	while (bigDate[0] != smallDate[0] || bigDate[1] != smallDate[1] || bigDate[2] != smallDate[2])
	{
		smallDate[2]++;
		rel++;
		if (smallDate[2]>GetMonthDay(smallDate[0], smallDate[1]))
		{
			smallDate[2] = 1;  //由于是一天一天加的所以只会超出1天。
			smallDate[1]++;
			if (smallDate[1] == 13)
			{
				smallDate[1] = 1;
				smallDate[0]++;
			}
		}
	}
	cout << rel + 1 << endl;  //连续时为两天，所以+1
}
int main()
{
	int s1, s2;
	int bigDate[3];
	int smallDate[3];
	while (cin >> s1 >> s2)
	{
		int rel = s1 - s2;
		if (rel>0)
		{
			//默认s1是大的日期，不作处理
		}
		else if (rel<0)
		{
			//s1小的话，交换。
			int temp;
			temp = s1;
			s1 = s2;
			s2 = temp;
		}
		else  //==0
		{
			cout << "1" << endl;
			continue;
		}
		bigDate[0] = s1 / 10000;  //年
		bigDate[1] = (s1 / 100) % 100;  //月
		bigDate[2] = s1 % 100; //日
		smallDate[0] = s2 / 10000;
		smallDate[1] = (s2 / 100) % 100;
		smallDate[2] = s2 % 100;
		days(bigDate, smallDate);
	}
	return 0;
}