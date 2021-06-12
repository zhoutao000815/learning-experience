//409. 最长回文串
//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//
//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//
//注意 :
//假设字符串的长度不会超过 1010。
//
//示例 1 :
//
//输入 :
//   "abccccdd"
//
//输出 :
//   7
//
//解释 :
//   我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
//
//   来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-palindrome
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路；统计所有字符出现次数，偶数个的相加，标志位flag为有无出现奇数个的字符。
//结果：偶数个的和 + flag。
// class Solution {
// public:
//     int longestPalindrome(string s) {
//         if(s.size()<2)
//         {
//             return s.size();
//         }
//         unordered_map<char,size_t> um;
//         for(auto &e:s)
//         {
//             um[e]++;
//         }
//         size_t flag=0;
//         size_t half_size=0;
//         for(auto&e:um)
//         {
//             half_size+=(e.second>>1);
//             if(e.second%2)
//                 flag=1;
//         }
//         int size=(half_size<<1)+flag;
//         return size;
//     }
// };

//思路：s的长度 减去 出现奇数次的字符个数+1，回文串最中间的哪一位可以是奇数次
class Solution
{
public:
	int longestPalindrome(string s)
	{
		//map<char, int> m;
		unordered_map<char, int> m;
		int sz = s.size();
		int count = 0; //出现次数为奇数的字母个数
		for (int i = 0; i < sz; i++)
		{
			m[s[i]]++;
			if (m[s[i]] % 2 == 1)
			{
				count++;
			}
			else
				count--;
		}
		if (count == 0)
			return sz;
		return sz - count + 1;
	}
};