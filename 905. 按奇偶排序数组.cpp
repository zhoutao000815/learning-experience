//905. 按奇偶排序数组
//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
//
//你可以返回满足此条件的任何数组作为答案。
//
//示例：
//
//输入：[3, 1, 2, 4]
//输出：[2, 4, 3, 1]
//输出[4, 2, 3, 1]，[2, 4, 1, 3] 和[4, 2, 1, 3] 也会被接受。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sort-array-by-parity
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<Windows.h>

int* sortArrayByParity(int* A, int ASize, int* returnSize){
	*returnSize = ASize;
	int *arr = (int *)malloc(sizeof(int)*ASize);
	int i;
	int prev = 0, next = ASize - 1;
	for (i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			arr[prev++] = A[i];
		}
		else
		{
			arr[next--] = A[i];
		}
	}
	return arr;
}
float func(float a, int b)
{
	float m = 1, n = 1;
	int i;
	for (i = 1; i <b; i++)
	{
		m *= a / i;
		n += m;
	}
	return n;
}
int main()
{
	//char *p = "abcdef", *r;
	//long *q;
	//q = (long*)p;
	//q++;
	//r = (char*)q;
	//long m = 25345;
	//printf("%s\n", r);

	printf("%f\n", func(2, 5));
	system("pause");
}