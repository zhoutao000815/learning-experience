#include<stdio.h>
#include<Windows.h>
int main()//����1--100���ж��ٸ�9
{
	int i = 0, j = 0, num = 0;
	for (i = 0; i <=10; i++){
		for (j = 0; j < 10; j++){
			if ((i == 10) && (j == 1))
				break;
			if (i==9||j==9)
			num += 1;
		}
	}
	printf("һ����%d������9",num);
	system("pause");
}