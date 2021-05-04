//剑指 Offer 57. 和为s的两个数字
//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
//
//
//
//示例 1：
//
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[2, 7] 或者[7, 2]
//示例 2：
//
//输入：nums = [10, 26, 30, 31, 47, 60], target = 40
//输出：[10, 30] 或者[30, 10]
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//对撞双指针
		size_t l = 0;
		size_t r = nums.size() - 1;
		while (l < r) {
			while (nums[r]>target)
			{
				r--;
			}
			int sum = nums[l] + nums[r];
			// 如果大于目标和，则右边的数要小一点
			if (sum > target) {
				r--;
			}
			// 如果小于目标和，则左边的数要大一点
			else if (sum < target) {
				l++;
			}
			// 如果等于目标和，则直接返回目标序列
			else if (sum == target){
				return vector<int>{nums[l], nums[r]};
			}
		}
		return vector<int>{};
	}
};