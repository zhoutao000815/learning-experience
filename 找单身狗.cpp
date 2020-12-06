#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int main()
{
	int nums[8] = { 4, 1, 4, 6};
	int numsSize = 8;
	int a = 0;
	for (int i = 0; i < numsSize; i++)//所有数字异或，相同数字异或为0，最后结果为不同两个数字的异或结果a。
	{

		a = a^nums[i];
	}
	int b = 0;
	int c = 0;
	//找到a的最低位为1的那一项，用这个分开两个数字。
	int flag = 1;
	while ((a & flag) == 0)//注意按位与“&”和判断操作符“==”的优先级
	{
		flag = flag << 1;//左移确定最低位
	}
	printf("%d\n", flag);
	for (int i = 0; i < numsSize; i++)//与flag相与&，分成两组，b、c。
	{
		if ((nums[i]& flag) ==0)//注意按位与“&”和判断操作符“==”的优先级
		{
			b = b^nums[i];

		}
		else
		{
			c = c^nums[i];

		}
	}
	printf("%d  %d", b, c);
	system("pause");
}