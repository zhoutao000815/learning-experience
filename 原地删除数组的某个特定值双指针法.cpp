#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//
//
//示例 1:
//
//给定 nums = [3, 2, 2, 3], val = 3,
//
//函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//
//你不需要考虑数组中超出新长度后面的元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-element
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//解法1：双数组下标=双指针。
int removeElement(int* nums, int numsSize, int val){

	int pl = 0, pr = 0;//开始时指向同一位置，快指针pr挨个检测，遇到要删除的值，直接下一个，遇到要保留的非val，把pr赋给pl，pl最后的值，即为新数组个数。
	while (numsSize--)
	{
		if (nums[pr] == val)
		{
			pr++;
		}
		else
		{
			nums[pl] = nums[pr];
			pr++;
			pl++;
		}
	}
	return pl;
}
int main()
{
	int nums[] = { 3, 2, 2, 3, 5, 3 };
	int numsSize = 6;
	int val = 3;
	int rel=removeElement(nums, numsSize, val);
	for (int i = 0; i < rel; i++)
	{
		printf("%d\n", *(nums + i));
	}

	system("pause");
}