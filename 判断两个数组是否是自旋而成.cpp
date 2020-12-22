#include<stdio.h>
#include<Windows.h>
#include <assert.h>
#pragma warning (disable:4996)
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
struct ListNode {
	int val;
	struct ListNode *next;
}; 
typedef struct ListNode ListNode;
//解题思路
//本题当然可以将所有旋转后的结果放到一个数组里，然后进行查找，但是这种做法既不好操作，也太费事，但是这题有一个很简单的做法：
//其实ABCDE无论怎么旋，旋转后的所有结果，都包含在了ABCDEABCD这个字符串里了。
//所以做法很简单，只需要将原字符串再来一遍接在后面，然后找一找待查找的字符串是不是两倍原字符串的子集即可。
char *My_strstr(const char * dst, const char *src)
{
	assert(dst != NULL);
	assert(src != NULL);
	char *p = (char *)src;
	char *rel = (char *)dst;
	while (*dst)
	{		
		if (*dst != *src)
		{
			rel++;
			dst++;
		}
		else
		{
			while (*dst && *src && *dst == *src)
			{
				dst++;
				src++;
				if (*src == NULL)
				{
					return rel;
				}
			}
			src = p;
			rel++;
			dst = rel;
		}
	}
	return NULL;
}
bool findRound(const char src[],char dst[])
{
	char temp[256];
	strcpy(temp, src);
	strcat(temp, src);
	int tempsize=strlen(temp);
	char *p = My_strstr(temp, dst);
	if (p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{

	char s1 [] = "abcd";
	char s2 []= "ACBD";

	char s3 []= "AABCD";
	char s4 []= "BCDAA";
	printf("%d\n", findRound(s3,s4));
	system("pause");
}