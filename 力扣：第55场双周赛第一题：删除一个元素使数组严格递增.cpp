﻿//5780. 删除一个元素使数组严格递增
//给你一个下标从 0 开始的整数数组 nums ，如果 恰好 删除 一个 元素后，数组 严格递增 ，那么请你返回 true ，否则返回 false 。如果数组本身已经是严格递增的，请你也返回 true 。
//
//数组 nums 是 严格递增 的定义为：对于任意下标的 1 <= i < nums.length 都满足 nums[i - 1] < nums[i] 。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 10, 5, 7]
//输出：true
//解释：从 nums 中删除下标 2 处的 10 ，得到[1, 2, 5, 7] 。
//[1, 2, 5, 7] 是严格递增的，所以返回 true 。
//示例 2：
//
//输入：nums = [2, 3, 1, 2]
//输出：false
//解释：
//[3, 1, 2] 是删除下标 0 处元素后得到的结果。
//[2, 1, 2] 是删除下标 1 处元素后得到的结果。
//[2, 3, 2] 是删除下标 2 处元素后得到的结果。
//[2, 3, 1] 是删除下标 3 处元素后得到的结果。
//没有任何结果数组是严格递增的，所以返回 false 。
//示例 3：
//
//输入：nums = [1, 1, 1]
//输出：false
//解释：删除任意元素后的结果都是[1, 1] 。
//[1, 1] 不是严格递增的，所以返回 false 。
//示例 4：
//
//输入：nums = [1, 2, 3]
//输出：true
//解释：[1, 2, 3] 已经是严格递增的，所以返回 true 。
//
//
//提示：
//
//2 <= nums.length <= 1000
//1 <= nums[i] <= 1000

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-one-element-to-make-the-array-strictly-increasing
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路：双指针，找到两个不符合递增条件的就返回false，没找到就返回true。
class Solution {
public:
	bool canBeIncreasing(vector<int>& nums) {
		int prev = 0;
		int cur = 1;
		while (cur != nums.size())
		{
			if (nums[prev] >= nums[cur])    //第一个不符合递增条件的
			{
				//判断一下是   1  8  2   类型，还是  3  5  2  6  类型  ，调整指向；方便找下一个不符合递增条件的。
				if (prev == 0 || nums[cur]>nums[prev - 1])
				{
					prev++;
				}
				cur++;

				while (cur != nums.size() && nums[prev]<nums[cur])
				{
					prev = cur;
					cur++;
				}
				return cur == nums.size();     //可能只找到一个，
			}
			prev++;
			cur++;
		}
		return true;
	}
};