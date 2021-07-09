//120. 三角形最小路径和
//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//
//每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
//
//
//
//示例 1：
//
//输入：triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
//输出：11
//解释：如下面简图所示：
//2
//3 4
//6 5 7
//4 1 8 3
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
//示例 2：
//
//输入：triangle = [[-10]]
//输出： - 10
//
//
//提示：
//
//1 <= triangle.length <= 200
//triangle[0].length == 1
//triangle[i].length == triangle[i - 1].length + 1
//- 104 <= triangle[i][j] <= 104
//
//
//进阶：
//
//你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/triangle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//=========================================================================================================
//此题类似于 剑指 Offer 47. 礼物的最大价值。

//思路：动态规划
// 解法一：因为传参是引用所以不能直接在原数组修改，只能拷贝一份出来，然后修改。
// 初始状态：dp[0][0]=triangle[0][0];
// 从第二行开始每一行都遵守下列状态转移方程
// 状态转移方程:dp[i][0] += dp[i-1][0]                                            (i>0 && i<n)
//             dp[i][j] += dp[i-1][j]<dp[i-1][j-1] ? dp[i-1][j]:dp[i-1][j-1];     (j>1 && j<i && i<n)
//             dp[i][i] += dp[i-1][i-1]                                           (i<n)

//解法二：由于每一行其实只与上一行有状态关系，所以只保存上一行路径值即可。(空间复杂度优化)
//第一行dp[0]为初始状态,从第二行开始.
//步数只能由 dp[i][j]+=dp[i-1][j]  || dp[i][j]+=dp[i-1][j-1]
//而求最小路径和，所以取上述所加值较小的哪一个。
//同时注意边界，dp[i][0]+=dp[i-1][0]  ；dp[i][i]+=dp[i-1][i-1]

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		// size_t n=triangle.size();
		// vector<int> dp(n,0);

		// dp[0]=triangle[0][0];                         //初始状态

		// for(int i=1;i<n;i++)
		// {
		//     vector<int> tmp(triangle[i]);             
		//     tmp[0]+=dp[0];                            //每一行的第一个数字都只能加自上一行的第一个数字。
		//     for(int j=1;j<i;j++)
		//     {
		//         tmp[j]+=min(dp[j-1],dp[j]);           //每一行i只能加上min（dp[i-1][j]，dp[i-1][j-1]）
		//     }
		//     tmp[i]+=dp[i-1];                          //每一行的最后一个数字只能加自上一行的最后一个数字
		//     dp=tmp;
		// }
		// int res=*min_element(dp.begin(),dp.end());
		// return res;


		int n = triangle.size();
		vector<int> f(n);
		f[0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			f[i] = f[i - 1] + triangle[i][i];               //每一行的最后一个
			for (int j = i - 1; j > 0; --j) {
				f[j] = min(f[j - 1], f[j]) + triangle[i][j];//上一行状态的小值，加上这行的初始值
			}
			f[0] += triangle[i][0];                         //每一行的第一个
		}
		return *min_element(f.begin(), f.end());
	}
};