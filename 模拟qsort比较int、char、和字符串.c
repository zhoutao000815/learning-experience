#include<stdio.h>
#include<Windows.h>
#include<assert.h>
//模仿qsort实现的一个通用的冒泡排序
int intcompare(const void*p1, const void*p2)//比较的时候无法判断传的是空指针无法判断类型，也就无法比较，只能根据传入数据，设立比较函数的数据类型。
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
int charcompare(const void*p1, const void*p2)//比较的时候无法判断传的是空指针无法判断类型，也就无法比较，只能根据传入数据，设立比较函数的数据类型。
{
	char * q1 = (char*)p1;
	char * q2 = (char*)p2;
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
int MY_strcmp(const void*p1, const void*p2)
{
	char*P1 = (char*)p1;
	char*P2 = (char*)p2;
	int rel = 0;
	while (!(rel = *(unsigned char*)P1 - *(unsigned char*)P2) && *P1)
	{
		P1++;
		P2++;
	}
	if (rel>0)
	{
		return 1;
	}
	else if (rel<0)
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
int cmp(const void*p1, const void*p2)
{
	return strcmp((char*)p1, (char*)p2);
}
void My_qsort(void* arr, int num,int size ,int(*compare)(const void*,const void*))
{
	assert(arr != 0);
	assert(compare != 0);
	char*p = arr;
	int flag = 1;
	for (int i = 0; i < num - 1; i++)
	{	
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (compare(p + j*size, p + (j + 1)*size) > 0)
			{
				swap(p + j*size, p + (j + 1)*size,size);
				flag = 0;
			}
		}
		if (flag)
		{
			printf("已经有序！\n");
			return;
		}
	}
}
void intPrint(int *arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%5d", *(arr + i));
	}
	printf("\n");
}
void charPrint(char *arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%5c", *(arr + i));
	}
	printf("\n");
}
void strPrint(char (*arr)[7], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", *(arr+i));
	}
	printf("\n");
}
int main()
{
	//int arr[] = { 13, 36, 78, 56, 36, 12, 66 };
	//int num = (sizeof(arr) / sizeof(arr[3]));
	//intPrint(arr, num);
	//My_qsort(arr, num, sizeof(arr[0]), intcompare);
	//intPrint(arr, num);

	//char arr[] = { "dcfeabhgkilj" };
	//int num = (sizeof(arr) / sizeof(arr[0]));
	//charPrint(arr, num);
	//My_qsort(arr, num, sizeof(arr[0]), charcompare);
	//charPrint(arr, num);

	char arr[6][7] = { "abc456", "abc123", "abcd3", "abcd2", "abcd1","1bad" };//只能用二维数组吗？不能写成char *arr[6]吗?
	int num = (sizeof(arr) / sizeof(arr[0]));
	strPrint(arr, num);
	My_qsort(arr, num, sizeof(arr[0]),MY_strcmp);
	strPrint(arr,num);

	system("pause");
}