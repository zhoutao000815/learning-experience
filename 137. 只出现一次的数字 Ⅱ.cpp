﻿//137. 只出现一次的数字 II
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//
//说明：
//
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//示例 1:
//
//输入 : [2, 2, 3, 2]
//输出 : 3
//	 示例 2 :
//
// 输入 : [0, 1, 0, 1, 0, 1, 99]
//  输出 : 99

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/single-number-ii/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		//思路
		//将每个数字的相同比特位依次相加，求出该比特位有多少元素出现了1，出现三次的取模为0，不为0的说明出现一次数字的该比特位为1 ，        //全部或运算，得出结果
		for (int i = 0; i<32; i++)
		{
			int count = 0;
			for (auto e : nums)
			{
				if ((e >> i) & 1)
				{
					count++;
				}
			}
			if (count % 3 != 0)
			{
				ret |= 1 << i;
			}
		}
		return ret;
	}
};
