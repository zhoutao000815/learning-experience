//字符串排序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
void swap(char* a1, char*a2)
{
	char temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void Bubblesort(char*arr, int arrSize)
{
	int i = 0;
	int j = 0;
	for (i = arrSize; i>1; i--)
	{
		for (j = 0; j<i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
int main()
{
	char p[21];
	scanf("%s",&p);
	int pSize = strlen(p);
	char arr[21];
	memset(arr, '0', 21);
	memcpy(arr, p, pSize);
	Bubblesort(arr, pSize);
	int k;
	for (k = 0; k<pSize; k++)
	{
		printf("%c", arr[k]);
	}
	system("pause");
	return 0;
}