//209. 长度最小的子数组
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//
//
//
//示例 1：
//
//输入：target = 7, nums = [2, 3, 1, 2, 4, 3]
//输出：2
//解释：子数组[4, 3] 是该条件下的长度最小的子数组。
//示例 2：
//
//输入：target = 4, nums = [1, 4, 4]
//输出：1
//示例 3：
//
//输入：target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
//输出：0
//
//
//提示：
//
//1 <= target <= 109
//1 <= nums.length <= 105
//1 <= nums[i] <= 105

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		// 解法一：暴力法
		// 超时
		// int add=0;
		// int addlenth=0;
		// int Minaddlenth=nums.size()+1;
		// bool HaveRet=false;
		// for(int i=0;i<nums.size();i++)
		// {
		//     add=0;
		//     for(int j=i;j<nums.size();j++)
		//     {
		//         add+=nums[i];
		//         if(add>=target)
		//         {
		//             HaveRet=true;
		//             addlenth=j-i+1;
		//             Minaddlenth=(Minaddlenth<addlenth?Minaddlenth:addlenth);
		//         }
		//     }
		// }
		// if(HaveRet)
		// {
		//     return Minaddlenth;
		// }
		// return 0;
		//=====================================================================
		//解法二:滑动窗口
		int subarrsize = nums.size() + 1;  //长度可能为数组长度+1；方便找出长度最小子数组
		int add = 0, addlenth = 0;
		int left = 0;
		for (int right = 0; right<nums.size(); right++)
		{
			add += nums[right];
			while (add >= target)       //窗口精髓部分
			{
				addlenth = right - left + 1;
				subarrsize = (subarrsize<addlenth ? subarrsize : addlenth);
				add -= nums[left++];          //减去左边的值，并且向右移动左指针。
			}
		}
		return subarrsize = (subarrsize == nums.size() + 1 ? 0 : subarrsize);
	}
};