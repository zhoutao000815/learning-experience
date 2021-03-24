//557. 反转字符串中的单词 III
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//
//
//示例：
//
//输入："Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
//
//
//
//提示：
//
//在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-words-in-a-string-iii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	string reverseWords(string s) {
		string::iterator begin = s.begin();
		string::iterator end = s.end();
		size_t pos = 0;
		while (begin != end)
		{
			begin = s.begin() + pos;
			pos = s.find(' ', pos);
			if (pos == string::npos)
			{
				std::reverse(begin, s.end());
				break;
			}
			std::reverse(begin, s.begin() + pos);
			pos++;
		}
		return s;
	}
};