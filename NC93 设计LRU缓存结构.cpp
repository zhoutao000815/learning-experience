//NC93 设计LRU缓存结构
//
//中等  通过率：33.23%  时间限制：2秒  空间限制：256M
//知识点
//
//设计LRU(最近最少使用)缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能
//1. set(key, value)：将记录(key, value)插入该结构
//2. get(key)：返回key对应的value值
//
//提示 :
//1.某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的，然后都会刷新缓存。
//2.当缓存的大小超过K时，移除最不经常使用的记录。
//3.输入一个二维数组与K，二维数组每一维有2个或者3个数字，第1个数字为opt，第2，3个数字为key，value
//若opt = 1，接下来两个整数key, value，表示set(key, value)
//若opt = 2，接下来一个整数key，表示get(key)，若key未出现过或已被移除，则返回 - 1
//对于每个opt = 2，输出一个答案
//4.为了方便区分缓存里key与value，下面说明的缓存里key用""号包裹
//
//进阶 : 你是否可以在O(1)的时间复杂度完成set和get操作
//	 示例1
//	 输入：
//	 [[1, 1, 1], [1, 2, 2], [1, 3, 2], [2, 1], [1, 4, 4], [2, 2]], 3
//	 复制
//	 返回值：
//	 [1, -1]
//复制
//说明：
//[1, 1, 1]，第一个1表示opt = 1，要set(1, 1)，即将(1, 1)插入缓存，缓存是{ "1" = 1 }
//[1, 2, 2]，第一个1表示opt = 1，要set(2, 2)，即将(2, 2)插入缓存，缓存是{ "1" = 1, "2" = 2 }
//[1, 3, 2]，第一个1表示opt = 1，要set(3, 2)，即将(3, 2)插入缓存，缓存是{ "1" = 1, "2" = 2, "3" = 2 }
//[2, 1]，第一个2表示opt = 2，要get(1)，返回是[1]，因为get(1)操作，缓存更新，缓存是{ "2" = 2, "3" = 2, "1" = 1 }
//[1, 4, 4]，第一个1表示opt = 1，要set(4, 4)，即将(4, 4)插入缓存，但是缓存已经达到最大容量3，移除最不经常使用的{ "2" = 2 }，插入{ "4" = 4 }，缓存是{ "3" = 2, "1" = 1, "4" = 4 }
//[2, 2]，第一个2表示opt = 2，要get(2)，查找不到，返回是[1, -1]
//示例2
//输入：
//[[1, 1, 1], [1, 2, 2], [2, 1], [1, 3, 3], [2, 2], [1, 4, 4], [2, 1], [2, 3], [2, 4]], 2
//复制
//返回值：
//[1, -1, -1, 3, 4]
//
//
//链接：https://www.nowcoder.com/practice/e3769a5f49894d49b871c09cadd13a61?tpId=117&&tqId=1006010

class Solution {
public:
	/**
	* lru design
	* @param operators int整型vector<vector<>> the ops
	* @param k int整型 the k
	* @return int整型vector
	*/

	vector<int> LRU(vector<vector<int> >& operators, int k) {
		list<pair<int, int>> lp;
		unordered_map<int, list<pair<int, int>>::iterator> um;
		vector<int> res;
		for (auto &opt : operators)
		{
			if (opt[0] == 1)   //set方法
			{
				auto it = um.find(opt[1]);
				if (it == um.end())
				{
					if (lp.size() >= k)
					{
						int val = opt[2];
						lp.push_front(make_pair(opt[1], val));
						um.erase((--lp.end())->first);
						lp.erase(--lp.end());
						um[opt[1]] = lp.begin();
					}
					else
					{
						int val = opt[2];
						lp.push_front(make_pair(opt[1], val));
						um[opt[1]] = lp.begin();
					}
				}
				else
				{
					int val = opt[2];
					lp.push_front(make_pair(opt[1], val));
					lp.erase(it->second);
					um[opt[1]] = lp.begin();
				}
			}
			else    //get方法
			{
				auto it = um.find(opt[1]);
				if (it != um.end())
				{
					int val = it->second->second;
					lp.push_front(make_pair(opt[1], val));
					lp.erase(it->second);
					um[opt[1]] = lp.begin();

					res.push_back(val);
				}
				else
				{
					res.push_back(-1);
				}
			}
		}
		return res;
	}
};