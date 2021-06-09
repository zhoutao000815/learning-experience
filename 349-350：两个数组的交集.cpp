//349. 两个数组的交集
//给定两个数组，编写一个函数来计算它们的交集。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2]
//示例 2：
//
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[9, 4]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/intersection-of-two-arrays
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//方法一：两个哈希表去重+查找
		// unordered_set<int> s1,s2;
		// for(auto&e:nums1)
		//     s1.insert(e);
		// for(auto&e:nums2)
		//     s2.insert(e);
		// vector<int> res;
		// for(auto&e:s1)
		// {
		//     if(s2.find(e)!=s2.end())
		//         res.push_back(e);
		// }
		// return res;

		//方法二：排序+双指针比对法
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> res;
		for (int i = 0, j = 0; i<nums1.size() && j<nums2.size();)
		{
			if (nums1[i]<nums2[j])
				i++;
			else if (nums1[i]>nums2[j])
				j++;
			else
			{
				res.push_back(nums1[i]);
				i++;
				j++;
			}
			while (i>0 && i<nums1.size() && nums1[i] == nums1[i - 1])        //去重
				i++;
			while (j>0 && j<nums2.size() && nums2[j] == nums2[j - 1])        //去重
				j++;
		}
		return res;
	}
};


//350. 两个数组的交集 II
//给定两个数组，编写一个函数来计算它们的交集。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2, 2]
//示例 2:
//
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[4, 9]
//
//
//说明：
//
//输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
//我们可以不考虑输出结果的顺序。
//进阶：
//
//如果给定的数组已经排好序呢？你将如何优化你的算法？
//如果 nums1 的大小比 nums2 小很多，哪种方法更优？
//如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
//
//如果 nums2的元素存储在磁盘上，磁盘内存是有限的，
//并且你不能一次加载所有的元素到内存中。那么就无法高效地对 nums2进行排序，
//
//因此推荐使用方法一而不是方法二。
//在方法一中，nums2只关系到查询操作，因此每次读取 nums2中的一部分数据，并进行处理即可。
//
//链接：https ://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		//方法一：一个哈希表记录次数，用另外一个去查找，出现次数大于0的，出现一次就减少一次，
		unordered_map<int, int> s1;
		for (auto&e : nums1)
			s1[e]++;
		vector<int> res;
		for (auto&e : nums2)
		{
			if (s1[e]>0)
			{
				res.push_back(e);
				s1[e]--;
			}
		}
		return res;

		//方法二：排序+双指针比对法
		// sort(nums1.begin(),nums1.end());
		// sort(nums2.begin(),nums2.end());
		// vector<int> res;
		// for(int i=0,j=0;i!=nums1.size() && j!=nums2.size();)
		// {
		//     if(nums1[i]<nums2[j])
		//         i++;
		//     else if(nums1[i]>nums2[j])
		//         j++;
		//     else
		//     {               
		//         res.push_back(nums1[i]);
		//         i++;
		//         j++;
		//     }               
		// }
		// return res;
	}
};