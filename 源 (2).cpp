#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
int Faction1 (int np)//非递归实现的求n的阶乘。
{
	int i = 0;
	for (i = np; i > 1; i--){
		np = np*(i - 1);
	}
	return np;
}
int Faction2(int nq)//递归实现的求阶乘。
{
	if (nq ==1)
	{
		return 1;
	}
	return nq*Faction2(nq - 1);
}
int main()
{
	int n = 0;
	printf("请输入n的阶乘！\n");
	scanf("%d",&n);
	int result= Faction2(n);
	printf("%d的阶乘=%d\n", n, result);
	system("pause");
}