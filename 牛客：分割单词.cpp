//链接：https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800?toCommentId=9308433
//来源：牛客网
//
//NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
//现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
//
//输入描述 :
//输入有多组数据，每组数据有两行。
//
//第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。
//
//第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
//
//
//输出描述 :
//如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
//示例1
//输入
//Joe, Kewell, Leon
//Joe
//"Letendre, Bruce", Joe, "Quan, William"
//William
//输出
//Ignore
//Important!


//直接分割列表，拿分割出的单词与name进行对比，相同就输出Ignore，不同就下一个单词，直到结束输出Important!，
// write your code here cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str, name;
	while (getline(cin, str))
	{
		getline(cin, name);
		string temp;
		bool find = false;
		for (int i = 0; i<str.size(); i++)
		{
			if (str[i] == '\"') //带"的名字
			{
				temp = str.substr(i + 1, str.find('\"', i + 1) - i - 1);
				i += temp.size() + 1 + 1;
			}
			else             //没有"的名字
			{
				temp = str.substr(i, str.find(',', i) - i - 1);
				i += temp.size() + 1;
			}
			if (temp == name)  //判断当前单词是否相等name
			{
				find = true;
				cout << "Ignore" << endl;
				break;
			}
			temp.clear();
		}
		if (!find)
		{
			cout << "Important!" << endl;
		}
	}
}