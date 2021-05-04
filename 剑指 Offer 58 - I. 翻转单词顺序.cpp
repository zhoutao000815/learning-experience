﻿//剑指 Offer 58 - I.翻转单词顺序
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
//
//
//
//示例 1：
//
//输入 : "the sky is blue"
// 输出 : "blue is sky the"
//	  示例 2：
//
//  输入 : "  hello world!  "
//   输出 : "world! hello"
//	解释 : 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//		 示例 3：
//
//	 输入 : "a good   example"
//	  输出 : "example good a"
//	   解释 : 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//
//		
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());

		string::iterator cur = s.begin();

		while (*cur == ' ')  //处理翻转后的前导空格
		{
			s.erase(cur);
		}
		string::iterator prev = cur;
		while (cur != s.end())
		{
			if (*cur == ' ')
			{
				while (*cur == ' ' && *(cur + 1) == ' ')  //处理单词间的多余空格
				{
					s.erase(cur);
				}
				reverse(prev, cur);
				prev = cur + 1;
			}
			cur++;
		}
		reverse(prev, cur); //处理最后一个单词，即使最后有空格，prev和cur都指向end（）逆置也不影响什么。

		cur = s.end() - 1;
		while (*cur == ' ')//处理尾部空格
		{
			s.erase(cur);
			cur--;
		}
		return s;
	}
};