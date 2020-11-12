#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning (disable:4996)
void function(int arr[],int size)//不使用数组下标，写一个函数打印arr数组的内容，使用指针。arr是一个整形一维数组。
{
	int i = 0, *p = arr;
	for (i = 0; i < size; i++)
	{
		printf("arr[%d]=%x\n",i, p + i);
		printf("arr[%d]=%d\n", i, *p + i);
		printf("*p+%d=%x\n",i, arr + i);
		printf("*p+%d=%d\n", i, *arr + i);
	}
}

void function2(char arr[], int i)//写一个函数，可以逆序输出一个字符串的内容。
{
	char *p = arr;
	for (i; i >=0; i--)
	{
		printf("%c", *(p+i));
	}
}

void function3(int a)//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
{
	int i = 0, b = 0, Sn = 0;
	for (i = 0; i <= 4; i++)
	{
		b += a*(int)(pow(10,i));
		Sn += b;
	}
	printf("%d", Sn);
}

void function4(int a)//判断一个数字是不是自幂数。
{
	int i = 1, j = 0,result=0;
	int b = a;
	int c = a;
	while (a / 10 != 0)
	{
		i++;
		a = a / 10;
	}
	for (j = 0; j < i; j++)
	{	
		result += (int)pow(b % 10, i);
	 	b = b / 10;
	}
	if (c == result)
	{
		printf (" %d ",c);
	}
	else
	{

	}
}

void function5()//菱形打印
{
	int i = 0, j = 0;
	for (i = 6; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < (13-2*i); j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < 7; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (j = (13 - 2 * i); j >0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}
void function6(int a)//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少瓶汽水？
{
	int b = 0, c = a;
	while (a>1)
	{
		b += a / 2;
		a += a % 2;
		//if (a % 2 == 1)
		//{
		//	a++;
		//}
		a /= 2;
	}
	printf("能喝%d瓶汽水！\n", (b + c));
}
int main()
{
	//int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	//int size = sizeof(arr) / sizeof arr[0];
	//function(arr,size);


	//char arr []= {"hello world!hello 2020!"};
	//int i = strlen(arr);
	//function2(arr,i);


	//int a = 2;
	//function3(a);
	

	//int i = 0;
	//for (i = 0; i <= 100000; i++)
	//{
	//	function4(i);
	//}	


	/*function5();*/

	printf("请输入你有多少钱？\n");
	int a = 0;
	scanf("%d", &a);
	function6(a);

	system("pause");
}