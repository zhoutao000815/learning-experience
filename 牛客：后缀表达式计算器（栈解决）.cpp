//链接：https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
//来源：牛客网
//
//Emacs计算器
//
//Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 + ”等价于中缀表达式的“2 + 3”。
//请你实现一个后缀表达式的计算器。
//
//输入描述 :
//输入包含多组数据。
//
//每组数据包括两行：第一行是一个正整数n(3≤n≤50)；紧接着第二行包含n个由数值和运算符组成的列表。
//
//“ + -*/ ”分别为加减乘除四则运算，其中除法为整除，即“5 / 3 = 1”。
//
//
//输出描述 :
//对应每一组数据，输出它们的运算结果。
//示例1
//输入
//3
//2 3 +
//5
//2 2 + 3 *
//5
//2 2 3 + *
//输出
//5
//12
//10

#include<bits/stdc++.h>
using namespace std;

int calculator(string method, int left, int right)
{
	long res;
	switch (method[0])
	{
	case '+':
		res = left + right;
		break;
	case '-':
		res = left - right;
		break;
	case '*':
		res = left*right;
		break;
	case '/':
		//假设不会出现除0错误。
		res = left / right;
		break;
	default:
		cout << "输入有误！" << endl;
		break;
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n)
	{
		stack<long> sc;
		while (n--)
		{
			string tmp;
			cin >> tmp;
			if (tmp[0] >= '0' && tmp[0] <= '9')
			{
				long in = 0;
				for (int i = 0; i<tmp.size(); i++)
				{
					in = in * 10 + (tmp[i] - '0');
				}
				sc.push(in);
			}
			else
			{
				long right = sc.top();
				sc.pop();
				long left = sc.top();
				sc.pop();
				sc.push(calculator(tmp, left, right));
			}
		}
		cout << sc.top() << endl;
		sc.pop();
	}
	return 0;
}