//925. 长按键入
//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
//
//
//
//示例 1：
//
//输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。
//示例 2：
//
//输入：name = "saeed", typed = "ssaaedd"
//输出：false
//解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
//示例 3：
//
//输入：name = "leelee", typed = "lleeelee"
//输出：true
//示例 4：
//
//输入：name = "laiden", typed = "laiden"
//输出：true
//解释：长按名字中的字符并不是必要的。
//
//name.length <= 1000
//typed.length <= 1000
//name 和 typed 的字符都是小写字母。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/long-pressed-name
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<Windows.h>

bool isLongPressedName(char * name, char * typed){
	//方法一:
	//自己写的笨比解法：记录每个相同字符的个数，如果同一个字符，
	//name的个数大于typed的就为假，
	// int i=1,j=1;  // 记录个数。
	// while(*name!='\0')
	// {
	//     if(*name != *typed)
	//     {
	//         return false;
	//     }
	//     while(*name==*(name+1) && *(name+1)!='\0')
	//     {
	//         name++;
	//         i++;
	//     }
	//     while(*(typed) == *(typed+1) && *typed != '\0')
	//     {
	//         typed++;
	//         j++;
	//     }
	//     if(i>j)
	//     {
	//         return false;
	//     }
	//     typed++;  //下一个字符
	//     name++;   //下一个字符
	//     i=1;      //记录数字归1 
	//     j=1;      //
	// }
	// if(*typed != '\0')  //此时name结束，typed如果还没有结束，那就是false。
	// return false;
	// else
	// return true;

	//方法二：官方解法
	//双指针依次检测，两字符串必须同时结束为真。
	int n = strlen(name), m = strlen(typed);
	int i = 0, j = 0;  //记录走到两字符串的那个位置。
	while (j < m) {  //typed结束。
		if (i < n && name[i] == typed[j]) {  //如果相同起始位置，字符也相同则各自+1；
			i++;
			j++;
		}
		else if (j > 0 && typed[j] == typed[j - 1]) {  //如果此处长按了，tyepd走向下一个，
			j++;
		}
		else {  //如果两者都不是，说明false。
			return false;
		}
	}
	return i == n;  //i是记录name的位置的，相同说明name也结束，不相同说明teped提前结束了。
}