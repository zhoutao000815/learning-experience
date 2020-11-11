#include<stdio.h>
#include<Windows.h>
//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
int main()//从第一项开始，每两项组合，变成(1/（1*2))+（1/（3*4））+...+（1/（99*100））
{
	float i = 1, k = 2;
	double result = 0;//i代表奇数，k代表偶数
	for (i = 1, k = 2; k<101;i+=2,k+=2)
	{
		result = result+(1.0 / (i*k));
	}
	printf("最终值为%f\n", result);
	system("pause");
}



//方法2
//#include <stdio.h>
//#include<Windows.h>
//
//int  main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	system("pause");
//	return 0;
//}