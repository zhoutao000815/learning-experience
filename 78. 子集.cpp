//78. 子集
//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 3]
//输出：[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//示例 2：
//
//输入：nums = [0]
//输出：[[], [0]]
//
//
//提示：
//
//1 <= nums.length <= 10
//- 10 <= nums[i] <= 10
//nums 中的所有元素 互不相同

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/subsets/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<iostream>
#include<Windows.h>
using namespace std;
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int ** arrs = (int**)malloc(sizeof(int *)*(1 << numsSize));//一个nums、有numsSize个数字，就有2的numsSize次方个子集。所以开辟相应多少指针的大小
	*returnSize = 1 << numsSize;     //返回的数组个数
	*returnColumnSizes = (int *)malloc(sizeof(int)*(1 << numsSize));   //返回每个数组的大小
	int arr[numsSize];                 //每一个子集的上限大小为numsSize个，但是我们malloc开辟大小又不知道每一个子集具体多少个数字，
	//所以干脆直接开辟一个上限大小的数组，检测子集元素，并计数后，再malloc，拷贝。
	for (int i = 0; i<(1 << numsSize); i++)   //组数控制
	{
		int arrsize = 0;
		for (int j = 0; j<numsSize; j++)     //每一组子集元素大小控制
		{
			if (i & (1 << j))           //元素检测，如果对应组数i的二进制的第j位为1，说明第j位的数字出现过，进入子集。//看不懂去看官方题解
			{
				arr[arrsize++] = nums[j];
			}
		}
		int *temp = (int *)malloc(sizeof(int)*arrsize);
		memcpy(temp, arr, sizeof(int)*arrsize);
		(*returnColumnSizes)[i] = arrsize;  //子集大小
		arrs[i] = temp;                     //子集地址拷贝
	}
	return arrs;
}