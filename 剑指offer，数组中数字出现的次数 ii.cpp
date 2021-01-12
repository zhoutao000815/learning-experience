//博客链接：https://blog.csdn.net/Zhou000815/article/details/112511583
//剑指 Offer 56 - II.数组中数字出现的次数 II
//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
//
//
//
//示例 1：
//
//输入：nums = [3, 4, 3, 3]
//输出：4
//示例 2：
//
//输入：nums = [9, 1, 7, 9, 7, 9, 7]
//输出：1
//
//
//限制：
//
//1 <= nums.length <= 10000
//1 <= nums[i] < 2 ^ 31
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	int nums[7] = { 9, 1, 7, 9, 7, 9, 7 };
	int numsSize = 7;
	//进行位操作。
	int bitmax = 32;
	int rel = 0;  //余数
	int count = 0;  //统计结果
	int result = 0;  //由余数加起来的最终结果
	for (int i = 0; i<32; i++)
	{
		for (int j = 0; j<numsSize; j++)
		{
			if ((nums[j] >> i) & 1)   //将数字右移i位与1‘相与’，得到第i位是否为1，
			{
				count++;   //对应第i个比特位上的统计结果
			}
		}
		if (count % 3)   //取余数，得到出现一次数字的第i位比特位的0 或1。
		{
			rel |= (1 << i);   // 用0和这个得到对应第i位比特位的余数‘相或’，得到对应的十进制数。
		}
		result += rel;  //将出现一次数字的每一个比特位上对应余数的十进制数字相加，即是最终结果。
		rel = 0;
		count = 0;
	}
	printf("%d\n", result);
	//return result;
	system("pause");
}