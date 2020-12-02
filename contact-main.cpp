#include"Contact.h"

int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{	
		menu();
		scanf(" %d", &select);
		switch (select)
		{
		case 1:
			Add();
			break;
		case 2:
			Del();
			break;
		case 3:
			Search();
			break;
		case 4:
			Revise();
			break;
		case 5:
			Show();
			break;
		case 6:
			Clear();
			break;
		case 7:
			Qsort();
			break;
		case 0:
			printf("bye bye!\n");
			quit = 1;
			break;
		default:
			printf("error input£¡again  please£¡\n");
			break;
		}
	}
	system("pause");
}
