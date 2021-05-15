//链接：https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036
//来源：牛客网
//
//字符串通配符
//热度指数：44689时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：
//实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）
//？：匹配1个字符
//
//
//输入：
//通配符表达式；
//一组字符串。
//
//
//输出：
//
//返回匹配的结果，正确输出true，错误输出false
//
//本题含有多组样例输入！
//
//输入描述 :
//先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
//
//
//
//输出描述 :
//返回匹配的结果，正确输出true，错误输出false
//
//示例1
//输入
//te ? t*.*
//txt12.xls
//输出
//false

#include<iostream>
#include<string>
using namespace std;

void IsSame(string &std, string &s2)
{
	size_t i, j;
	for (i = 0, j = 0; i<std.size() && j<s2.size(); i++, j++)
	{
		if (std[i] == '?')
		{
			continue;
		}
		else if (std[i] == '*')
		{
			string tmp;
			size_t pos;
			while (i<std.size() && std[i] != '*' && std[i] != '?')
			{
				tmp += std[i];
				i++;
			}
			if ((pos = s2.find(tmp, j)) == string::npos)
			{
				cout << "false" << endl;
				return;
			}
			else
			{
				j = pos;
				j += tmp.size();
			}
		}
		else
		{
			if (std[i] == s2[j])
				continue;
			else
				cout << "false" << endl;
			return;
		}
	}
	if (i == std.size() || (i == std.size() - 1 && std[i] == '*'))  //std走完，或者走到最后一个为*，但是s2没了。都是真。
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		IsSame(s1, s2);
	}
	return 0;
}