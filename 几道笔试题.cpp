#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
char *GetMemory1(void)
{
	char p[] = "hello world";
	return p;
}
char *GetMemory2(void)
{
	char *p = "hello world";
	return p;
}
char *GetMemory5(void)
{
	static char p[] = "hello world";
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
const char *GetMemory4(void)
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
const char* GetMemory6()
{
	const char str2 []= "hello world";
	return str2;
}

int main()
{
	const char *str =GetMemory6();
	printf("%s\n", str);
	system("pause");
}