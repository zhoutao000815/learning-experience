//题目描述
//计算字符串最后一个单词的长度，单词以空格隔开。
//
//输入描述 :
//输入一行，代表要计算的字符串，非空，长度小于5000。
//
//输出描述 :
//输出一个整数，表示输入字符串最后一个单词的长度。
//
//示例1
//输入
//复制
//hello nowcoder
//输出
//复制
//8
//牛客链接：https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&rp=5&ru=%2Factivity%2Foj&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tab=answerKey
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	// 不要使用cin>>line,因为会它遇到空格就结束了
	// while(cin>>line)
	while (getline(cin, s))
	{
		size_t pos = s.rfind(' ');
		if (pos == string::npos)
		{
			cout << s.size() << endl;
		}
		else
		{
			cout << s.size() - pos - 1 << endl;
		}
	}
	return 0;
}