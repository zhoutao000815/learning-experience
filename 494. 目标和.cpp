//494. 目标和
//给你一个整数数组 nums 和一个整数 target 。
//
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//
//例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//
//
//示例 1：
//
//输入：nums = [1, 1, 1, 1, 1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//示例 2：
//
//输入：nums = [1], target = 1
//输出：1
//
//
//提示：
//
//1 <= nums.length <= 20
//0 <= nums[i] <= 1000
//0 <= sum(nums[i]) <= 1000
//- 1000 <= target <= 1000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/target-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//回溯暴力法：共n个数字，每个数字都有'+' 或'-'两种选择，要把每个数字都进行运算，2的n次方种，遍历后得到结构 == target？count++
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int count=0;
//         findTargetSumWays(nums,target,0,0,count);
//         return count;
//     }
//     void findTargetSumWays(vector<int>& nums, int target,int index,int res,int &count)
//     {
//         if(index==nums.size())
//         {
//             count += (res==target?1:0);
//         }
//         else
//         {
//             findTargetSumWays(nums,target,index+1,res+nums[index],count);
//             findTargetSumWays(nums,target,index+1,res-nums[index],count);
//         }
//     }
// };

//动态规划：01背包问题：参考官方题解，采用了一定的数学推导，二维dp，可以用滚动数组进行空间优化。
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum=0;
//         for(auto &num:nums)
//             sum+=num;
//         int diff=sum-target;                 
//         if(diff<0 || diff%2!=0)
//             return 0;

//         int n=nums.size(),reg=(diff>>1);
//         vector<vector<int>> dp(n+1,vector<int>(reg+1,0));
//         dp[0][0]=1;
//         for(int i=1;i<=nums.size();i++)
//         {
//             int line=nums[i-1];
//             for(int j=0;j<=reg;j++)
//             {
//                 dp[i][j]+=dp[i-1][j];
//                 if(j>=line)
//                     dp[i][j]+=dp[i-1][j-line];
//             }
//         }
//         return dp[n][reg];
//     }
// };

//动态规划：一般逻辑，这道题的关键不是nums[i]的选与不选，而是nums[i]是加还是减，那么我们就可以将方程定义为：
//dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]  即：当前方案数='+'当前数字的方案数 + '-'当前数字的方案数

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int n = nums.size();
		int sum = 0;
		for (auto number : nums) sum += number;
		if (target > sum) return 0;                                             //目标值大于总和，返回0.
		vector<vector<int>> dp(n + 1, vector<int>(2 * (sum + 1), 0));           //多开一行一列方便初始化。
		dp[0][sum] = 1;
		int curSum = 0;
		for (int i = 1; i <= n; ++i) {
			curSum += nums[i - 1];												//当前行的size的绝对值。
			for (int j = sum - curSum; j <= sum + curSum; ++j) {
				dp[i][j] =
					(j + nums[i - 1] < 2 * (sum + 1) ? dp[i - 1][j + nums[i - 1]] : 0) +             
					(j - nums[i - 1] >= 0 ? dp[i - 1][j - nums[i - 1]] : 0);
			}
		}
		return dp[n][target + sum];
	}
};

// 作者：keepal
// 链接：https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-si-kao-quan-guo-cheng-by-keepal/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。