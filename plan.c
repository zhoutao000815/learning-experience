#include<stdio.h>
#include<Windows.h>
int main()//计算1--100中有多少个9
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
	printf("一共有%d个数字9",num);
	system("pause");
}