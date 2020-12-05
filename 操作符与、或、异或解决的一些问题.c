#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
int function(int a, int b);//函数的声明。
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子:
//1999 2299
//输出例子 : 7

void function2();
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列。

int function3();
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1

void function4();
//不允许创建临时变量，交换两个整数的内容
int main()
{
	int a = 0, b = 0;
	printf("请输入两个int型数字！\n");
	scanf("%d %d", &a, &b);
	printf("交换前：a=%d,b=%d\n", a,b);
	function4(a,b);


	//printf("请输入一个整数！\n");
	//int n = 0;
	//scanf("%d", &n);
	//function3(n);
	//printf("%d个1\n", function3(n));



	//printf("请输入一个整数！\n");
	//int m = 0;
	//scanf("%d", &m);
	//function2(m);


	//printf("请输入两个int型数字！\n");
	//int m = 0, n = 0;
	//scanf("%d %d", &m, &n);
	//function(m, n);//函数必须先声明后使用，通常情况下，声明和定义写在一起，都写在main函数前。
	//printf("%d\n", function(m, n));



	system("pause");
}
 static int function(int a,int b)//函数的定义。
{
	int count = 0;
	int c = a^b;
	while (c)//求一个数字c的比特位有多少个“1”。
	{
		c = c&(c - 1);
		count++;
	}
	return count;
}

 void function2(int m)
 {
	 int i = 0;
	 printf("奇数：\n");
	 for (i = 31; i >= 1; i -= 2)//2的“1”次方是第一个奇数位“十位”
	 {
		 printf("%d", (m >> i) & 1);
	 }
	 printf("\n偶数：\n");
	 for (i = 30; i >= 0; i -= 2)//2的“0”次方是第一个偶数位“个位”
	 {
		 printf("%d", (m >> i) & 1);
	 }
 }

 int function3(int n)
 {
	 int count = 0;
	 while (n)
	 {
		 n = n&(n - 1);
		 count++;
	 }
	 return count;
 }

 void function4(int a, int b)
 {
	/* a = a + b;
	 b = a - b;   //b = （a + b） - b
	 a = a - b;   //a = （a + b） - a
	 printf("交换后：a=%d,b=%d\n", a, b);*///方法一

	 a = a ^ b;
	 b = a ^ b;   //b=(a ^ b) ^ b         
	 a = a ^ b;   //a=(a ^ b) ^ a
	 printf("交换后：a=%d,b=%d\n", a, b);//方法二

 }