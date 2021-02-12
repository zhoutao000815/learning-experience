//88. 合并两个有序数组
//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//示例 2：
//
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
//
//
//提示：
//
//nums1.length == m + n
//nums2.length == n
//0 <= m, n <= 200
//1 <= m + n <= 200
//- 109 <= nums1[i], nums2[i] <= 109
//nums1.length == m + n
//nums2.length == n
//0 <= m, n <= 200
//1 <= m + n <= 200
//- 109 <= nums1[i], nums2[i] <= 109
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

void reverse(int *sum1, int *sum2)
{
	int temp = 0;
	temp = *sum1;
	*sum1 = *sum2;
	*sum2 = temp;
}
void bubble(int *arr, int arrSize)
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
	//方法一：合并后排序
	// int msize=0;
	// for(int i=m;i<m+n;i++)
	// {
	//     nums1[i]=nums2[msize];
	//     msize++;
	// }
	// bubble( nums1,m+n);

	//方法二：双指针
	int* arr = (int *)malloc(4 * (m + n));
	int i = 0;
	int j = 0;
	int k = 0;
	while (m != 0 && n != 0)
	{
		if (nums1[i]<nums2[j])
		{
			arr[k++] = nums1[i++];
			m--;
		}
		else//(nums2[j]<=nums1[i])
		{
			arr[k++] = nums2[j++];
			n--;
		}
	}
	while (m != 0)
	{
		arr[k++] = nums1[i++];
		m--;
	}
	while (n != 0)
	{
		arr[k++] = nums2[j++];
		n--;
	}
	memcpy(nums1, arr, nums1Size * 4);
}