//724. 寻找数组的中心索引
//给你一个整数数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
//
//数组 中心索引 是数组的一个索引，其左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果数组不存在中心索引，返回 - 1 。如果数组有多个中心索引，应该返回最靠近左边的那一个。
//
//注意：中心索引可能出现在数组的两端。
//
//
//
//示例 1：
//
//输入：nums = [1, 7, 3, 6, 5, 6]
//输出：3
//解释：
//中心索引是 3 。
//左侧数之和(1 + 7 + 3 = 11)，
//右侧数之和(5 + 6 = 11) ，二者相等。
//示例 2：
//
//输入：nums = [1, 2, 3]
//输出： - 1
//解释：
//数组中不存在满足此条件的中心索引。
//示例 3：
//
//输入：nums = [2, 1, -1]
//输出：0
//解释：
//中心索引是 0 。
//索引 0 左侧不存在元素，视作和为 0 ；
//右侧数之和为 1 + (-1) = 0 ，二者相等。

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-pivot-index/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<stdio.h>
#include<Windows.h>
int pivotIndex(int* nums, int numsSize){
	int numsAdd = 0;
	for (int i = 0; i<numsSize; i++)//求整个数组和
	{
		numsAdd += nums[i];
	}
	int key = 0;
	int leftAdd = 0;
	int rightAdd = numsAdd - nums[key];
	while (leftAdd != rightAdd && key<numsSize)//用总和减掉一个数，这个数就是key，key的左和，右和，都可以记录。
	{
		leftAdd += nums[key];
		key++;
		if (key == numsSize)  //没找到
		{
			return -1;
		}
		rightAdd -= nums[key];
	}
	return key;
}