//5823. 字符串转化后的各位数字之和
//给你一个由小写字母组成的字符串 s ，以及一个整数 k 。
//
//首先，用字母在字母表中的位置替换该字母，将 s 转化 为一个整数（也就是，'a' 用 1 替换，'b' 用 2 替换，... 'z' 用 26 替换）。接着，将整数 转换 为其 各位数字之和 。共重复 转换 操作 k 次 。
//
//例如，如果 s = "zbax" 且 k = 2 ，那么执行下述步骤后得到的结果是整数 8 ：
//
//
//
//示例 1：
//
//输入：s = "iiii", k = 1
//输出：36
//解释：操作如下：
//- 转化："iiii" -> "(9)(9)(9)(9)" -> "9999" ->9999
//- 转换 #1：9999 -> 9 + 9 + 9 + 9->36
//因此，结果整数为 36 。
//示例 2：
//
//输入：s = "leetcode", k = 2
//输出：6
//解释：操作如下：
//- 转化："leetcode" -> "(12)(5)(5)(20)(3)(15)(4)(5)" -> "12552031545" -> 12552031545
//- 转换 #1：12552031545 -> 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 -> 33
//- 转换 #2：33 -> 3 + 3 -> 6
//因此，结果整数为 6 。
//
//
//提示：
//
//1 <= s.length <= 100
//1 <= k <= 10
//s 由小写英文字母组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sum-of-digits-of-string-after-convert
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	string add(string &tmp)        //累计和
	{
		int res = 0;
		for (int i = 0; i<tmp.size(); i++)
		{
			res += tmp[i] - '0';
		}
		return to_string(res);
	}

	int getLucky(string s, int k) { 
		string tmp;
		for (int i = 0; i<s.size(); i++)       //第一次字符a~z转为数字1~26
		{
			int c = s[i] - 'a' + 1;
			tmp += to_string(c);
		}
		for (int i = 0; i<k; i++)			  //k次计和
		{
			string res = add(tmp);
			tmp = res;
		}
		return atoi(tmp.c_str());
	}
};