#include "game.h"
void menu()
{
	printf("*****************************\n");
	printf("****  1:play      2:exit ****\n");
	printf("*****************************\n");
}
void board(char arr[][COL])//���鴫�η�����ά����ά�������ʡ�Ե�һ��[]�����֡�
{
	int i = 0, j = 0;
	printf("   | 1 | 2 | 3 | \n");
	for (i = 1; i <= COL; i++)//���ʹ������ʱ��ȷ��λ�ô�1��ʼ ��COL������
	{
		printf("---------------\n");
		printf(" %d |", i);
		for (j = 1; j <= COL; j++)
		{
			printf(" %c |",arr[i-1][j-1]);//�����������±꣨0-2������ң�1-3��ʹ�õĲ��i��j�ֱ��һ��
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
		printf("��������Ҫ�µ�λ�ã�\n");
		scanf("%d %d", &a, &b);
		if (a<1 || a>3 || b<1 || b>3)
		{
			printf("�����������������룡");
			continue;
		}
		else
		{
			if (arr[a - 1][b - 1] != ' ')
			{
				printf("��λ���������ӣ�������ѡ��λ�ã�\n");
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
	for (i = 0; i < 3; i++)//�ж����Ƿ�����
	{
		if (arr[i][0] == arr[i][1] &&\
		    arr[i][0] == arr[i][2] &&\
		    arr[i][0] != ' ')//�����ж������Ƿ�ͬ��ʱ��������д�� arr[i][0] == arr[i][1] == arr[i][2]==arr[i][0] != ' '��
		                   	// ��Ϊ'=='�Ǹ��߼���������������Ϊ1��0����һ����==����ɺ����ˡ�1����0��==arr[i][2]������ʧ�档
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < 3; i++)//�ж����Ƿ�����
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
			arr[1][1] != ' ')//�K����������ж�
	{
		return arr[1][1];
	}
	if ((arr[0][2] == arr[1][1] &&\
		 arr[1][1] == arr[2][0])&&\
		 arr[1][1] != ' ')//�L����������жϣ�����ġ�\���𵽳н���һ�д����������߿ɶ��ԡ�
	{
		return arr[1][1];
	}
	for (i = 0; i < 3; i++)//�����ж���δ�ֳ�ʤ��ʱ�������Ƿ�������û������һ��NEXT��������ƽ�֡�
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			{
				return NEXT;
			}
		}
	}
		return DRAW;//�����з���ֵʱ�����ǵ�ÿһ���������Ӧ�ķ�֧���Ҫ��return����������warning C4715: ��victory��: �������еĿؼ�·��������ֵ��
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
		char result = victory(arr);//��һ���ⲿ����ȡ�������ķ���ֵ����߿ɶ��ԣ�ȷ������������ͬ��
		if (result != NEXT)//ÿһ���������Ӻ󣬶�Ҫ�ж��Ƿ�����ʤ����ƽ�֡�����NEXT�����н��������������
		{
			break;
		}
		computer(arr);
		board(arr);
		result = victory(arr);
		if (result != NEXT)//ÿһ���������Ӻ󣬶�Ҫ�ж��Ƿ�����ʤ����ƽ�֡�����NEXT�����н��������������
		{
			break;
		}
	}
	char result = victory(arr);
	if (result == PLAYER)
	{
		printf("��Ӯ�ˣ�\n");
	}
	else
	{
		if (result == COMP)
		{
			printf("�����ˣ�\n");
		}
		else
		{
			printf("ƽ�֣�\n");
		}
	}
}