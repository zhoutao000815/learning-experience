//189. 旋转数组
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//进阶：
//
//尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
//
//
//示例 1:
//
//输入 : nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//
//	示例 2 :
//
//	输入：nums = [-1, -100, 3, 99], k = 2
//	输出：[3, 99, -1, -100]
//解释 :
//   向右旋转 1 步 : [99, -1, -100, 3]
//   向右旋转 2 步 : [3, 99, -1, -100]
//
//   提示：
//   1 <= nums.length <= 2 * 104
//   - 231 <= nums[i] <= 231 - 1
//   0 <= k <= 105
//
//   来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/rotate-array
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
void reverse(int *arr, int arrSize)
{
	int temp = 0;
	arrSize = arrSize - 1;
	for (int i = 0; i < arrSize / 2 + arrSize % 2; i++)
	{
		temp = *(arr + arrSize - i);
		*(arr + arrSize - i) = *(arr + i);
		*(arr + i) = temp;
	}
}
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
void rotate(int* nums, int numsSize, int k){
	//方法一：暴力法（k次旋转法）---超时。
	//---------------------------------
	/*k=k%numsSize;
	int temp=0;
	for(int i=0;i<k;i++)
	{
	temp=nums[numsSize-1];
	for(int j=numsSize-1;j>0;j--)
	{
	nums[j]=nums[j-1];
	}
	nums[0]=temp;
	}*/
	//---------------------------------

	//方法二：额外空间法
	//-------------------------------------------------
	//申请额外k个空间arr，存放原数组 后k 个数据
	//再往右挪动原数组的数据k步，再将arr填充到 前n-k 个数据里。
	// k=k%numsSize;
	// int *arr=(int *)malloc(k*sizeof(nums[0]));
	// if(arr!=NULL)
	// {
	// int Size=0;
	// for(int i=numsSize-k;i<numsSize;i++)
	// {
	//     *(arr+Size)=nums[i];
	//     Size++;
	// }
	// for(int j=numsSize-1-k;j>=0;j--)
	// {
	//     nums[j+k]=nums[j];
	// }
	// for(int m=0;m<k;m++)
	// {
	//     nums[m]=*(arr+m);
	// }   
	// }
	//可以申请好k个int的空间，然后用三次memcpy搞定。
	//-------------------------------------------------

	//方法三：环状替换
	//递归法
	//-------------------------------------------------
	// k=k%numsSize;
	// if(k==0)
	// {
	//     return ;  //当k是numsize的整数倍无需旋转，退出返回原数组即可
	// }
	// int times=0;
	// while(times<k)
	// {
	//     for(int i=times;i<numsSize;i+=k)
	//     {
	//         if(i+k<numsSize)
	//         {
	//             swap(&nums[times],&nums[i+k]); 
	//         }
	//         else
	//         {
	//             break;
	//         }
	//     }
	//     times++;
	// }
	// int nextk=0;
	// if(numsSize%k==0)
	// {
	//     return;     //递归出口：没有余数。
	// }
	// else
	// {
	//     nextk=k-numsSize%k;
	//     rotate(nums,k,nextk);
	// }
	//-------------------------------------------------
	//-------------------------------------------------
	//循环迭代法
	//-------------------------------------------------
	k = k%numsSize;
	if (k == 0)
	{
		return;
	}
	int count = gcd(numsSize, k);
	int group = 0;
	while (group<count)
	{
		for (int i = group + k; 1; i += k)
		{
			if (i%numsSize != group)
			{
				swap(&nums[group], &nums[i%numsSize]);
			}
			else
			{
				break;
			}
		}
		group++;
	}
	//-------------------------------------------------
	/*
	//方法四：三次反转
	//-------------------------------------------------
	k=k%numsSize;
	//第一次反转：整个数组反转。
	reverse(nums,numsSize);
	//第二次反转：反转k个数字。
	reverse(nums,k);
	//第三次反转：反转numsize-k个。
	reverse(nums+k,numsSize-k);
	*/
	//-------------------------------------------------
}