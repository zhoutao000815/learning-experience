//66. 加一
//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//
//
//示例 1：
//
//输入：digits = [1, 2, 3]
//输出：[1, 2, 4]
//解释：输入数组表示数字 123。
//
//示例 2：
//
//输入：digits = [4, 3, 2, 1]
//输出：[4, 3, 2, 2]
//解释：输入数组表示数字 4321。
//
//示例 3：
//
//输入：digits = [0]
//输出：[1]
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/plus-one
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<stdio.h>
#include<Windows.h>
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int key = digitsSize - 1;    //记录下标
	digits[key]++;            //最低位+1
	while (digits[key] >= 10 && key>0)  //如果当前下标大于10再进行进位，如果是最高位不做进位处理，因为没有多余空间【-1】
	{
		digits[key] = 0;
		key--;
		digits[key]++;
	}
	int up = digitsSize;     //up记录需要malloc的数组大小
	if (digits[key] == 10)    //最高位【0】为10则需要进位，
	{
		up++;
	}
	*returnSize = up;       //返回数组的大小
	int *arr = (int *)malloc(sizeof(int)*up);
	if (up>digitsSize)         //最高位【0】有进位=10的情况，
	{
		arr[0] = 1;
		arr[1] = 0;
		memcpy(arr + 2, digits + 1, (digitsSize - 1) * 4);
	}
	else                    //最高位没有进位的情况
	{
		memcpy(arr, digits, (digitsSize)* 4);
	}
	return arr;
}
int main()
{
	//char *p = "abcdef", *r;
	//long *q;
	//q = (long*)p;
	//q++;
	//r = (char*)q;
	//long m = 25345;
	//printf("%s\n", r);

	system("pause");
}