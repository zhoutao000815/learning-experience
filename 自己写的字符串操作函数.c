#include <stdio.h>
#include <windows.h>
#include<assert.h>
#pragma warning (disable:4996)
//方法一：创建临时变量计数
int My_strlen(char *arr)
{
	char *p = arr;
	assert(arr!= NULL);
	assert(p != NULL);
	int size = 0;
	while (*p)
	{
		*p++;
		size++;
	}
	return size;
}
//方法二：用指针相减得到中间元素的个数
int My_strlen2(char *arr)
{
	char* q = arr;
	assert(arr != NULL);
	assert(q != NULL);
	while (*q != 0)
	{
		q++;
	}
	return q - arr;
}
//方法三：递归方法
int My_strlen3(char *arr)
{
	assert(arr != NULL);
	if (*arr == '/0')
	{
		return 0;
	}
	else
	{
		return 1 + My_strlen3(arr + 1);
	}

}
char* My_strcpy(char *dst,const char* str)
{
	char* cp = dst;
	assert(dst != NULL);
	assert(str != NULL);
	while (*cp++ = *str++)
	{
	}
	return (dst);
}
char* My_strcat(char *dst, const char* str)
{
	char*cp = dst;
	assert(dst != NULL);
	assert(str != NULL);
	while (*cp != '\0')
	{
		cp++;
	}
	while (*str != '\0')
	{
		 *cp++ = *str++ ;
	}
	*cp = '\0';
	return dst;
}
int My_strcmp(const char* str1, const char* str2)
{
	int ret = 0;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
	{
		str1++;
		str2++;
	}
	if (ret > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return ret;
}
char* My_strstr(const char *src,const char* dst)
{
	assert(dst != NULL);
	assert(src != NULL);
	char *p = (char*)dst;
	char *ret = (char*)src;
	while (*src)
	{
		if (*dst != *src)
		{
			src++;
			ret++;
		}
		else
		{
			while (*dst)
			{
				dst++;
				src++;
				if (*dst == '\0')
				{
					return ret;
				}
			}
			dst = p;
			src = ret + 1;
		}
	}
	return 0;
}
void* My_memcpy(void* dst, const void* src, size_t size)
{
	assert(dst != NULL);
	assert(src != NULL);
	void* ret = dst;
	while (size--)
	{
		(char*)dst = (char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void* My_memmove(void* dst, const void* src, size_t size)
{
	assert(dst != NULL);
	assert(src != NULL);
	void* ret = dst;
	if (dst <= src || ((char*)src+size <= (char*)dst))
	{
		while (size--)
		{
			(char*)dst = (char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dst = (char*)dst + size-1;
		src = (char*)src + size-1;
		while (size--)
		{
			(char*)dst = (char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}
int main()
{
	//const char* str1 = "a";
	//const char* str2 = "1cde";
	/*const char *str = "hello world!";*/
	//char dst[100] = "hello ";
	//printf("%s\n",My_strcat(dst, str));
	//printf("%d\n", My_strcmp(str1, str2));
	//const char* flag = "o";
	//printf("%s\n", My_strstr(str,flag));
	//printf("%s\n", My_strstr(str,flag));
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
	system("pause");
}
//{
//	printf("请输入要计算长度的字符串！\n");
//	//---------------------------------------------------------------------------
//	//指针字符串的数据类型大小，以及可否被修改验证。
//	char* arr = "hello.c" ;//*arr是字符指针
//	printf("%d\n", sizeof(arr));//sizeof（arr）==sizeof（type of arr）这里字符串名字arr的数据类型为char*，即字符型指针。32位操作系统下，指针都是4字节。64位：8字节。
//	printf("%d\n", sizeof(*arr));//sizeof（*arr）==sizeof（type of *arr）这里*arr是指针的解引用，“arr”字符串名代表首元素的地址，所以sizeof（*arr）==sizeof（h），
//	                           //“h”是一个字符，但它的数据类型是前面开辟空间时所决定的，这里是char型，所以结果为1。
//
//	/**arr = *(arr+1);*/ //可以看到指针字符串是不能被修改的，因为指针字符串中的字符是在系统内存中的字符常量区，只可读取，不可被修改。
//                         //我们使用指针字符串的时候，只是使用了字符存在系统内存中的地址，通过地址来访问和排序的。
//	printf("%c\n", *arr + 1);//由于“*”优先级高于“+”。所以先解引用再加1。解引用后是“h”，“h+1”是什么呢?是系统字符常量区中“h”的下一个字符！
//	printf("%c\n", *(arr + 1));//这里解引用的是“arr+1”。arr代表首元素地址，+1是第二个元素的地址！再解引用就是第二个元素‘e’。
//	                         //所以我们在使用指针的时候要多注意优先级的问题，为了确保无误可以加（）。
//
//	//---------------------------------------------------------------------------
//	//数组字符串的数据类型大小，以及可否被修改验证。
//    char arr2[] = { "hello world!" };
//	printf("%d\n", sizeof(arr2));//sizeof（数组名）和 &数组名 中的数组名代表整个数组，其他情况都是指首元素地址。所以“arr2”的大小，是char类型所占字节大小×数组元素个数。字符串最后系统给一个\0
//	printf("%d\n", sizeof(*arr2));//第一个元素的数据类型所占字节数。
//	
//	arr2[0] = arr2[11];//用数组下标修改数组字符串中的字符。
//	char* p = arr2;//这是一个指向数组内部首元素的指针，因为数组名在这里代表首元素地址。
//	*(p + 2) = arr2[11];//用指针修改数组字符串中的字符。
//	printf("%s\n", arr2);//为什么数组字符串可以修改呢？因为数组是在栈帧上开辟空间，并且对字符常量区进行拷贝放入数组开辟的内存中。所以可以被修改。
//	//---------------------------------------------------------------------------
//	//My_strlen函数的main代码。
//	/*scanf("%c", &arr);
//	My_strlen(arr);
//	int result = My_strlen(arr);
//	printf("%d", result);*/
//	system("pause");
//}