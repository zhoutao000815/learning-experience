﻿//139. 单词拆分
//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入 : s = "leetcode", wordDict = ["leet", "code"]
// 输出 : true
//  解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//	   示例 2：
//
//   输入 : s = "applepenapple", wordDict = ["apple", "pen"]
//	输出 : true
//	解释 : 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//		  注意你可以重复使用字典中的单词。
//		  示例 3：
//
//	  输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//	  输出 : false
//
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/word-break
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> us(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j<i; j++)
			{
				if (dp[j] && (us.find(s.substr(j, i - j)) != us.end()))
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
};

// class Solution {
// public:
//     bool wordBreak(string& s, vector<string>& wordDict) {
//         vector<bool> dp(s.size()+1, false);
//         dp[0] = true;
//         for(int i = 0; i < s.size(); i++){
//             if(!dp[i])
//                 continue;
//             for(auto& word : wordDict)
//                 if(word.size() + i <= s.size() && s.substr(i, word.size()) == word)
//                     dp[i+word.size()] = true;
//         }
//         return dp[s.size()];
//     }
// };