#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
int Faction1 (int np)//�ǵݹ�ʵ�ֵ���n�Ľ׳ˡ�
{
	int i = 0;
	for (i = np; i > 1; i--){
		np = np*(i - 1);
	}
	return np;
}
int Faction2(int nq)//�ݹ�ʵ�ֵ���׳ˡ�
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
	printf("������n�Ľ׳ˣ�\n");
	scanf("%d",&n);
	int result= Faction2(n);
	printf("%d�Ľ׳�=%d\n", n, result);
	system("pause");
}