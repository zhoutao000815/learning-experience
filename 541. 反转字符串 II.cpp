//
//541. 反转字符串 II
//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
//
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//
//
//示例 :
//
//输入 : s = "abcdefg", k = 2
//输出 : "bacdfeg"
//
//
//
//
//	  来源：力扣（LeetCode）
//  链接：https ://leetcode-cn.com/problems/reverse-string-ii
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//正确通过oj的代码
class Solution {
public:
	string reverseStr(string s, int k) {
		int size = s.size();
		int IsReverse = 1;
		string::iterator begin = s.begin();
		while (size >= k)
		{
			string::iterator kend = begin;
			for (int i = 0; i<k; i++)
			{
				kend++;
			}
			if (IsReverse % 2)       //余数为1，说明为奇数，需要逆置。
			{
				std::reverse(begin, kend);
			}
			size -= k;
			begin += k;
			IsReverse++;
		}
		string::iterator end = s.end();
		if (IsReverse % 2)           // size<k,而且是奇数组别
		{
			std::reverse(begin, end);
		}
		return s;
	}
};


//=================================================================================================================
//以下为测试代码，不解其原因，据推测可能与迭代器的返回值，或者迭代器不支持一次走多步有关，待我知其所以然再补充
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//		string reverseStr(string s, int k) {
//			int size = s.size();
//			int IsReverse = 1;
//			string::iterator begin = s.begin();
//			while (size >= k)
//			{
//				if (IsReverse % 2)       //余数为1，说明为奇数，需要逆置。
//				{
//					std::reverse(begin, begin + k - 1);     //错误写法， begin + k - 1 没有起到作用，虽然编译通过了。
//				}
//				size -= k;
//				begin += k;
//				IsReverse++;
//			}
//			string::iterator end = s.end();
//			if (IsReverse % 2)           // size<k,而且是奇数组别
//			{
//				std::reverse(begin, end);
//			}
//			return s;
//		}
//};
//int main()
//{
//	Solution d;
//	string s = "abcdefg";
//	d.reverseStr(s, 2);
//
//	return 0;
//}