﻿//5. 最长回文子串
//给你一个字符串 s，找到 s 中最长的回文子串。
//
//
//
//示例 1：
//
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//示例 2：
//
//输入：s = "cbbd"
//输出："bb"
//示例 3：
//
//输入：s = "a"
//输出："a"
//示例 4：
//
//输入：s = "ac"
//输出："a"
//
//
//提示：
//
//1 <= s.length <= 1000
//s 仅由数字和英文字母（大写和 / 或小写）组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-palindromic-substring
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力法：例举所有子串，判断是否回文，记录最长回文子串。O（n ③）
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.size()<2)
//             return s;
//         string res;
//         for(int i=s.size();i>=0;--i)          
//         {
//             for(int j=0;j<i;j++)
//             {
//                 string tmp=s.substr(j,i-j);
//                 string tmp2(tmp);
//                 reverse(tmp2.begin(),tmp2.end());
//                 if(tmp==tmp2 && tmp.size()>res.size())
//                 {
//                     res=tmp;
//                 }
//             }
//         }
//         return res;
//     }
// };

//动态规划：
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         if (n < 2) {
//             return s;
//         }

//         int maxLen = 1;
//         int begin = 0;
//         // dp[i][j] 表示 s[i..j] 是否是回文串
//         vector<vector<int>> dp(n, vector<int>(n));
//         // 初始化：所有长度为 1 的子串都是回文串
//         for (int i = 0; i < n; i++) {
//             dp[i][i] = true;
//         }
//         // 递推开始
//         // 先枚举子串长度
//         for (int L = 2; L <= n; L++) {
//             // 枚举左边界，左边界的上限设置可以宽松一些
//             for (int i = 0; i < n; i++) {
//                 // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//                 int j = L + i - 1;
//                 // 如果右边界越界，就可以退出当前循环
//                 if (j >= n) {
//                     break;
//                 }

//                 if (s[i] != s[j]) {
//                     dp[i][j] = false;
//                 } else {
//                     if (j - i < 3) {
//                         dp[i][j] = true;
//                     } else {
//                         dp[i][j] = dp[i + 1][j - 1];
//                     }
//                 }

//                 // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
//                 if (dp[i][j] && j - i + 1 > maxLen) {
//                     maxLen = j - i + 1;
//                     begin = i;
//                 }
//             }
//         }
//         return s.substr(begin, maxLen);
//     }
// };

//中心扩展算法：遍历原字符串，以s[i]或者s[i][i+1]为中心往两边扩展
//奇数回文串，找最中间那个字符，往左右两边扩展，直到不是回文串。
//偶数回文串，找最中间那两个字符，往左右两边扩展，直到不是回文串。
//保留长度最长的回文串。
class Solution {
public:
	string central(string &s, int cenl, int cenr)
	{
		while (cenl >= 0 && cenr<s.size() && s[cenl] == s[cenr])  //直到不满足条件的位置
		{
			cenl--;
			cenr++;
		}
		cenl++; cenr--;               //满足条件的位置。
		return s.substr(cenl, cenr - cenl + 1);
	}

	string longestPalindrome(string s) {
		if (s.size()<2)
			return s;
		string res;
		for (int i = 0; i<s.size(); i++)
		{
			string tmp1 = central(s, i, i);
			string tmp2 = central(s, i, i + 1);
			res = tmp1.size()>res.size() ? tmp1 : res;
			res = tmp2.size()>res.size() ? tmp2 : res;
		}
		return res;
	}
};