//面试题 17.01.不用加号的加法
//设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
//
//示例 :
//
//输入 : a = 1, b = 1
//输出 : 2
//
//
//	 提示：
//
//	 a, b 均可能是负数或 0
//	 结果不会溢出 32 位整数
//
//	来源：力扣（LeetCode）
// 链接：https ://leetcode-cn.com/problems/add-without-plus-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int add(int a, int b) {
		int i = 0;
		int flag = 1;
		int up = 0;
		int rel = 0;
		//分情况讨论即可，注意进位，有进位处理进位；没有进位，将进位置0；
		while (i<32)
		{
			if (a&(flag << i) || b&(flag << i))
			{
				if (a&(flag << i) && b&(flag << i))
				{
					if (up == 1)
					{
						rel = rel | (flag << i);
					}
					up = 1;
				}
				else
				{
					if (up == 1)
					{
						up = 1;
					}
					else
					{
						rel = rel | (flag << i);
						up = 0;
					}
				}
			}
			else
			{
				if (up)
				{
					rel = rel | (flag << i);
				}
				up = 0;
			}
			i++;
		}
		return rel;
	}
};