//392. 判断子序列
//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//
//字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
//
//进阶：
//
//如果有大量输入的 S，称作 S1, S2, ..., Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
//
//
//
//示例 1：
//
//输入：s = "abc", t = "ahbgdc"
//输出：true
//示例 2：
//
//输入：s = "axc", t = "ahbgdc"
//输出：false
//
//
//提示：
//
//0 <= s.length <= 100
//0 <= t.length <= 10 ^ 4
//两个字符串都只由小写字符组成。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/is-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
	bool isSubsequence(string s, string t) {
		//双指针法
		size_t pos = 0;
		for (int i = 0; i<s.size(); i++)
		{
			//find函数的第二个参数可以指定查找起始位置，当pos>=str.size（）时同样返回string::npos（-1）
			if ((pos = t.find(s[i], pos)) == -1)     //s[i]在T中POS之后的位置找不到
				return false;
			pos++;                            //给上一个位置的结果+1，就是下一个位置的起始
		}
		return true;
	}
};