//14. 最长公共前缀
//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//
//
//示例 1：
//
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//示例 2：
//
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。
//
//
//提示：
//
//0 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 仅由小写英文字母组成
//
//解释：输入不存在公共前缀。
//
//
//提示：
//
//0 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 仅由小写英文字母组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-common-prefix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret;
		if (strs.size() == 0)
		{
			return ret;
		}
		size_t minlen = strs[0].size();  //虽然是最长前缀，但是最长也长不过最短字符串的长度。
		for (int i = 0; i<strs.size(); i++)
		{
			if (strs[i].size()<minlen)
			{
				minlen = strs[i].size();
			}
		}
		for (int i = 0; i<minlen; i++)
		{
			int j = 1;
			for (; j<strs.size(); j++)
			{
				if (strs[j][i] != strs[j - 1][i])
				{
					return ret;
				}
			}
			ret += strs[0][i];
		}
		return ret;
	}
};