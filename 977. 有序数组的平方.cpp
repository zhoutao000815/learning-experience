//977. 有序数组的平方
//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
//
//
//示例 1：
//
//输入：nums = [-4, -1, 0, 3, 10]
//输出：[0, 1, 9, 16, 100]
//解释：平方后，数组变为[16, 1, 0, 9, 100]
//排序后，数组变为[0, 1, 9, 16, 100]
//示例 2：
//
//输入：nums = [-7, -3, 2, 3, 11]
//输出：[4, 9, 9, 49, 121]
//
//
//提示：
//
//1 <= nums.length <= 104
//- 104 <= nums[i] <= 104
//nums 已按 非递减顺序 排序
//
//
//进阶：
//
//请你设计时间复杂度为 O(n) 的算法解决本问题
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/squares-of-a-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<Windows.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesort(int *arr, int numsSize)
{
	int end = numsSize;
	int flag = 1;
	while (numsSize>0)
	{
		for (int i = 0; i<numsSize - 1; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
		numsSize--;
	}
}
int* sortedSquares(int* nums, int numsSize, int* returnSize){
	*returnSize = numsSize;

	//方法一
	//笨比办法，平凡后再排序。（显然没有用到他们提供的有序。）
	// int *arr=(int *)malloc(sizeof(int)*numsSize);
	// int i=0;
	// while(i<numsSize)
	// {
	//     nums[i]=nums[i]*nums[i];
	//     i++;
	// }
	// bubblesort(nums,numsSize);
	// memcpy(arr,nums,sizeof(int)*numsSize);
	// return arr;
	//==================================================

	//方法二
	//先找到负数和非负数的分界线，再各自平方。然后合并两个有序数组，一个正序，一个逆序。
	//比较简单而且好理解，不写了。

	//方法三
	//直接平方，然后从两段同时开始比较大小，将大端逆序排放在malloc的数组里。
	int *arr = (int *)malloc(sizeof(int)*numsSize);
	int i = 0, j = numsSize - 1, pos = numsSize - 1;
	while (pos >= 0)
	{
		if (nums[j] * nums[j]>nums[i] * nums[i])
		{
			nums[j] = nums[j] * nums[j];
			arr[pos] = nums[j];
			j--;
		}
		else
		{
			nums[i] = nums[i] * nums[i];
			arr[pos] = nums[i];
			i++;
		}
		pos--;
	}
	return arr;
}