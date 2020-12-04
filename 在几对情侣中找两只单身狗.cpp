#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int main()
{
	int nums[8] = { 4, 1, 4, 6, 5,5,7,7};
	int numsSize = 8;
	int a = 0;
	for (int i = 0; i < numsSize; i++)
	{

		a = a^nums[i];
	}
	int b = 0;
	int c = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] % 2 == a % 2)
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