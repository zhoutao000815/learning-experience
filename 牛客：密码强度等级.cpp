//链接：https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361
//来源：牛客网
//
//[编程题]密码强度等级
//热度指数：52922时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
//
//一、密码长度 :
//
//5 分 : 小于等于4 个字符
//
//10 分 : 5 到7 字符
//
//25 分 : 大于等于8 个字符
//
//二、字母 :
//
//0 分 : 没有字母
//
//10 分 : 全都是小（大）写字母
//
//20 分 : 大小写混合字母
//
//三、数字 :
//
//0 分 : 没有数字
//
//10 分 : 1 个数字
//
//20 分 : 大于1 个数字
//
//四、符号 :
//
//0 分 : 没有符号
//
//10 分 : 1 个符号
//
//25 分 : 大于1 个符号
//
//五、奖励 :
//
//2 分 : 字母和数字
//
//3 分 : 字母、数字和符号
//
//5 分 : 大小写字母、数字和符号
//
//最后的评分标准 :
//
//>= 90 : 非常安全
//
//>= 80 : 安全（Secure）
//
//>= 70 : 非常强
//
//>= 60 : 强（Strong）
//
//>= 50 : 一般（Average）
//
//>= 25 : 弱（Weak）
//
//>= 0 : 非常弱
//
//
//对应输出为：
//
//VERY_SECURE
//
//SECURE,
//
//VERY_STRONG,
//
//STRONG,
//
//AVERAGE,
//
//WEAK,
//
//VERY_WEAK,
//
//
//请根据输入的密码字符串，进行安全评定。
//
//注：
//
//字母：a - z, A - Z
//
//数字： - 9
//
//符号包含如下：(ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
//
//!"#$%&'()*+,-./     (ASCII码：x21~0x2F)
//
//:; <= > ? @             (ASCII <= > <= > <= > <= > <= >码：x3A~0x40)
//
//[\] ^ _`              (ASCII码：x5B~0x60)
//
//{
//	|
//}~(ASCII码：x7B~0x7E)
//
//
//输入描述:
//本题含有多组输入样例。
//每组样例输入一个string的密码
//
//输出描述 :
//每组样例输出密码等级
//
//示例1
//输入
//38$@NoNoNo
//123
//输出
//VERY_SECURE
//WEAK
//说明
//第一组样例密码强度为95分。
//第二组样例密码强度为25分。
//
//
//
#include<iostream>
#include<string>
using namespace std;
void gardenlevel(int goal)
{
	if (goal >= 0 && goal<25)
	{
		cout << "VERY_WEAK" << endl;
	}
	else if (goal >= 25 && goal<50)
	{
		cout << "WEAK" << endl;
	}
	else if (goal >= 50 && goal<60)
	{
		cout << "AVERAGE" << endl;
	}
	else if (goal >= 60 && goal<70)
	{
		cout << "STRONG" << endl;
	}
	else if (goal >= 70 && goal<80)
	{
		cout << "VERY_STRONG" << endl;
	}
	else if (goal >= 80 && goal<90)
	{
		cout << "SECURE" << endl;
	}
	else if (goal >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
}

bool IsSum(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	return false;
}
bool IsBig(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return true;
	}
	return false;
}
bool IsSmall(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return true;
	}
	return false;
}

void GetPwdSecurityLevel(string& pPasswordStr)
{
	int goal = 0;

	//长度得分
	if (pPasswordStr.size() <= 4)
	{
		goal += 5;
	}
	else if (pPasswordStr.size() <= 7 && pPasswordStr.size()>4)
	{
		goal += 10;
	}
	else
	{
		goal += 25;
	}

	bool small = false;//小写字母
	bool big = false;//大写字母

	int sumsize = 0; //数字个数

	int flag = 0;  //符号个数

	//统计
	for (int i = 0; i<pPasswordStr.size(); i++)
	{
		if (IsBig(pPasswordStr[i]))
		{
			small = true;
			continue;
		}
		if (IsSmall(pPasswordStr[i]))
		{
			big = true;
			continue;
		}
		if (IsSum(pPasswordStr[i]))
		{
			sumsize++;
			continue;
		}
		flag++;
	}

	//字母得分
	if (big || small)
	{
		if (big && small)
		{
			goal += 10;
		}
		goal += 10;
	}

	//数字个数得分
	if (sumsize == 1)
	{
		goal += 10;
	}
	if (sumsize>1)
	{
		goal += 20;
	}

	//符号个数得分
	if (flag == 1)
	{
		goal += 10;
	}
	if (flag>1)
	{
		goal += 25;
	}

	//奖励得分
	if (big && small && sumsize && flag)
	{
		goal += 5;
	}
	else if ((big || small) && sumsize && flag)
	{
		goal += 3;
	}
	else if ((big || small) && sumsize)
	{
		goal += 2;
	}

	//输出
	gardenlevel(goal);
}

int main()
{
	string str;
	while (cin >> str)
	{
		GetPwdSecurityLevel(str);
	}
	return 0;
}