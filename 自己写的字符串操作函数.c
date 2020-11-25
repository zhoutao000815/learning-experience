#include <stdio.h>
#include <windows.h>
#include<assert.h>
#pragma warning (disable:4996)
//����һ��������ʱ��������
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
//����������ָ������õ��м�Ԫ�صĸ���
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
//���������ݹ鷽��
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
//	printf("������Ҫ���㳤�ȵ��ַ�����\n");
//	//---------------------------------------------------------------------------
//	//ָ���ַ������������ʹ�С���Լ��ɷ��޸���֤��
//	char* arr = "hello.c" ;//*arr���ַ�ָ��
//	printf("%d\n", sizeof(arr));//sizeof��arr��==sizeof��type of arr�������ַ�������arr����������Ϊchar*�����ַ���ָ�롣32λ����ϵͳ�£�ָ�붼��4�ֽڡ�64λ��8�ֽڡ�
//	printf("%d\n", sizeof(*arr));//sizeof��*arr��==sizeof��type of *arr������*arr��ָ��Ľ����ã���arr���ַ�����������Ԫ�صĵ�ַ������sizeof��*arr��==sizeof��h����
//	                           //��h����һ���ַ�������������������ǰ�濪�ٿռ�ʱ�������ģ�������char�ͣ����Խ��Ϊ1��
//
//	/**arr = *(arr+1);*/ //���Կ���ָ���ַ����ǲ��ܱ��޸ĵģ���Ϊָ���ַ����е��ַ�����ϵͳ�ڴ��е��ַ���������ֻ�ɶ�ȡ�����ɱ��޸ġ�
//                         //����ʹ��ָ���ַ�����ʱ��ֻ��ʹ�����ַ�����ϵͳ�ڴ��еĵ�ַ��ͨ����ַ�����ʺ�����ġ�
//	printf("%c\n", *arr + 1);//���ڡ�*�����ȼ����ڡ�+���������Ƚ������ټ�1�������ú��ǡ�h������h+1����ʲô��?��ϵͳ�ַ��������С�h������һ���ַ���
//	printf("%c\n", *(arr + 1));//��������õ��ǡ�arr+1����arr������Ԫ�ص�ַ��+1�ǵڶ���Ԫ�صĵ�ַ���ٽ����þ��ǵڶ���Ԫ�ء�e����
//	                         //����������ʹ��ָ���ʱ��Ҫ��ע�����ȼ������⣬Ϊ��ȷ��������Լӣ�����
//
//	//---------------------------------------------------------------------------
//	//�����ַ������������ʹ�С���Լ��ɷ��޸���֤��
//    char arr2[] = { "hello world!" };
//	printf("%d\n", sizeof(arr2));//sizeof������������ &������ �е������������������飬�����������ָ��Ԫ�ص�ַ�����ԡ�arr2���Ĵ�С����char������ռ�ֽڴ�С������Ԫ�ظ������ַ������ϵͳ��һ��\0
//	printf("%d\n", sizeof(*arr2));//��һ��Ԫ�ص�����������ռ�ֽ�����
//	
//	arr2[0] = arr2[11];//�������±��޸������ַ����е��ַ���
//	char* p = arr2;//����һ��ָ�������ڲ���Ԫ�ص�ָ�룬��Ϊ�����������������Ԫ�ص�ַ��
//	*(p + 2) = arr2[11];//��ָ���޸������ַ����е��ַ���
//	printf("%s\n", arr2);//Ϊʲô�����ַ��������޸��أ���Ϊ��������ջ֡�Ͽ��ٿռ䣬���Ҷ��ַ����������п����������鿪�ٵ��ڴ��С����Կ��Ա��޸ġ�
//	//---------------------------------------------------------------------------
//	//My_strlen������main���롣
//	/*scanf("%c", &arr);
//	My_strlen(arr);
//	int result = My_strlen(arr);
//	printf("%d", result);*/
//	system("pause");
//}