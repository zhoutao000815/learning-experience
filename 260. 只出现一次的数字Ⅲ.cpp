//260. 只出现一次的数字 III
//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//
//
//
//进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 1, 3, 2, 5]
//输出：[3, 5]
//解释：[5, 3] 也是有效的答案。
//示例 2：
//
//输入：nums = [-1, 0]
//输出：[-1, 0]
//示例 3：
//
//输入：nums = [0, 1]
//输出：[1, 0]

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/single-number-iii/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//第一步：全部异或，得到的结果sum = 两个只出现一次数字异或的结果（ret1^ret2）
		int sum = 0;
		for (auto e : nums)
		{
			sum ^= e;
		}
		//第二步：找出ret1和ret2比特位不同并且最小的哪一位（任意哪一位都可以，只要不同即可，作为标识去区分。）
		int pos = 0;
		while (((sum >> pos) & 1) != 1)
		{
			pos++;
		}
		//第三步:分组异或，用标识的比特位，把两个结果分在两组数字里去异或，得出结果
		int ret1 = 0;
		int ret2 = 0;
		for (auto e : nums)
		{
			if (((e >> pos) & 1) == 1)
			{
				ret1 ^= e;
			}
			else
			{
				ret2 ^= e;
			}
		}
		vector<int> v(2, 0);
		v[0] = ret1;
		v[1] = ret2;
		return v;
	}
};