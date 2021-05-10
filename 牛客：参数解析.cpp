//链接：https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
//来源：牛客网
//
//参数解析
//热度指数：58546时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//在命令行输入如下命令：
//
//xcopy / s c : \ d : \，
//
//各个参数如下：
//
//参数1：命令字xcopy
//
//参数2：字符串 / s
//
//参数3：字符串c : \
//
//	   参数4 : 字符串d : \
//
//			 请编写一个参数解析程序，实现将命令行各个参数解析出来。
//
//
//			 解析规则：
//
//			 1.参数分隔符为空格
//			 2.对于用""包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s "C:\program files" "d:\"时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将""去掉，引号不存在嵌套情况。
//			 3.参数不定长
//			 4.输入由用例保证，不会出现不符合要求的输入
//
//
//
//		 输入描述 :
//输入一行字符串，可以有空格
//
//
//
//输出描述 :
//输出参数个数，分解后的参数，每个参数都独占一行
//
//示例1
//输入
//xcopy / s c : \\ d:\\
//输出
//4
//xcopy
/// s
//c : \\
//d:\\
//


#include<iostream>
#include<string>
#include<vector>
  using namespace std;

vector<string> args;

void get(string &str)
{
	string tmp;
	bool flag = false;  //用来标记是否出现  “
	for (size_t i = 0; i<str.size(); i++)
	{
		if (flag)
		{
			if (str[i] != '\"')  //转义字符
				tmp += str[i];
			else
				flag = false;
		}
		else
		{
			if (str[i] == ' ')
			{
				args.push_back(tmp);
				tmp = "";
			}
			else if (str[i] == '\"')
			{
				flag = true;
			}
			else
			{
				tmp += str[i];
			}
		}
	}
	args.push_back(tmp);
}

void printf()
{
	cout << args.size() << endl;
	for (int i = 0; i<args.size(); i++)
	{
		cout << args[i] << endl;
	}
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		get(str);
		printf();
	}
}