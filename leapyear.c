#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int leapyear(int x)
{
	{
		if ((x % 400 == 0)){
			return x;
		}
		else{
			if (x % 4 == 0 && x % 100 != 0){
			return x;
			}
			else
				return 0;
		}
	}
}
int main()
{
	int a = 0, b = 0, i = a;
	printf("请输入想要确定的年份！\n");
	printf("例如1000 2000\n");
	scanf("%d%d", &a, &b);
	for (i = a; i <=b; i+=4)
	{
		{ if (leapyear(a) )
			printf("%d是闰年\n", a);
		else
			printf("%d不是闰年\n", a);
		}
		a+=4;
	}
	system("pause");
}