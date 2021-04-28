//请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
//
//本题含有多组样例输入。
//输入描述 :
//每组样例输入两个正整数n和m，用空格隔开。(1≤n, m≤8)
//
//输出描述 :
//	 每组样例输出一行结果
//
//	 示例1
//
//	 输入
//	 2 2
//	 1 2
//
//	 输出
//	 6
//	 3

 //牛客题目链接:https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tab=answerKey

#include<iostream>
#include<algorithm>
using namespace std;
int maxways(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 1;
	}
	return maxways(m - 1, n) + maxways(m, n - 1);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		

		int ways = 1;
		//方法一:排列组合
		//设右下目标点为原点(0,0),起点为（n，m）。
		//一共走m+n步，当走到下边（x，0）或右边（0，y）的时候，只能沿一个方向走。
		//也就是说，C（m+n，m）或C（m+n，n）。高中数学，这俩组合值其实相等。
		/*
		for(int i=0;i<m;i++)
		{
		ways*=(m+n)-i;
		}
		for(int i=1;i<=m;i++)
		{
		ways/=i;
		}*/

		//======================================================
		//方法二：递归
		ways = maxways(m, n);
		//======================================================
		cout << ways << endl;
	}
	return 0;
}