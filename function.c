#include<stdio.h>
#include<Windows.h>
#include<assert.h>
//模仿qsort实现的一个通用的冒泡排序
int compare(const void*p1, const void*p2)//比较的时候无法判断传的是空指针无法判断类型，也就无法比较，只能根据传入数据，设立比较函数的数据类型。
{
	int * q1 =(int*) p1;
	int * q2 =(int*) p2;
	if (*q1 > *q2)
	{
		return 1;
	}
	else if (*q1 < *q2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void swap(char*p1, char*p2,int size)
{
	for (int i = 0; i < size; i++)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		*p1++, *p2++;
	}
}
void My_qsort(void* arr, int num,int size ,int(*compare)(const void*,const void*))
{
	assert(arr != 0);
	assert(compare != 0);
	char*p = arr;
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (compare(p + j*size, p + (j+1)*size) > 0)
			{
				swap(p + j*size, p + (j + 1)*size,size);
				flag = 1;
			}
		}
	}
}
void Print(int *arr, int nume)
{
	for (int i = 0; i < nume; i++)
	{
		printf("%5d", *(arr+i));
	}
	printf("\n");
}
int main()
{
	int arr[] = { 2, 23, 56, 123, 456, 123, 1, 26, 89, 23, 1254, 1321, 369, 852, 147 };
	int num = (sizeof(arr) / sizeof(arr[0]));
	Print(arr, num);
	My_qsort(arr, num, sizeof(arr[0]), compare);
	Print(arr,num);
	system("pause");
}