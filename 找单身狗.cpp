#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int main()
{
	int nums[8] = { 4, 1, 4, 6};
	int numsSize = 8;
	int a = 0;
	for (int i = 0; i < numsSize; i++)//�������������ͬ�������Ϊ0�������Ϊ��ͬ�������ֵ������a��
	{

		a = a^nums[i];
	}
	int b = 0;
	int c = 0;
	//�ҵ�a�����λΪ1����һ�������ֿ��������֡�
	int flag = 1;
	while ((a & flag) == 0)//ע�ⰴλ�롰&�����жϲ�������==�������ȼ�
	{
		flag = flag << 1;//����ȷ�����λ
	}
	printf("%d\n", flag);
	for (int i = 0; i < numsSize; i++)//��flag����&���ֳ����飬b��c��
	{
		if ((nums[i]& flag) ==0)//ע�ⰴλ�롰&�����жϲ�������==�������ȼ�
		{
			b = b^nums[i];

		}
		else
		{
			c = c^nums[i];

		}
	}
	printf("%d  %d", b, c);
	system("pause");
}