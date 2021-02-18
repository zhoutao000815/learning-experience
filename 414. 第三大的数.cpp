//414. 第三大的数
//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
//
//示例 1：
//输入：[3, 2, 1]
//输出：1
//解释：第三大的数是 1 。
//
//示例 2：
//输入：[1, 2]
//输出：2
//解释：第三大的数不存在, 所以返回最大的数 2 。
//
//示例 3：
//输入：[2, 2, 3, 1]
//输出：1
//解释：注意，要求返回第三大的数，是指第三大且唯一出现的数。
//存在两个值为2的数，它们都排第二。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/third-maximum-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

<<<<<<< HEAD
//博客链接：https://blog.csdn.net/Zhou000815/article/details/113848563

=======
>>>>>>> 26d67e71e68c7c98e9928228bbe83820bd3912dc
#include<stdio.h>
#include<Windows.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int thirdMax(int* nums, int numsSize){
	//方法一：基于选择排序的三次选择数字，时间复杂度（3n）
	int i = 0;               //记录当前位置下标。
	int echo = 0;            //记录前三组数字里，每一组数字的重复次数。（比如一个数字出现两次，那就是重复一次）。
	int ret = 3;             //用来控制选出三大数字，假设数组不重复并且大于3.
	int thirdgroupMax = 0;   //记录选出了第几大
	while (i<ret  && i<numsSize)      //既要保证只选出正确位置的，又要保证不越界。
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if (nums[i] <= nums[j])      //遇到》=当前数的，要分别处理。
			{
				if (nums[i] == nums[j])        //等于的要排成一组，排在当前数的后面，
				{
					echo++;                //当前数的重复次数
					ret++;                 //一旦前三名里出现重复，就要给选出的第三大++，保证下标正确
					swap(&nums[i + echo], &nums[j]);     //有一点瑕疵，i+echo可能会等于j。加个判断退出即可，
					continue;
				}
				swap(&nums[i], &nums[j]);      //遇到大数字，只和当前数交换，
			ret -= echo;	echo = 0;         //这一行可有可无，但是加上后会排出前三大的序列，不加，只能选出第三大的数字。
			}                          
		}
		i += echo + 1;                      //下一个位置，应该是当前这一组的下一个位置
		echo = 0;                           //下一组了，重复清零
		thirdgroupMax++;                    //一组数字完毕，确认找出了一个大数字
	}
	if (thirdgroupMax<3)                    //没有第三大，返回最大值
	{
		return nums[0];
	}
	else                                    //返回第三大
	{
		return nums[ret - 1];
	}
	
	//方法二:用堆选数字也可以，但是写起来会比较麻烦。时间复杂度（n * log n）
}
int main()
{
	int arr[] = { 5, 5, 5, 5, 6, 6, 6, 7, 7, 7 };
	thirdMax(arr, 10);	for (int m = 0; m<10; m++)
	{
		printf("%3d", arr[m]);
	}
	printf("\n");
	system("pause");
}