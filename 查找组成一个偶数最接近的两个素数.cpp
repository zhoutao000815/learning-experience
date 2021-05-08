//链接：https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
//来源：牛客网
//
//[编程题]查找组成一个偶数最接近的两个素数
//热度指数：51931时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。
//本题含有多组样例输入。
//
//输入描述 :
//输入一个偶数
//
//
//
//输出描述 :
//输出两个素数
//
//示例1
//输入
//20
//输出
//7
//13

#include<iostream>
using namespace std;

bool is_su_shu(int num) //确定一个数字是不是素数
{
	int flag = 2;
	while (flag < num >> 1)
	{
		if (num%flag == 0)
		{
			return false;
		}
		flag++;
	}
	return true;
}

int get_only_num(int num)
{
	int num1 = num;
	int num2 = num;
	while (!is_su_shu(num1) || !is_su_shu(num2))//注意：需要两个组成数都是素数才可以。只要有其中一个不是，都要继续
	{
		num1--;
		num2++;
	}
	return num1;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int rel1;
		rel1 = get_only_num(num >> 1); //求差值最小的，所以从中间开始求。
		cout << rel1 << endl;
		cout << num - rel1 << endl;
	}
	return 0;
}