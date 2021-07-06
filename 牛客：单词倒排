//链接：https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836
//来源：牛客网
//
//单词倒排
//热度指数：223443时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//对字符串中的所有单词进行倒排。
//
//说明：
//
//1、构成单词的字符只有26个大写或小写英文字母；
//
//2、非构成单词的字符均视为单词间隔符；
//
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//
//4、每个单词最长20个字母；
//
//
//输入描述 :
//输入一行以空格来分隔的句子
//
//
//
//输出描述 :
//输出句子的逆序
//
//示例1
//输入
//I am a student
//输出
//student a am I
//示例2
//输入
//$bo*y gi!r#l
//输出
//l r gi y bo

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		string res;
		size_t pos = str.size();
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i]<'A' || (str[i]>'Z' && str[i]<'a') || str[i]>'z')
			{
				res += string(str.begin() + i + 1, str.begin() + pos);
				res += ' ';
				pos = i;
			}
		}
		res += string(str.begin(), str.begin() + pos);          //第一个单词前面没有非字母，手动添加。
		cout << res << endl;
	}
	return 0;
}