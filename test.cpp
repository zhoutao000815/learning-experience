#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
void Intprintf123(int a)//�ݹ�ʵ�ֵ�˳�����
{
	if(a> 10){
	Intprintf123(a / 10);
	}
	else
	{

	}
	printf("%d\t",a%10);
}
int Intprintf321(int a)//�ݹ�ʵ�ֵ��������
{
	printf("%d\t", a % 10);
	while (a<10)
	{
		return a;
	}
	(Intprintf321(a / 10));
}
int main()
{
	int Printf123 = 0, Printf321 = 0, flag = 0;
	printf("������Ҫ��ӡ��˳��\n");
	printf("1:˳��2������\n");
	scanf("%d", &flag);
	switch (flag)
	{
	case 1:
		printf("������Ҫ��ӡ�����֣�\n");
		scanf("%d", &Printf123);
		Intprintf123(Printf123);
		break;
	case 2:
		printf("������Ҫ��ӡ�����֣�\n");
		scanf("%d", &Printf321);
		Intprintf321(Printf321);
		break;
	default:
		break;
	}
	system("pause");
}