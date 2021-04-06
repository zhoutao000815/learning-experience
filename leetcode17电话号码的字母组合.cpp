//17. 电话号码的字母组合
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
//
//
//示例 1：
//
//输入：digits = "23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//示例 2：
//
//输入：digits = ""
//输出：[]
//示例 3：
//
//输入：digits = "2"
//输出：["a", "b", "c"]


//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//帮助理解的博客链接:https://blog.csdn.net/Zhou000815/article/details/115458033
	class Solution {
	public:
		void initial(vector<string>& initlist)
		{
			initlist[2] = "abc";
			initlist[3] = "def";
			initlist[4] = "ghi";
			initlist[5] = "jkl";
			initlist[6] = "mno";
			initlist[7] = "pqrs";
			initlist[8] = "tuv";
			initlist[9] = "wxyz";
		}
		void retvset(const string& flag, vector<string>& retv, int retvsize, int groupsize)
		{
			int begin = 0;
			//groupsize指每个字母在被重复多少次
			//groups指数字对应的字母组有多少组
			int groups = retvsize / groupsize / flag.size();
			for (int g = 0; g<groups; g++)
			{
				for (int i = 0; i<flag.size(); i++)
				{
					for (int j = 0; j<groupsize; j++)
					{
						retv[begin] += flag[i];
						begin++;
					}
				}
			}
		}
		vector<string> letterCombinations(string digits) {
			vector<string> list(10, "");
			initial(list);
			int retvsize = 0;
			for (int i = 0; i<digits.size(); i++)
			{
				if (0 == retvsize)
				{
					retvsize = 1;
				}
				retvsize *= list[digits[i] - '0'].size();
			}
			vector<string> retv(retvsize, "");
			int retvsizecopy = retvsize;
			for (int i = 0; i<digits.size(); i++)
			{
				retvsizecopy /= list[digits[i] - '0'].size();
				retvset(list[digits[i] - '0'], retv, retvsize, retvsizecopy);
			}
			return  retv;
		}
	};