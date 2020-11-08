#include "game.h"
void game();
void menu();
int main()
{
	int quit = 0;
	int select = 0;
	while (quit == 0)
	{
		menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game();
			printf("再来?\n");
			break;
		case 2:
			quit = 1;
			printf("byebye!\n");
			break;
		default:
			printf("输入有误!请重新输入！\n");
			continue;
		}
	}
	system("pause");
}
