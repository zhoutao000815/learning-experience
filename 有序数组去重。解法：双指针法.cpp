#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//
//给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//
//你不需要考虑数组中超出新长度后面的元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解法：双指针法
//用两个数组下标 pl pr，判断是否重复，重复跳过，下一组，不重复，把左边的值赋给新数组下标，新数组下标++。最后两个数字，是关键。
int removeDuplicates(int* nums, int numsSize){
	if (numsSize == 0)
	{
		return numsSize;
	}
	int pl = 0, pr = 1, newnums = 0;
	while (pr < numsSize)//注意，快右指针pr，是不能越界访问的。
	{
		if (nums[pl] == nums[pr])
		{
			pl++;
			pr++;
		}
		else
		{
			nums[newnums] = nums[pl];//而我们是把左边的值赋给了新数组。
			pl++;
			pr++;
			newnums++;
		}
	}
	nums[newnums] = nums[numsSize-1];
	//最后两个数字的右值，虽然进行了判断，相同跳过了一个也没保留，不相同又只保留了左边的。
	//所以把最后一个数字直接赋给新数组就好。不论相不相同，都能满足。
	//这里写成nums[newnums] = nums[pr]；可以吗？
	//答案：不可以，最后两个数字判断过后，进行了++。再使用就越界了。
	newnums++;
	return newnums;
}
int main()
{
	int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 ,4,5};
	int numsSize = 12;

	int rel = removeDuplicates(nums,numsSize);
	for (int i = 0; i < rel; i++)
	{
		printf("%d\n", *(nums + i));
	}

	system("pause");
}