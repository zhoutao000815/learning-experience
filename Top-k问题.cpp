//博客链接：https://blog.csdn.net/Zhou000815/article/details/112638509
//面试题 17.14.最小K个数（剑指offer）
//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
//
//示例：
//
//输入： arr = [1, 3, 5, 7, 2, 4, 6, 8], k = 4
//输出：[1, 2, 3, 4]
//提示：
//
//0 <= len(arr) <= 100000
//0 <= k <= min(100000, len(arr))
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/smallest-k-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//======================================================================
//记住！求最小的前k个，建立大堆!求最大的前k个，建立小堆!
//======================================================================
//思路3：求前k个最小值，我们建立一个k个数字的大堆，将第k+1（下标为k）个数据和堆顶比较，小于堆顶则交换，再向下调整算法入堆。
//       全部数据比较完毕，堆里的k个数据就是要求的数据，但是不是完全有序的。至于为什么？看下面。
//		 想一下，求最小的，我们建立大堆，大堆下面都是比他大的，最后结果大堆堆顶是最小的，  倒着推算，
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *a1, int *a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void ADJustDown(int *arr, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child<n)
	{
		if (child + 1<n && arr[child + 1]>arr[child])
		{
			child++;
		}
		if (arr[parents]<arr[child])
		{
			swap(&arr[parents], &arr[child]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
int* smallestK(int* arr, int arrSize, int k, int* returnSize){
	*returnSize = k;
	int *reterarr = (int *)malloc(sizeof(int)*k);
	if (k == 0)
	{
		return reterarr;
	}
	memcpy(reterarr, arr, k*sizeof(int)); //题目要求返回的数组必须mallocd，所以copy一下。
	int lastparents = (k - 1 - 1) / 2;  //堆排序算法里详细讲解了。
	for (int i = lastparents; i >= 0; i--)//建堆
	{
		ADJustDown(reterarr, k, i);
	}
	for (int j = k; j<arrSize; j++)//剩余数据比较，
	{
		if (arr[j]<reterarr[0])
		{
			swap(&arr[j], &reterarr[0]);
			ADJustDown(reterarr, k, 0);
		}
	}
	return reterarr;
}
int main()
{
	int arr[8] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int arrSize = 8;
	int k = 4;
	int returnsize = 0;
	int * returnSize = &returnsize;
	int *returnarr=smallestK(arr, arrSize, k, returnSize);
	for (int i = 0; i < k; i++)
	{
		printf("%7d", returnarr[i]);
	}
	printf("\n");
	system("pause");
}