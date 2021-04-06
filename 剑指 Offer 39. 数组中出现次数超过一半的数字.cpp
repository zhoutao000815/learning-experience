//剑指 Offer 39. 数组中出现次数超过一半的数字
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//
//
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//
//
//
//示例 1:
//
//输入 : [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出 : 2

	//来源：力扣（LeetCode）
 //  链接：https ://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
 //  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//方法一:计数法，（哈希表统计出现次数）  （时间空间都为O(N)）
		//方法二：排序取中，因为次数大于一半，所以最中间的一定是结果ret （排序算法最低也是 n*logn）
		//方法三:摩尔投票法
		//第一步:首先假设一个结果ret，
		//第二步：遍历检测，相同则票数+1，不同则-1，
		//第三步:对票数进行检测，票数为0了，说明之前投票为无效票数，重新选定结果ret。
		//因为题目前提：这个过半数字一定存在。所以票数一定为正数，
		//当然如果没有这个前提，票数结果就不得而知了，最后得到的结果就是出现次数最多的数字，而不是过半数字。
		int ret;
		int votes = 0;
		for (auto e : nums)
		{
			if (votes == 0)
			{
				ret = e;
			}
			votes += (ret == e ? 1 : -1);
		}
		return ret;
	}
};