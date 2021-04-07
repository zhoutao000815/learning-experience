//剑指 Offer 42. 连续子数组的最大和
//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
//
//要求时间复杂度为O(n)。
//
//
//
//示例1 :
//
//输入 : nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//输出 : 6
// 解释 : 连续子数组[4, -1, 2, 1] 的和最大，为 6。
//
//
//
//
//	 来源：力扣（LeetCode）
//	 链接：https ://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//方法一:暴力遍历连续子数组求解
		//方法二:分治

		//方法三:动态规划
		int max = nums[0];
		for (int i = 1; i<nums.size(); i++)
		{
			if (nums[i - 1] <= 0)
			{
				//nums[i]=nums[i];
			}
			else    //nums[i-1]>0
			{
				nums[i] += nums[i - 1];
			}
			if (nums[i]>max)
			{
				max = nums[i];
			}
		}
		return max;
	}
};