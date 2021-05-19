//链接：https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
//来源：牛客网
//
//MP3光标位置
//热度指数：35488时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。
//
//
//现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：
//
//歌曲总数 <= 4的时候，不需要翻页，只是挪动光标位置。
//
//光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。
//
//
//
//其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。
//
//
//
//2. 歌曲总数大于4的时候（以一共有10首歌为例）：
//
//
//特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，屏幕要显示最后一页（即显示第7 - 10首歌），同时光标放到最后一首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。
//
//
//
//一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似。
//
//
//
//其他情况，不用翻页，只是挪动光标就行。
//
//
//
//输入描述 :
//输入说明：
//1 输入歌曲数量
//2 输入命令 U或者D
//
//本题含有多组输入数据！
//
//
//
//
//输出描述 :
//输出说明
//1 输出当前列表
//2 输出当前选中歌曲
//
//示例1
//输入
//10
//UUUU
//输出
//7 8 9 10
//7
//
根据歌曲数量，创建歌曲列表，
根据歌曲数量（大于4首，还是小于等于4首）创建MP3显示列表，确定光标位置。
利用光标在显示列表里的位置，确定翻页动作（翻页分两类：1.跳页，2.翻页）。

#include<bits/stdc++.h>
using namespace std;

void get(vector<int> &v, string &str)
{
	vector<int> out;  //mp3的显示器列表
	if (v.size()>4)
	{
		vector<int> tmp(v.begin(), v.begin() + 4);
		out.swap(tmp);
	}
	else
	{
		vector<int> tmp(v.begin(), v.end());
		out.swap(tmp);
	}
	int flag = 0;   //光标位置

	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == 'U')
		{
			flag--;
			if (flag == -1)  //向上翻页
			{
				if (out[flag + 1] == v[0])//上翻到顶，转最后一首歌的那一页
				{
					vector<int> tmp(v.end() - out.size(), v.end());
					flag = out.size() - 1;  //光标归位
					out.swap(tmp);
				}
				else  //没有上翻到顶，上移一格即可
				{
					for (int j = 0; j<out.size(); j++) //上移一格
					{
						out[j]--;
					}
					flag = 0;  //光标归位
				}
			}
		}
		if (str[i] == 'D')
		{
			flag++;
			if (flag == out.size())  //向下翻页
			{
				if (out[flag - 1] == v[v.size() - 1])  //下翻到底，转第一首歌那一页
				{
					vector<int> tmp(v.begin(), v.begin() + out.size());
					flag = 0;
					out.swap(tmp);
				}
				else
				{
					for (int j = 0; j<out.size(); j++)
					{
						out[j]++;
					}
					flag = out.size() - 1;   //光标归位
				}
			}
		}
	}
	for (int j = 0; j<out.size(); j++)
	{
		cout << out[j] << " ";
	}
	cout << endl;
	cout << out[flag];
	cout << endl;
}

int main()
{
	int musicsize;
	string str;
	while (cin >> musicsize >> str)
	{
		vector<int> v(musicsize, 0); //歌曲列表
		for (int i = 0; i<v.size(); i++)
		{
			v[i] = i + 1;
		}
		get(v, str);
	}
	return 0;
}