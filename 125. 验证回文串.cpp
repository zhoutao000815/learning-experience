//125. 验证回文串
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入 : "A man, a plan, a canal: Panama"
//输出 : true
//	 示例 2 :
//
// 输入 : "race a car"
//  输出 : false

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/valid-palindrome/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<stdio.h>
#include<Windows.h>
//在原字符串上进行判断，空间复杂度O（1），时间复杂度O（N）。
bool isPalindrome(char * s){
	int leng = strlen(s);
	int i = 0;       //前后指针法，i为前指针下标
	int end = leng - 1;        //end为后指针下标
	while (i<end)
	{
		int ischar1 = 0;
		int ischar2 = 0;
		while (!ischar1 && i<end)      //确保前指针指向为字母或数字，
		{
			if ((*(s + i) >= '0' &&  *(s + i) <= '9') || (*(s + i) >= 'A' &&  *(s + i) <= 'Z') || (*(s + i) >= 'a' && *(s + i) <= 'z'))
			{
				ischar1 = 1;
				break;
			}
			i++;
		}
		while (!ischar2 && i<end)         //确保后指针指向为字母或数字，
		{
			if ((*(s + end) >= '0' &&  *(s + end) <= '9') || (*(s + end) >= 'A' &&  *(s + end) <= 'Z') || (*(s + end) >= 'a' && *(s + end) <= 'z'))
			{
				ischar2 = 1;
				break;
			}
			end--;
		}

		if ((*(s + end) >= '0' &&  *(s + end) <= '9') || (*(s + i) >= '0' &&  *(s + i) <= '9'))  //数字没有大小写之分，直接判断
		{
			if (*(s + i) == *(s + end))
			{
				i++;
				end--;
				continue;
			}
			else
			{
				return false;
			}
		}
		if (*(s + i) == *(s + end) || (*(s + i) + ' ' == *(s + end)) || (*(s + i) == *(s + end) + ' '))    //字母情况要加上大小写的情况，同一字符大小写ascii相差32，ascii为32的字符是' '（空格）
		{
			i++;
			end--;
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}