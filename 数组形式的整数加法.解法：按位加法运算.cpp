#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){	
	//将数字K和数组A中每一个数字相加，然后取10的模赋给该数字所在的位置。
	//如果A大，k被加完，如果K大，则剩余的加给给A[0],
	//对A[0]取模运算，算出A[0]长度，加上除A[0]以外的数字，算出新数组长度，将a[0]和剩余的数字。分两组赋给新数组每一位。												
	if (A[0] == 0 && K == 0)//检测特殊情况
	{		
		*returnSize = 1;
		int *arr = (int*)malloc(4);
		arr[0] = 0;
		return arr;
	}
	for (int i = ASize - 1; i >= 0; i--)
	{
		int add = A[i] + K;
		if (i == 0)
		{
			A[i] = add;
		}
		else
		{
			A[i] = add % 10;
			K = add / 10;
		}
	}
	int A0size = 0;
	int A0copy = A[0];
	while (A0copy)
	{
		A0copy /= 10;
		A0size++;
	}
	int XKsize = A0size + ASize - 1;
	*returnSize = XKsize;
	int *arr = (int*)malloc(sizeof(int)*XKsize);
	if (arr != NULL)
	{
		int j = 1;
		for (int i = ASize - 1; i>0; i--)
		{

			arr[XKsize - j] = A[i];
			j++;
		}
		for (int i = A0size - 1; i >= 0; i--)
		{
			arr[XKsize - j] = A[0] % 10;
			A[0] /= 10;
			j++;
		}
	}
	return arr;
}
int main()
{
	int A[] = { 2,1,5 };
	int ASize = 3;
	int K = 806;
	int returnSize;
	int *arr=addToArrayForm(A, ASize, K, &returnSize);
	for (int i = 0; i < returnSize; i++)

	{
		printf("%d\n",*(arr+i));
	}

	system("pause");
}