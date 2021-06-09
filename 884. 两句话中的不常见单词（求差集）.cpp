//884. 两句话中的不常见单词
//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//
//返回所有不常用单词的列表。
//
//您可以按任何顺序返回列表。
//
//
//
//示例 1：
//
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet", "sour"]
//示例 2：
//
//输入：A = "apple apple", B = "banana"
//输出：["banana"]
//
//
//提示：
//
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。
//
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/uncommon-words-from-two-sentences
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路：要做到本身只出现一次 && 在对方哪里没有出现过
//解法一：两个unordered_multiset分别记录 s1 s2 再通过成员函数t1.count（）计数自己出现次数==1， t2.find（）==t2.end（）；
// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         unordered_multiset<string> t1,t2;
//         size_t begin=0;
//         size_t end=0;
//         while((end=s1.find(' ',begin))!=string::npos)
//         {
//             t1.insert(s1.substr(begin,end-begin));
//             begin=++end;
//         }
//         t1.insert(s1.substr(begin,s1.size()-begin));

//         begin=end=0;
//         while((end=s2.find(' ',begin))!=string::npos)
//         {
//             t2.insert(s2.substr(begin,end-begin));
//             begin=++end;
//         }
//         t2.insert(s2.substr(begin,s2.size()-begin));

//         vector<string> res;
//         for(auto &e:t1)
//         {
//             if(t2.end()==t2.find(e) && t1.count(e)==1)
//                 res.push_back(e);
//         }

//         for(auto &e:t2)
//         {
//             if(t1.end()==t1.find(e)&& t2.count(e)==1)
//                 res.push_back(e);
//         }
//         return res;
//     }
// };

//解法二：直接用unordered_map<string,int> m，两个字符串加一起一起遍历，加上［］进行插入计数，.second为１　的为差集。
class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		unordered_map<string, int> m;
		s1 += ' ';
		s1 += s2;
		size_t begin = 0;
		size_t end = 0;
		while ((end = s1.find(' ', begin)) != string::npos)
		{
			m[s1.substr(begin, end - begin)]++;
			begin = ++end;
		}
		m[(s1.substr(begin, s1.size() - begin))]++;

		vector<string> res;
		for (auto &e : m)
		{
			if (e.second == 1)
				res.push_back(e.first);
		}
		return res;
	}
};