//43. 字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//示例 1:
//
//输入 : num1 = "2", num2 = "3"
//输出 : "6"
//	 示例 2 :
//
// 输入 : num1 = "123", num2 = "456"
//  输出 : "56088"
//
//		来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/multiply-strings
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		//方法一：两数相乘，可以看作是num1个num2相加，但是时间复杂度和空间复杂度都比较高,可能会超时。

		string zero = "0";
		if (zero == num1 || zero == num2)
		{
			return zero;
		}
		//方法二：模拟实现竖式乘法
		//用num2的低位到高和num1相乘得到num2.size（）个字符串，再依次相加。
		size_t size1 = num1.size();
		size_t size2 = num2.size();
		string* retarry = new string[size2];
		size_t sum1 = 0;
		size_t sum2 = 0;
		size_t next = 0;      //进位
		int retarrysize = 0;
		for (int i = size2 - 1; i >= 0; i--)
		{
			next = 0;
			sum2 = num2[i] - '0';
			for (int j = size1 - 1; j >= 0; j--)
			{

				sum1 = num1[j] - '0';
				retarry[retarrysize] += (sum1*sum2 + next) % 10 + '0';  //记得是先进位，后留数，不能先留数，再进位
				next = (sum1*sum2 + next) / 10;             //同上一行
			}
			if (next != 0)
			{
				retarry[retarrysize] += next + '0';
			}
			reverse(retarry[retarrysize].begin(), retarry[retarrysize].end());   //先逆置
			retarry[retarrysize].append(retarrysize, '0');         //在加对应位次个数的0
			retarrysize++;
		}
		string retstr = "";
		while (retarrysize >= 0)
		{
			retstr = addStrings(retstr, retarry[retarrysize--]);
		}
		return retstr;
	}

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
int main()
{
	Solution s1;
	string result=s1.multiply("123456789","987654321");
	cout << result << endl;
	return 0;
}