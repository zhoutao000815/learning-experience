//5797. 两个数对之间的最大乘积差
//两个数对(a, b) 和(c, d) 之间的 乘积差 定义为(a * b) - (c * d) 。
//
//例如，(5, 6) 和(2, 7) 之间的乘积差是(5 * 6) - (2 * 7) = 16 。
//给你一个整数数组 nums ，选出四个 不同的 下标 w、x、y 和 z ，使数对(nums[w], nums[x]) 和(nums[y], nums[z]) 之间的 乘积差 取到 最大值 。
//
//返回以这种方式取得的乘积差中的 最大值 。
//
//
//
//示例 1：
//
//输入：nums = [5, 6, 2, 7, 4]
//输出：34
//解释：可以选出下标为 1 和 3 的元素构成第一个数对(6, 7) 以及下标 2 和 4 构成第二个数对(2, 4)
//乘积差是(6 * 7) - (2 * 4) = 34
//示例 2：
//
//输入：nums = [4, 2, 5, 9, 7, 4, 8]
//输出：64
//解释：可以选出下标为 3 和 6 的元素构成第一个数对(9, 8) 以及下标 1 和 5 构成第二个数对(2, 4)
//乘积差是(9 * 8) - (2 * 4) = 64
//
//
//提示：
//
//4 <= nums.length <= 104
//1 <= nums[i] <= 104
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-product-difference-between-two-pairs
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int maxProductDifference(vector<int>& nums) {
		sort(nums.begin(), nums.begin() + 4);
		int big_first = nums[3];
		int big_second = nums[2];
		int small_first = nums[0];
		int small_second = nums[1];
		for (int i = 4; i<nums.size(); i++)
		{
			if (nums[i]>big_second)
			{
				if (nums[i]>big_first)
				{
					big_second = big_first;
					big_first = nums[i];
				}
				else
				{
					big_second = nums[i];
				}
			}

			if (nums[i]<small_second)
			{
				if (nums[i]<small_first)
				{
					small_second = small_first;
					small_first = nums[i];
				}
				else
				{
					small_second = nums[i];
				}
			}
		}
		return (big_first*big_second) - (small_first*small_second);
	}
};