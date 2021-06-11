//300. 最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。
//
//
//示例 1：
//
//输入：nums = [10, 9, 2, 5, 3, 7, 101, 18]
//输出：4
//解释：最长递增子序列是[2, 3, 7, 101]，因此长度为 4 。
//示例 2：
//
//输入：nums = [0, 1, 0, 3, 2, 3]
//输出：4
//示例 3：
//
//输入：nums = [7, 7, 7, 7, 7, 7, 7]
//输出：1
//
//
//提示：
//
//1 <= nums.length <= 2500
//- 104 <= nums[i] <= 104
//
//进阶：
//
//你可以设计时间复杂度为 O(n2) 的解决方案吗？
//你能将算法的时间复杂度降低到 O(n log(n)) 吗 ?
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-increasing-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//动态规划：
//用dp[i]来表示当前位置往左最长子序列长度。
//对于每一个位置i只要满足 1、j在i左边。2、num[j]比nums[i]小。都应该dp[i]=max(dp[i],dp[j]+1);
//另外初始状态，每个位置初始计数都是1,包括他自己。

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int maxcount = 0;
		vector<int> dp(nums.size(), 1);        //每个位置，起始位置的计数包括他自己。 
		for (int i = 0; i<nums.size(); i++)
		{
			for (int j = 0; j<i; j++)
			{
				if (nums[j]<nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			maxcount = max(maxcount, dp[i]);
		}
		return maxcount;
	}
};