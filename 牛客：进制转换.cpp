//链接：https://www.nowcoder.com/questionTerminal/ac61207721a34b74b06597fe6eb67c52
//来源：牛客网
//
//[编程题]进制转换
//热度指数：25366时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//
//输入描述 :
//输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
//
//
//输出描述 :
//为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
//示例1
//输入
//7 2
//输出
//111
 
很明显，输出的数有各种进制，计算机只有10进制类型的整数，所以输出是一个字符串。

思路:相除取余，余数是从低到高取的，用字符串尾插余数，最后逆置即可。

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string tmp = "0123456789ABCDEF";
//	int M, N;
//	cin >> M >> N;
//	int flag = 1;
//	if (M<0)  //负数记录标志
//	{
//		flag = -1;
//		M *= -1;
//	}
//	string ret;
//	while (M)
//	{
//		int k = M%N;
//		ret += tmp[k];
//		M = M / N;
//	}
//	if (flag == -1)
//	{
//		ret += '-';
//	}
//	reverse(ret.begin(), ret.end());
//	cout << ret;
//	return 0;
//}