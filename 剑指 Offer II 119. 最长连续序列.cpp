//剑指 Offer II 119. 最长连续序列
//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//
//
//
//示例 1：
//
//输入：nums = [100, 4, 200, 1, 3, 2]
//输出：4
//解释：最长数字连续序列是[1, 2, 3, 4]。它的长度为 4。
//示例 2：
//
//输入：nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
//输出：9
//
//
//提示：
//
//0 <= nums.length <= 104
//- 109 <= nums[i] <= 109
//
//
//进阶：可以设计并实现时间复杂度为 O(n) 的解决方案吗？
//
//
//
//注意：本题与主站 128 题相同： https ://leetcode-cn.com/problems/longest-consecutive-sequence/


//时间复杂度：O（n）
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> num_set;
		for (auto &e : nums)
		{
			num_set.insert(e);
		}

		int max_leng = 0;

		for (auto &e : num_set)
		{
			//前一个数字e-1存在，那就不往后找，等到e-1时再找。
			//也就是说，我们从每一段连续的数列的第一个开始找。不是第一个就等到第一个再找。
			if (num_set.find(e - 1) == num_set.end())
			{
				int curnum = e;
				int curnum_leng = 1;
				while (num_set.find(curnum + 1) != num_set.end())
				{
					++curnum;
					++curnum_leng;
				}
				max_leng = max(max_leng, curnum_leng);
			}
		}
		return max_leng;
	}
};