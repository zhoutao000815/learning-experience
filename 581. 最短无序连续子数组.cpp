//581. 最短无序连续子数组
//给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
//请你找出符合题意的 最短 子数组，并输出它的长度。
//
//
//
//示例 1：
//
//输入：nums = [2, 6, 4, 8, 10, 9, 15]
//输出：5
//解释：你只需要对[6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
//示例 2：
//
//输入：nums = [1, 2, 3, 4]
//输出：0
//示例 3：
//
//输入：nums = [1]
//输出：0
//
//
//提示：
//
//1 <= nums.length <= 104
//- 105 <= nums[i] <= 105
//
//
//进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/submissions/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<iostream>
#include<Windows.h>
using namespace std;

// 堆排序
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void AdjustDwon(int* a, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parents] < a[child])
		{
			Swap(&a[parents], &a[child]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//===建堆===
	int lastchild = n - 1;
	int lastparents = (lastchild - 1) / 2;
	for (int i = lastparents; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//===堆排序===
	int end = n - 1;
	while (end >= 1)
	{
		Swap(&a[0], &a[end]);  //end代表数组中最后一个元素的下标
		AdjustDwon(a, end, 0);  //end代表数组中剩下的有效数据个数
		end--;
	}
}
int findUnsortedSubarray(int* nums, int numsSize){
	//方法一：暴力遍历比较（需要考虑的情况太多了，需要细节把控）
	//分别从左边右边确立一个有序数列出来，找到无序的边界，中间的无序子序列可能就是答案
	if (numsSize == 1)
	{
		return 0;
	}
	int begin1 = 0, begin2 = 1;  //左双指针
	int end1 = numsSize - 2, end2 = numsSize - 1; //右双指针
	int left = begin1, right = end2;  //两个边界
	bool haveRet = false;   //确定是否需要排序的指示值
	//以上是基本变量定义
	int echo1 = 0;     //存在相同数字，需要计数并跳过
	while (begin1<end2)  //左序列边界
	{
		if (nums[begin1] >= nums[begin2])
		{
			if (nums[begin1] == nums[begin2])
			{
				echo1++;
				begin1++;
				begin2++;
				continue;
			}
			left = begin1 - echo1;
			haveRet = true;   //一旦找到了无序的就是有需要调整的子序列，就有答案。返回非0.
			break;
		}
		else
		{
			begin1++;
			begin2++;
			echo1 = 0;
			continue;
		}
	}
	int echo2 = 0;
	while (begin1<end2 && haveRet)  //右序列边界
	{
		if (nums[end1] >= nums[end2])
		{
			if (nums[end1] == nums[end2])
			{
				echo2++;
				end1--;
				end2--;
				continue;
			}
			right = end2 + echo2;
			break;
		}
		else
		{
			end1--;
			end2--;
			echo2 = 0;
			continue;
		}
	}
	if (!haveRet)  //没有答案返回0.
	{
		return 0;
	}
	int max = left, min = left, k = left;  //确定中间无序数组的最大值和最小值
	while (k <= right)
	{
		if (nums[max]<nums[k])
		{
			max = k;
		}
		if (nums[min]>nums[k])
		{
			min = k;
		}
		k++;
	}
	int leftcopy = left;         //拷贝一下，作为循环边界依据
	int leftcopy2 = left;        //
	//接下来就是最重要的情况处理了，
	//情况1【5，6，1，2，3，4】：这种情况下，（下标）left=1，right=2.但是，调整这两个数就能有序吗？显然不行，我们需要右序列的所有值大于左序列，我们拿右序列的边界（最小值）作为比较依据，确保左序列left之前所有值小于右。但是仅仅拿右边界比较够吗?看下面这种情况
	//情况2【4，5，6，0，2，1，3，7，8】//这种情况下，即使左序列减到0，右序列right=5，但是（右子序列）right后还有数字小于左序列，这时就要确认右序列的边界，然后就有第二个循环rightcopy。这时左右边界出来了，
	//但是中间的无序子序列呢?如果这个无序子序列中最小的数小于左序列中的任何一个值呢？最大值和右序列呢？
	//情况三:【4，5，6，2，1，0，9，3，7，8】这又该怎么办？我们找出中间无序序列的最大最小值，最小值在左序列寻找合适的位置，最大值在右边找

	while (leftcopy >= 0)
	{
		if (nums[leftcopy]>nums[right] || nums[min]<nums[leftcopy])  // 左边：确立左边界|| 右边：确立中间无序子序列的最小值位置
		{
			left = leftcopy;
		}
		leftcopy--;
	}
	int rightcopy = right;
	while (rightcopy<numsSize)
	{
		if (nums[leftcopy2]>nums[rightcopy] || nums[max]>nums[rightcopy])  //类似于左边情况）
		{
			right = rightcopy;
		}
		rightcopy++;
	}
	return right - left + 1;

	//方法二:排序后前后比较，找出不同位，相减+1.
	// int *arr=(int *)malloc(numsSize*sizeof(int));
	// memcpy(arr,nums,numsSize*sizeof(int));
	// HeapSort(arr,numsSize);
	// int i=0,j=numsSize-1;
	// while(nums[i]==arr[i])
	// {
	//     i++;
	//     if(i==numsSize)
	//     return 0;
	// }
	// while(nums[j]==arr[j])
	// {
	//     j--;
	//     if(j==-1)
	//     return 0;
	// }
	// return j-i+1;

	//方法三：利用栈的特性设立边界进行比较
}