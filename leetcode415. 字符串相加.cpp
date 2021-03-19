//415. 字符串相加
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//
//
//提示：
//
//num1 和num2 的长度都小于 5100
//num1 和num2 都只包含数字 0 - 9
//num1 和num2 都不包含任何前导零
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-strings
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
	string addStrings(string num1, string num2) {
		string sret;
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int next = 0;
		int sum1;
		int sum2;
		while (end1 >= 0 || end2 >= 0)
		{
			sum1 = end1 >= 0 ? num1[end1] - '0' : 0;
			sum2 = end2 >= 0 ? num2[end2] - '0' : 0;
			int add = sum1 + sum2 + next;
			if (add >= 10)
			{
				add %= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			//sret.insert(sret.begin(), add+'0');  //头插要挪动数据，效率低下，先尾插，最后逆置。
			sret += ('0' + add);
			--end1;
			--end2;
		}
		if (1 == next)
		{
			sret += '1';
		}
		reverse(sret.begin(), sret.end());
		return sret;
	}
};