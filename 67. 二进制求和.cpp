//67. 二进制求和
//给你两个二进制字符串，返回它们的和（用二进制表示）。
//
//输入为 非空 字符串且只包含数字 1 和 0。
//
//
//
//示例 1:
//
//输入 : a = "11", b = "1"
//输出 : "100"
//	 示例 2 :
//
// 输入 : a = "1010", b = "1011"
//  输出 : "10101"
//
//
//	   提示：
//
//	   每个字符串仅由字符 '0' 或 '1' 组成。
//	   1 <= a.length, b.length <= 10 ^ 4
//	   字符串如果不是 "0" ，就都不含前导零。

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/add-binary/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
char * addBinary(char * a, char * b){
	//方法一：模拟加法运算
	int aleng = strlen(a);
	int bleng = strlen(b);
	int retleng = (aleng>bleng ? aleng : bleng) + 1 + 1; //第一次+1是要给字符串结尾赋值‘\0’,第二个+1为了给最高位进位留出空位。
	int up = 0;           //代表进位
	char *ret = (char *)malloc(retleng);
	*(ret + retleng - 1) = '\0';  //字符串末尾赋‘\0’
	retleng--;
	while (retleng > 0)
	{
		char acopy = '0', bcopy = '0';     //长短不一的情况下，用0值代替缺少的加数（默认是缺少的）
		if (aleng>0){ acopy = *(a + aleng - 1); }   //  不缺少的情况下，完成拷贝
		if (bleng>0){ bcopy = *(b + bleng - 1); }   //  不缺少的情况下，完成拷贝
		*(ret + retleng - 1) = '0' + acopy - 48 + bcopy - 48 + up;  //用固定‘0’作为基础值，
		up = 0;
		//加法会产生四种情况，0，1，2，3  .0和1没有进位不需处理 ，2，3虽进位相同，但此位数字不同，分别处理
		if (*(ret + retleng - 1) == '2')   //  
		{
			*(ret + retleng - 1) = '0';
			up = 1;
		}
		else if (*(ret + retleng - 1) == '3')
		{
			*(ret + retleng - 1) = '1';
			up = 1;
		}
		aleng--;
		bleng--;

		if (up == 1 && retleng == 2) //特殊情况；最高位完成加法后有进位，这时就用到了提前开好的空位空间，赋1退出即可。
		{
			retleng--;
			*(ret + retleng - 1) = '1';
			return ret;
		}

		retleng--;
	}
	return ret + 1;  //没有用到最高位进位的空位，所以+1刨除空位。
	//方法二：转为10进制，再加，再转为字符串二进制，用C语言写太麻烦了。
	//方法三：用位运算代替加减乘除，完成
}
int main()
{
	
	system("pause");
}