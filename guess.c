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
	printf("我准备好了！请输入您猜的数字！！(1-100)\n");
	while (1)
	{
	scanf("%d",&a);
		if (a < r)
			printf("对不起，您猜小了,请再次输入\n");
		else{
			if (a>r)
				printf("对不起，您猜大了，请再次输入\n");
			else  
			{
				printf("您猜对了!!!\n");
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
	printf("#######请输入#######\n");
}
	int main()
{
		int quit=0 ;
		menu();
    	scanf("%d",&quit);
		while (quit)
		{
		game();
		printf("再来一局？？？\n");
		menu();
		scanf("%d",&quit);
		if (quit==0){
			printf("拜拜~~~\n");
			break;
		}
	}
	system("pause");
}