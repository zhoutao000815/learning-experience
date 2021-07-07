//链接：https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32
//来源：牛客网
//
//乒乓球筐
//热度指数：2742时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？
//
//输入描述 :
//输入有多组数据。
//每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，即相同类型的乒乓球为相同的大写字母。
//字符串长度不大于10000。
//
//
//输出描述 :
//每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
//示例1
//输入
//ABCDFYE CDE<br / >ABCDGEAS CDECDE
//输出
//Yes<br / >No


#include<bits/stdc++.h>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		map<char, int> AM;
		for (auto &e : A)
		{
			AM[e]++;
		}

		map<char, int> BM;
		for (auto &e : B)
		{
			BM[e]++;
		}
		bool flag = true;
		for (auto &e : B)
		{
			if (AM[e]<BM[e])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}