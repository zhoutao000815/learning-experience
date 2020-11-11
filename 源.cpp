#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
void MuPca(int a, int b)//³Ë·¨¿Ú¾÷±í
{
	int i, j;
	for (i = 1; i <= a; i++){
		for (j = 1; j <= i; j++){
			printf("%dX%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int a = 0, b = 0;
	printf("please input your Muliplpication Table!!!\n");
	scanf("%d%d", &a, &b);
	MuPca(a, b);
	system("pause");
}