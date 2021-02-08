//709. 转换成小写字母
//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
//
//
//
//示例 1：
//
//输入 : "Hello"
// 输出 : "hello"
//
//示例 2：
//
//输入 : "here"
// 输出 : "here"
//
//示例 3：
//
//输入 : "LOVELY"
//输出 : "lovely"
//
//
	//  来源：力扣（LeetCode）
 // 链接：https ://leetcode-cn.com/problems/to-lower-case
	//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<stdio.h>
#include<Windows.h>
char * toLowerCase(char * str){
	char *ret = str;
	while ((*str) != '\0')
	{
		if ((*str)>64 && (*str)<91)
		{
			(*str) += 32;
		}
		str++;
	}
	return ret;
}
int main()
{
	char arr [] = "HELLO";
	arr[0] ='h';  
	//运行通过
	printf("%s\n", arr);
	toLowerCase(arr);
	printf("%s\n", arr);

	//char *arr = "HELLO";
	//arr[0] = 'h';      //访问报错

	//字符数组可以直接修改内容，字符串不可以。
	//原因：字符数组会拷贝字符放在栈或堆上新的地址空间里；字符串是拿到字符的常量区地址，将字符串地址组成你要的字符序列。
	//所以你直接修改数组地址指向的字符是可以的；但是修改字符串地址指向的字符，就等同于修改字符常量区的字符，自然报错。
	system("pause");
}