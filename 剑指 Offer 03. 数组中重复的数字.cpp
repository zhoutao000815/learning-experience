//剑指 Offer 03.找出数组中重复的数字。
//
//
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//
//示例 1：
//
//输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3
//
//
//限制：
//
//2 <= n <= 100000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//博客:https://blog.csdn.net/Zhou000815/article/details/114984124

int findRepeatNumber(int* nums, int numsSize){
	//方法一：n²遍历  超时不可取
	// int rel=0;
	// int flag=0;
	// for(int i=0;i<numsSize;i++)
	// {
	//     for(int j=i+1;j<numsSize;j++)
	//     {
	//         if(nums[j]==nums[i])
	//         {
	//             flag=1;
	//             rel=nums[i];
	//             break;
	//         }
	//     }
	//     if(1==flag)
	//     {
	//         break;
	//     }
	// }
	// return rel;

	//方法二：计数排序
	int max = nums[0];
	int min = nums[0];
	int ret = 0;
	for (int i = 1; i<numsSize; i++)
	{
		if (nums[i]>max)
		{
			max = nums[i];
		}
		if (nums[i]<min)
		{
			min = nums[i];
		}
	}
	int* arr = calloc(max - min + 1, sizeof(int));
	for (int j = 0; j<numsSize; j++)
	{
		arr[nums[j] - min]++;
		if (arr[nums[j] - min]>1)
		{
			ret = nums[j];
			break;
		}
	}
	return ret;

	//方法二：优化版本。（注意题目信息：长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内）
	//这表示不需要求出最大最小值来确定排序数组长度，直接用原数组大小计数即可。
	int ret = 0;
	int* arr = calloc(numsSize, sizeof(int));
	for (int j = 0; j<numsSize; j++)
	{
		arr[nums[j]]++;
		if (arr[nums[j]]>1)
		{
			ret = nums[j];
			break;
		}
	}
	return ret;
}