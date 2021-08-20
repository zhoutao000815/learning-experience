//剑指 Offer II 017. 含有所有字符的最短字符串
//给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。
//
//如果 s 中存在多个符合条件的子字符串，返回任意一个。
//
//注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
//
//示例 1：
//
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
//示例 2：
//
//输入：s = "a", t = "a"
//输出："a"
//示例 3：
//
//输入：s = "a", t = "aa"
//输出：""
//解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
//
//
//提示：
//
//1 <= s.length, t.length <= 105
//s 和 t 由英文字母组成
//
//
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
//
//注意：本题与主站 76 题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-substring/
//
//链接：https ://leetcode-cn.com/problems/M1oyTv
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//思路：滑动窗口，先在S的子串右指针右移找一个完全包含T的，找到后，左指针移除非必须的字符
//非必须的字符有两类：1、T中没有的，2、T中有，但子串中出现的次数超过了T中出现的次数。）
//一但左指针到了，刚好出现次数相等的字符处，说明此时的left字符已经是必须的了。
//删掉这个必须的字符，开始寻找下一个完全包含T的s子串。
//当然了，找到符合条件的子串要取长度最短的那个。
//还有一点，如何确认S中包含T呢？要实现O（1）的查找只能用哈希表。
class Solution {
public:
	string minWindow(string s, string t) {
		if (t.size()>s.size())
			return "";
		int left = 0;
		int right = 0;
		//哈希标查找效率逼近O（1）。
		unordered_map<char, int> t_um;              //t字符串的字符统计
		unordered_map<char, int> s_um;              //s子串中包含T的统计，只要出现过就统计次数。
		unordered_map<char, int> s_std;             //s子串中包含T的统计，并且出现次数小于等于T中字符出现次数的
		for (auto &e : t)
			t_um[e]++;
		string res("");
		while (right<s.size())
		{
			if (t_um.find(s[right]) != t_um.end())            //注意T_um的查询必须用find,[]底层用的是insert。
			{
				s_um[s[right]]++;
				if (s_std[s[right]]<t_um[s[right]])
					s_std[s[right]]++;
			}

			while (t_um == s_std)                         //用来确认满足S子串包含T，并且用来剔除非必须字符的循环。
			{
				if (res == "" || res.size() > (right - left + 1))
				{
					res = s.substr(left, right - left + 1);
				}

				if (t_um.find(s[left]) != t_um.end())            //T中出现的字符。
				{
					if (t_um[s[left]] == s_um[s[left]])        //满足当前窗口条件的必须字符
					{
						s_std[s[left]]--;                     //干掉后，自动下一个。
					}
					s_um[s[left]]--;                          //出现次数过多的非必须字符，删掉。
				}
				left++;
			}
			right++;
		}
		return res;
	}
};

