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
			printf("����?\n");
			break;
		case 2:
			quit = 1;
			printf("byebye!\n");
			break;
		default:
			printf("��������!���������룡\n");
			continue;
		}
	}
	system("pause");
}
