#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//
//
//
//说明：
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//
//
//示例：
//
//输入：
//nums1 = [1, 2, 3, 0, 0, 0], m = 3
//nums2 = [2, 5, 6], n = 3
//
//输出：[1, 2, 2, 3, 5, 6]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//方法一：合并排序法
void reverse(int *sum1, int *sum2)
{
	int temp = 0;
	temp = *sum1;
	*sum1 = *sum2;
	*sum2 = temp;
}
void bubble(int *nums1, int nums1Size)//冒泡排序：给定数字找位置
{
	int flag = 1;
	for (int i = 0; i<nums1Size-1; i++)
	{
		for (int j = 0; j<nums1Size - i-1; j++)
		{
			if (*(nums1 + j)>*(nums1 + j + 1))
			{
				reverse(nums1 + j, nums1 + j + 1);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
void bubble2(int *arr, int arrSize)//选择排序：给定位置找数字
{
	for (int i = 0; i<arrSize - 1; i++)
	{
		for (int j = i; j<arrSize - 1; j++)
		{
			if (*(arr + i)>*(arr + j + 1))
			{
				reverse(arr + i, arr + j + 1);
			}
		}
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int msize = 0;
	for (int i = m; i<m + n; i++)
	{
		nums1[i] = nums2[msize];
		msize++;
	}
	bubble(nums1, m + n);
}
//方法二：双指针法
int main()
{
	int k = 3;
	int nums1[14] = { 1, 2, 3, 4, 5, 6, 7 };
	int nums2[7] = { 1, 1, 3, 4, 6, 6, 8 };
	int nums1Size = 14;
	int nums2Size = 7;
	int m = 7, n = 7;
	merge(nums1, nums1Size,  m,  nums2,  nums2Size,  n);

	for (int i = 0; i < 14; i++)
	{
		printf("%d\n", *(nums1 + i));
	}
	system("pause");
}