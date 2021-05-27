//338. 比特位计数
//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
//
//示例 1:
//
//输入 : 2
//输出 : [0, 1, 1]
//	 示例 2 :
//
// 输入 : 5
//  输出 : [0, 1, 1, 2, 1, 2]
//   进阶 :
//
//
//	  来源：力扣（LeetCode）
//  链接：https ://leetcode-cn.com/problems/counting-bits
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
	//解法一:暴力法
	// int get_bit_1_nums(int n)
	// {
	//     int count=0;
	//     while(n)
	//     {
	//         n&=n-1;
	//         count++;
	//     }
	//     return count;
	// }
	// vector<int> countBits(int n) {
	//     vector<int> rel;
	//     for(int i=0;i<=n;i++)
	//     {
	//         rel.push_back(get_bit_1_nums(i));
	//     }
	//     return rel;
	// }

	//解法二:动态规划，最高有效位
	vector<int> countBits(int n) {
		vector<int> rel(n + 1);
		int highbit = 0;
		for (int i = 1; i <= n; i++)
		{
			if ((i&i - 1) == 0)
			{
				highbit = i;
			}
			rel[i] = rel[i - highbit] + 1;
		}
		return rel;
	}
};