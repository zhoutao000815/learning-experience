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
	printf("��������Ҫȷ������ݣ�\n");
	printf("����1000 2000\n");
	scanf("%d%d", &a, &b);
	for (i = a; i <=b; i+=4)
	{
		{ if (leapyear(a) )
			printf("%d������\n", a);
		else
			printf("%d��������\n", a);
		}
		a+=4;
	}
	system("pause");
}