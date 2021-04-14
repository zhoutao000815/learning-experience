//18. 四数之和
//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//注意：答案中不可以包含重复的四元组。
//
//
//
//示例 1：
//
//输入：nums = [1, 0, -1, 0, -2, 2], target = 0
//输出：[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
//示例 2：
//
//输入：nums = [], target = 0
//输出：[]
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/4sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/4sum/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int size = nums.size();
		if (size<4)
		{
			return result;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i<size; i++)
		{
			if (nums[i] > target)
			{
				return result;
			}
			if (i>0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			for (int j = i + 1; j<size; j++)
			{
				if (j>i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				int left = j + 1;
				int right = size - 1;
				while (left<right)
				{
					if (left<right && nums[i] + nums[j] + nums[left] + nums[right]>target)
					{
						right--;
					}
					else if (left<right && nums[i] + nums[j] + nums[left] + nums[right]<target)
					{
						left++;
					}
					else
					{
						result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						while (left<right && nums[right] == nums[right - 1]) { right--; }
						while (left<right && nums[left] == nums[left + 1]) { left++; }
						right--;
						left++;
					}

				}
			}
		}
		return result;
	}
};