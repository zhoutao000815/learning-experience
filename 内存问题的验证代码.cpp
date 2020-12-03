#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

char *GetMemory2(void)
{
	char *p = "hello world";
	return p;
}

char *GetMemory3(void)
{
	char *q = "hello world!";
	char *p = NULL;
	p=(char*)malloc(20);
	if ( NULL != *p )
	{
		for (int i = 0; i < 20; i++)
		{
			*(p + i) = *(q + i);
		}
	}
	free(p);
	return p;
}
char *GetMemory4(void)
{

	char *p = NULL;
	p = (char*)malloc(20);
	if (NULL != *p)
	{
		p = "hello world";
	}
	free(p);
	return p;
}

char *GetMemory1(void)
{
	char p[] = "hello world";
	return p;
}

int main()
{
	char *str = NULL;
	str = GetMemory1();

	printf(str);
	system("pause");
}