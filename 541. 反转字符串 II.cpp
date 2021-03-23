//
//541. ��ת�ַ��� II
//����һ���ַ��� s ��һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת��
//
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
//
//
//ʾ�� :
//
//���� : s = "abcdefg", k = 2
//��� : "bacdfeg"
//
//
//
//
//	  ��Դ�����ۣ�LeetCode��
//  ���ӣ�https ://leetcode-cn.com/problems/reverse-string-ii
//	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//��ȷͨ��oj�Ĵ���
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
			if (IsReverse % 2)       //����Ϊ1��˵��Ϊ��������Ҫ���á�
			{
				std::reverse(begin, kend);
			}
			size -= k;
			begin += k;
			IsReverse++;
		}
		string::iterator end = s.end();
		if (IsReverse % 2)           // size<k,�������������
		{
			std::reverse(begin, end);
		}
		return s;
	}
};


//=================================================================================================================
//����Ϊ���Դ��룬������ԭ�򣬾��Ʋ������������ķ���ֵ�����ߵ�������֧��һ���߶ಽ�йأ�����֪������Ȼ�ٲ���
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
//				if (IsReverse % 2)       //����Ϊ1��˵��Ϊ��������Ҫ���á�
//				{
//					std::reverse(begin, begin + k - 1);     //����д���� begin + k - 1 û�������ã���Ȼ����ͨ���ˡ�
//				}
//				size -= k;
//				begin += k;
//				IsReverse++;
//			}
//			string::iterator end = s.end();
//			if (IsReverse % 2)           // size<k,�������������
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