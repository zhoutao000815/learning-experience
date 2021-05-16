//链接：https://www.nowcoder.com/questionTerminal/210741385d37490c97446aa50874e62d
//来源：牛客网
//
//最长公共子串
//热度指数：5071时间限制：C / C++ 2秒，其他语言4秒空间限制：C / C++ 256M，其他语言512M
//算法知识视频讲解
//给定两个字符串str1和str2, 输出两个字符串的最长公共子串，如果最长公共子串为空，输出 - 1。
//
//输入描述 :
//输入包括两行，第一行代表字符串srr1，第二行代表字符串str2。\left(1\leq length(str1), length(str2) \leq 5000 \right)(1≤length(str1), length(str2)≤5000)
//
//
//输出描述:
//输出包括一行，代表最长公共子串。
//示例1
//输入
//1AB2345CD
//12345EF
//输出
//2345


#include<bits/stdc++.h>
using namespace std;

void get_max_sub_str(string &s1, string &s2)
{
	if (s1.size()>s2.size())
	{
		s1.swap(s2);
	}
	string rel;
	for (int i = 0; i<s1.size(); i++)
	{
		string tmp;
		int icopy = i;
		for (int j = 0; j<s2.size() && i<s1.size(); j++)
		{
			int jcopy = j;
			while (s1[i] == s2[j] && j<s2.size() && i<s1.size())
			{
				tmp += s1[i];
				i++;
				j++;
			}
			i = icopy;
			j = jcopy;
			if (tmp.size()>rel.size())
			{
				rel = tmp;
			}
			tmp.clear();
		}

	}
	if (rel.empty())
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << rel << endl;
	}
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		get_max_sub_str(s1, s2);
	}
	return 0;
}