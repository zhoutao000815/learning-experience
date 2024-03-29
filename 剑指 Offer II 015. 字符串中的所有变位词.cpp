﻿//剑指 Offer II 015. 字符串中的所有变位词
//给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//
//变位词 指字母相同，但排列不同的字符串。
//
//
//
//示例 1:
//
//输入 : s = "cbaebabacd", p = "abc"
//输出 : [0, 6]
// 解释 :
//	起始索引等于 0 的子串是 "cba", 它是 "abc" 的变位词。
//	起始索引等于 6 的子串是 "bac", 它是 "abc" 的变位词。
//	示例 2 :
//
//输入 : s = "abab", p = "ab"
// 输出 : [0, 1, 2]
//  解释 :
//	 起始索引等于 0 的子串是 "ab", 它是 "ab" 的变位词。
//	 起始索引等于 1 的子串是 "ba", 它是 "ab" 的变位词。
//	 起始索引等于 2 的子串是 "ab", 它是 "ab" 的变位词。
//
//
// 提示 :
//
//	 1 <= s.length, p.length <= 3 * 104
//		 s 和 p 仅包含小写字母

//注意：本题与主站 438 题相同： https ://leetcode-cn.com/problems/find-all-anagrams-in-a-string/

//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/VabMRr
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		if (s.size()<p.size())
			return{};
		vector<int> index, s_str(26), p_str(26);      //用映射记录数组下标对应字符出现次数。
		int i = 0;
		for (; i<p.size(); i++)
		{
			s_str[s[i] - 'a']++;
			p_str[p[i] - 'a']++;
		}
		if (s_str == p_str)                            //如果26个字符出现的次数都相等说明满足条件，记录起始位置。
			index.push_back(0);
		int psize = p.size();

		for (; i<s.size(); i++)                        //定长滑动窗口，左边字符出现次数减一，右边+1。
		{
			s_str[s[i] - 'a']++;
			s_str[s[i - psize] - 'a']--;
			if (s_str == p_str)                        //判断相等。
				index.push_back(i - psize + 1);
		}
		return index;
	}
};