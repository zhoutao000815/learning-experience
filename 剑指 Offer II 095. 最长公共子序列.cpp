//剑指 Offer II 095. 最长公共子序列
//给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
//
//一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
//两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
//
//
//
//示例 1：
//
//输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace" ，它的长度为 3 。
//示例 2：
//
//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc" ，它的长度为 3 。
//示例 3：
//
//输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0 。
//
//
//提示：
//
//1 <= text1.length, text2.length <= 1000
//text1 和 text2 仅由小写英文字符组成。
//
//
//注意：本题与主站 1143 题相同： https ://leetcode-cn.com/problems/longest-common-subsequence/
//


//思路：动态规划
//假设在text2中寻找text1的最长子序列
//由text1[0]到text1[i]开始，一一与text2[0~j]匹配，产生两种结果
//text1[i]==text2[j]，说明是text1[0~i]子序列中的一员，再加上子序列前一个位置的最大长度，就得到该位置子序列的最大长度。
//text1[i]！=text2[j]，说明不是text1[0~i]最长子序列中的一员，这就要从text1[0~（i-1）]最长子序列长度，和text1[0~i]中选最大值。
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0)); //多开一行一列空间，并且初始化。
//         for(int i=1;i<=text1.size();i++)
//         {
//             for(int j=1;j<=text2.size();j++)
//             {
//                 if(text1[i-1]==text2[j-1])
//                 {
//                     dp[i][j]=dp[i-1][j-1]+1;      //记得+该字符本身1，
//                 }
//                 else
//                 {
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[text1.size()][text2.size()];
//     }
// };

//可以用滚动数组进行空间优化.
//因为dp[j-1]先于dp[j]运算，所以dp[j-1]=dp[i][j-1],dp[j]=dp[i-1][j]; 再来一个变量prev记录dp[i-1][j-1]
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<int> dp(text2.size() + 1, 0);      //多开一列空间，并且初始化。
		int prev, prev_temp;
		for (int i = 1; i <= text1.size(); i++)
		{
			prev_temp = dp[0];       //temp相当于dp[i][0];
			for (int j = 1; j <= text2.size(); j++)
			{
				prev = prev_temp;    //相当于一个变量pre代替了dp[i-1][j-1];
				prev_temp = dp[j];   //temp相当于dp[i-1][j];
				dp[j] = text1[i - 1] == text2[j - 1] ? prev + 1 : max(dp[j], dp[j - 1]);
			}
		}
		return dp[text2.size()];
	}
};
