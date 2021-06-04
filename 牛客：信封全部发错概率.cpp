﻿//链接：https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
//来源：牛客网
//
//年会抽奖
//热度指数：3482时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
//1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
//2. 待所有字条加入完毕，每人从箱中取一个字条；
//3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
//现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？
//
//输入描述 :
//输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
//
//
//输出描述 :
//对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率。
//示例1
//输入
//2
//输出
//50.00%

//
//解这道题，我们需要明白什么时候才算做都不获奖？全部都不获奖的概率如何计算？
//对于什么时候才算做都不获奖，当然是所有人都拿到了别人的名字，没有拿到自己的名字。
//全部都不获奖的概率必定是由 n个人都拿错的情况种数 除 n个人拿出的所有排列情况数。
//n个人拿出的所有排列情况数显然是n的阶乘。
//n个人都拿错的情况种数与上一道题 PAT乙级(Basic Level)练习题 发邮件 是一样的。
//假设a的名字没有被a拿到，其他n - 1个人都有可能拿到，即有n - 1种情况。假设b拿到了a的名字，那么对于b的名字有两种情况，
//
//第一种是b的名字被a拿到了，也就是a、b互相拿到了对方的名字，那么对于其他n - 2个人互相拿错又是一个子问题f(n - 2).
//
//第二种是b的名字没有被a拿到，则剩下的问题是子问题f(n - 1).
//因此可得递推公式f(n) = (n - 1) * (f(n - 1) + f(n - 2)).
//
//最终得出公式n人都不获奖的概率:h(n) = f(n) / (n!).
//最终得出公式n人都不获奖的概率:h(n) = (n - 1) * (f(n - 1) + f(n - 2))    /    (n!).


#include<stdio.h>
int main()
{
	long long d[21] = { 0, 0, 1 };
	long long f[21] = { 0, 1, 2 };
	for (int i = 3; i <= 20; ++i)
	{
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
		f[i] = f[i - 1] * i;
	}
	int n;
	while (~scanf("%d", &n))
	{
		printf("%.2f%c\n", 1.0*d[n] / f[n] * 100, '%');
	}
	return 0;
}