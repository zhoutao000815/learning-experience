//917. 仅仅反转字母
//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//
//
//
//示例 1：
//
//输入："ab-cd"
//输出："dc-ba"
//示例 2：
//
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
//示例 3：
//
//输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-only-letters
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<Windows.h>

void swap(char*a, char*b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
char * reverseOnlyLetters(char * S){
	int leng = strlen(S);
	int i = 0, j = leng - 1;      //记录下标
	while (leng>1 && i<j)
	{
		if ((*(S + i) >= 'A' &&  *(S + i) <= 'Z') || (*(S + i) >= 'a' && *(S + i) <= 'z') && i<j) //是字母则什么都不做
		{
		}
		else                     //不是字母，前端下标++，长度--，再continue判断下一个字符
		{
			i++;
			leng--;
			continue;
		}
		if ((*(S + j) >= 'A' &&  *(S + j) <= 'Z') || (*(S + j) >= 'a' && *(S + j) <= 'z') && i<j)
		{
		}
		else
		{
			j--;
			leng--;
			continue;
		}
		if (i<j)       //上述判定结束后，要么是ij所指是字符，要么就是i==j了，判断一下，需要交换则换，==直接break。
		{
			swap(S + i, S + j);
			i++;
			j--;
			leng -= 2;
		}
		else{
			break;
		}
	}
	return S;
}
int main()
{
	int n = 2;
	n += n -= n*n;
	printf("%d\n", n);

	system("pause");
}