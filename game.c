#include "game.h"
void menu()
{
	printf("*****************************\n");
	printf("****  1:play      2:exit ****\n");
	printf("*****************************\n");
}
void board(char arr[][COL])//数组传参发生降维，二维数组可以省略第一个[]的数字。
{
	int i = 0, j = 0;
	printf("   | 1 | 2 | 3 | \n");
	for (i = 1; i <= COL; i++)//玩家使用棋盘时候，确定位置从1开始 ，COL结束。
	{
		printf("---------------\n");
		printf(" %d |", i);
		for (j = 1; j <= COL; j++)
		{
			printf(" %c |",arr[i-1][j-1]);//由于数组名下标（0-2）和玩家（1-3）使用的差别，i和j分别减一。
		}
		printf("\n");
	}
	printf("\n");
}
void player(char arr[][COL])
{
	int a = 0, b = 0;
	while (1)
	{
		printf("请输入你要下的位置！\n");
		scanf("%d %d", &a, &b);
		if (a<1 || a>3 || b<1 || b>3)
		{
			printf("输入有误，请重新输入！");
			continue;
		}
		else
		{
			if (arr[a - 1][b - 1] != ' ')
			{
				printf("该位置已有棋子，请重新选择位置！\n");
				continue;
			}
			else
			{
				arr[a - 1][b - 1] = PLAYER;
				break;
			}
		}
	}
}
void computer(char arr[][COL])
{
	while (1)
	{
		int r = rand() % ROW;
		int q = rand() % COL;
		if (arr[r][q] == ' ')
		{
			arr[r][q] = COMP;
			break;
		}
	}
}
char victory(char arr[][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)//判断行是否三连
	{
		if (arr[i][0] == arr[i][1] &&\
		    arr[i][0] == arr[i][2] &&\
		    arr[i][0] != ' ')//另外判断三个是否同样时，不可以写成 arr[i][0] == arr[i][1] == arr[i][2]==arr[i][0] != ' '。
		                   	// 因为'=='是个逻辑运算符，运算后结果为1或0，第一个“==”完成后变成了“1或者0”==arr[i][2]，明显失真。
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < 3; i++)//判断列是否三连
	{
		if (arr[0][i] == arr[1][i]&&\
			arr[0][i] == arr[2][i]&&\
			arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}
		if (arr[0][0] == arr[1][1]&&\
		    arr[1][1] == arr[2][2]&&\
			arr[1][1] != ' ')//↘方向的三连判断
	{
		return arr[1][1];
	}
	if ((arr[0][2] == arr[1][1] &&\
		 arr[1][1] == arr[2][0])&&\
		 arr[1][1] != ' ')//↙方向的三连判断，上面的“\”起到承接下一行代码的作用提高可读性。
	{
		return arr[1][1];
	}
	for (i = 0; i < 3; i++)//用来判断尚未分出胜负时，棋盘是否下满，没满则下一步NEXT，已满则平局。
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			{
				return NEXT;
			}
		}
	}
		return DRAW;//函数有返回值时，考虑到每一种情况，对应的分支语句要加return。否则会出现warning C4715: “victory”: 不是所有的控件路径都返回值。
}
void game ()
{	
	char arr[ROW][COL];
	//InitBoard(board, ROW, COL)
	memset(arr,' ', sizeof(arr));
	srand((unsigned long)time(NULL));
	board(arr);
	while (1)
	{
		player(arr);
		board(arr);
		char result = victory(arr);//用一个外部变量取代函数的返回值，提高可读性，确保数据类型相同。
		if (result != NEXT)//每一次下完棋子后，都要判断是否有人胜利或平局。不是NEXT代表有结果，结束比赛。
		{
			break;
		}
		computer(arr);
		board(arr);
		result = victory(arr);
		if (result != NEXT)//每一次下完棋子后，都要判断是否有人胜利或平局。不是NEXT代表有结果，结束比赛。
		{
			break;
		}
	}
	char result = victory(arr);
	if (result == PLAYER)
	{
		printf("你赢了！\n");
	}
	else
	{
		if (result == COMP)
		{
			printf("你输了！\n");
		}
		else
		{
			printf("平局！\n");
		}
	}
}