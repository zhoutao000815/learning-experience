//链接：https://www.nowcoder.com/questionTerminal/98dc82c094e043ccb7e0570e5342dd1b
//来源：牛客网
//
//公共子串计算
//热度指数：69766时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。
//
//注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。
//
//
//输入描述 :
//输入两个只包含小写字母的字符串
//
//
//
//输出描述 :
//输出一个整数，代表最大公共子串的长度
//
//示例1
//输入
//asdfas
//werasdfaswer
//输出
//6

#include<bits/stdc++.h>
using namespace std;

int getCommonStrLength(string &s1, string &s2)
{
	if (s1.size()>s2.size())
		s1.swap(s2);
	int maxsamelength = 0;
	for (int i = 0; i<s1.size(); i++)       //长度较小的字符串
	{
		int icopy = i;
		int left = 0, right = 0;
		while (icopy<s1.size() && right<s2.size()) //滑动窗口确定最大值
		{
			if (s1[icopy] != s2[right] && left == right)  //情况一
			{
				left++;
				right++;
			}
			else if (s1[icopy] == s2[right])          //情况二
			{
				icopy++;
				right++;
				maxsamelength = max(maxsamelength, right - left);
			}
			else
				//(s1[icopy]!=s2[right] && left！=right) 与情况一不同，虽然都不相等，但是当前right可能和i相同。
			{
				icopy = i;
				left = right;
			}
		}
		//这里应该增加回溯剪枝，如果maxsamelength==s1.size（）就直接退出。
	}
	return maxsamelength;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << getCommonStrLength(s1, s2) << endl;
	}
	return 0;
}