//692. 前K个高频单词
//给一非空的单词列表，返回前 k 个出现次数最多的单词。
//
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
//
//示例 1：
//
//输入 : ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// 输出 : ["i", "love"]
//  解析 : "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//	   注意，按字母顺序 "i" 在 "love" 之前。
//
//
//	   示例 2：
//
//   输入 : ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
//	输出 : ["the", "is", "sunny", "day"]
//	 解析 : "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//		  出现次数依次为 4, 3, 2 和 1 次。
//
//
//		  注意：
//
//		  假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
//		  输入的单词均由小写字母组成。
//
//
//		  扩展练习：
//
//		  尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
//
//
//
//		  来源：力扣（LeetCode）
//	  链接：https ://leetcode-cn.com/problems/top-k-frequent-words
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> count_map;
		//用map<string,int> count_map;统计string出现次数.
		for (auto &e : words)
		{
			count_map[e]++;
		}

		//方法一:vector+排序
		//因为可能存在出现次数相同的字符串，此条件下由于string由ASCII码排序，相对顺序不能变，用vector保存count_map的k-v
		//再定义仿函数比较大小、排降序是不可取的。
		//用快排sort稳定性差，是不可取的。
		//所以要采用稳定性好的排序（冒泡，插入，归并）排降序取前k个。

		//方法二:multimap / multiset
		//因为stl中，multimap / multiset的插入，在key值相同的情况下，会在key的右子树插入，保证了string的相对顺序。
		multimap<int, string, greater<int>> sort_map;
		for (auto &e : count_map)
		{
			sort_map.insert(make_pair(e.second, e.first));
		}

		vector<string> rel;
		auto it = sort_map.begin();
		while (k--)
		{
			rel.push_back(it->second);
			it++;
		}
		return rel;
	}
};