//3. 无重复字符的最长子串
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//
//
//示例 1:
//
//输入 : s = "abcabcbb"
//输出 : 3
// 解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//	  示例 2 :
//
//  输入 : s = "bbbbb"
//   输出 : 1
//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//		 示例 3 :
//
//	 输入 : s = "pwwkew"
//	  输出 : 3
//	   解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//			请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//			示例 4 :
//
//		输入 : s = ""
//		 输出 : 0
//		  输入 : s = ""
//		   输出 : 0
//
//				来源：力扣（LeetCode）
//			链接：https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//滑动窗口
		//每次右指针向右移一步，在当前窗口内作查重检测，无重复则右指针继续右移，有重复则重新定义窗口左指针到无重复位置。
		int left = 0, right = 0;
		int size = 0;
		while (right<s.size())
		{
			size_t cur = left;
			while (cur<right)  //作检测
			{
				if (s[cur] == s[right]) //有重复，缩小窗口左到没有重复的部分。
				{
					left = cur + 1;
					break;
				}
				cur++;
			}
			size = max(size, right - left + 1);     //每次检测完后计算窗口大小，保存最大值。
			right++;
		}
		return size;
	}
};