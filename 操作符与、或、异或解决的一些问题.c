#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
int function(int a, int b);//������������
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//��������:
//1999 2299
//������� : 7

void function2();
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ�����������С�

int function3();
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1

void function4();
//����������ʱ������������������������
int main()
{
	int a = 0, b = 0;
	printf("����������int�����֣�\n");
	scanf("%d %d", &a, &b);
	printf("����ǰ��a=%d,b=%d\n", a,b);
	function4(a,b);


	//printf("������һ��������\n");
	//int n = 0;
	//scanf("%d", &n);
	//function3(n);
	//printf("%d��1\n", function3(n));



	//printf("������һ��������\n");
	//int m = 0;
	//scanf("%d", &m);
	//function2(m);


	//printf("����������int�����֣�\n");
	//int m = 0, n = 0;
	//scanf("%d %d", &m, &n);
	//function(m, n);//����������������ʹ�ã�ͨ������£������Ͷ���д��һ�𣬶�д��main����ǰ��
	//printf("%d\n", function(m, n));



	system("pause");
}
 static int function(int a,int b)//�����Ķ��塣
{
	int count = 0;
	int c = a^b;
	while (c)//��һ������c�ı���λ�ж��ٸ���1����
	{
		c = c&(c - 1);
		count++;
	}
	return count;
}

 void function2(int m)
 {
	 int i = 0;
	 printf("������\n");
	 for (i = 31; i >= 1; i -= 2)//2�ġ�1���η��ǵ�һ������λ��ʮλ��
	 {
		 printf("%d", (m >> i) & 1);
	 }
	 printf("\nż����\n");
	 for (i = 30; i >= 0; i -= 2)//2�ġ�0���η��ǵ�һ��ż��λ����λ��
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
	 b = a - b;   //b = ��a + b�� - b
	 a = a - b;   //a = ��a + b�� - a
	 printf("������a=%d,b=%d\n", a, b);*///����һ

	 a = a ^ b;
	 b = a ^ b;   //b=(a ^ b) ^ b         
	 a = a ^ b;   //a=(a ^ b) ^ a
	 printf("������a=%d,b=%d\n", a, b);//������

 }