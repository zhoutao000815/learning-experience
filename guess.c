#include<stdio.h>
#include<Windows.h>
#include <time.h>
#pragma warning(disable:4996)
#define RANGE 100
void game()
{
	int a = 0;
	srand((unsigned long)time(NULL));
	int r = rand() % RANGE + 1;
	printf("��׼�����ˣ����������µ����֣���(1-100)\n");
	while (1)
	{
	scanf("%d",&a);
		if (a < r)
			printf("�Բ�������С��,���ٴ�����\n");
		else{
			if (a>r)
				printf("�Բ������´��ˣ����ٴ�����\n");
			else  
			{
				printf("���¶���!!!\n");
				break;
			}
		}

	}
}
   void menu()
{
	printf("####################\n");
	printf("###1:begin 0:exit###\n");
	printf("####################\n");
	printf("#######������#######\n");
}
	int main()
{
		int quit=0 ;
		menu();
    	scanf("%d",&quit);
		while (quit)
		{
		game();
		printf("����һ�֣�����\n");
		menu();
		scanf("%d",&quit);
		if (quit==0){
			printf("�ݰ�~~~\n");
			break;
		}
	}
	system("pause");
}