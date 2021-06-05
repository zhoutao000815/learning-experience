//剑指 Offer 38. 字符串的排列
//输入一个字符串，打印出该字符串中字符的所有排列。
//
//
//
//你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
//
//
//
//示例 :
//
//输入：s = "abc"
//输出：["abc", "acb", "bac", "bca", "cab", "cba"]
//
//
//限制：
//
//1 <= s 的长度 <= 8
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	void permu(set<string>& tmp, string &s, int begin, int end)
	{
		if (begin == end-1)
		{
			tmp.insert(s);
			return;
		}
		for (size_t i = begin; i<s.size(); i++)
		{
			swap(s[begin], s[i]);
			permu(tmp, s, begin + 1, end);
			swap(s[begin], s[i]);
		}
	}

	vector<string> permutation(string s) {
		set<string> tmp;           //利用set的去重特性，保存结果，
		permu(tmp, s, 0, s.size());
		vector<string> res(tmp.begin(), tmp.end());    //迭代器区间构造结果返回
		return res;
	}
};


// class Solution {
// public:
//     vector<string> permutation(string s) {
//         dfs(s, 0);
//         return res;
//     }
// private:
//     vector<string> res;
//     void dfs(string s, int x) {
//         if(x == s.size() - 1) {
//             res.push_back(s);                       // 添加排列方案
//             return;
//         }
//         set<int> st;
//         for(int i = x; i < s.size(); i++) {
//             if(st.find(s[i]) != st.end()) 
//                 continue;							// 重复，因此剪枝
//             st.insert(s[i]);
//             swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
//             dfs(s, x + 1);                          // 开启固定第 x + 1 位字符
//             swap(s[i], s[x]);                       // 恢复交换
//         }
//     }
// };