#include<stdio.h>
#include<Windows.h>
//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
int main()//�ӵ�һ�ʼ��ÿ������ϣ����(1/��1*2))+��1/��3*4����+...+��1/��99*100����
{
	float i = 1, k = 2;
	double result = 0;//i����������k����ż��
	for (i = 1, k = 2; k<101;i+=2,k+=2)
	{
		result = result+(1.0 / (i*k));
	}
	printf("����ֵΪ%f\n", result);
	system("pause");
}



//����2
//#include <stdio.h>
//#include<Windows.h>
//
//int  main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	system("pause");
//	return 0;
//}