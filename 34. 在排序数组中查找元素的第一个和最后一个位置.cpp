//34. 在排序数组中查找元素的第一个和最后一个位置
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回[-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//
//
//示例 1：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]
//示例 2：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 6
//输出：[-1, -1]
//示例 3：
//
//输入：nums = [], target = 0
//输出：[-1, -1]
//
//
//提示：
//
//0 <= nums.length <= 105
//- 109 <= nums[i] <= 109
//nums 是一个非递减数组
//- 109 <= target <= 109

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<stdio.h>
#include<Windows.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int* retarr = (int*)malloc(8);
	retarr[0] = -1;
	retarr[1] = -1;
	*returnSize = 2;
	//方法一：暴力遍历
	// for(int i=0;i<numsSize;i++)
	// {
	//     if(nums[i]!=target)
	//     {
	//         continue;
	//     }
	//     else if(retarr[0]==-1)
	//     {
	//         retarr[0]=i;
	//         retarr[1]=i;
	//     }
	//     else
	//     {
	//         retarr[1]=i;
	//     }
	// }
	// return retarr;

	//方法二：二分查找出其中一个，然后再分别向前，向后求证
	int left = 0, right = numsSize - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target<nums[mid])
		{
			right = mid - 1;
		}
		else if (nums[mid]<target)
		{
			left = mid + 1;
		}
		else
		{
			retarr[0] = mid;
			retarr[1] = mid;
			int midcopy = mid;
			//--------非二分查找---------
			while (target == nums[mid])
			{
				retarr[0] = mid;
				mid--;
				if (mid == left - 1)
				{
					break;
				}
			}
			mid = midcopy;
			while (target == nums[mid])
			{
				retarr[1] = mid;
				mid++;
				if (mid == right + 1)
				{
					break;
				}
			}
			//------非二分查找内容--------
			//return mid;
		}
	}
	return retarr;
}