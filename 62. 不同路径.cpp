﻿//62. 不同路径
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//
//问总共有多少条不同的路径？
//
//
//
//示例 1：
//
//
//输入：m = 3, n = 7
//输出：28
//示例 2：
//
//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右->向下->向下
//2. 向下->向下->向右
//3. 向下->向右->向下
//示例 3：
//
//输入：m = 7, n = 3
//输出：28
//示例 4：
//
//输入：m = 3, n = 3
//输出：6
//
//
//提示：
//
//1 <= m, n <= 100
//题目数据保证答案小于等于 2 * （10的九次方）
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/unique-paths
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//方法一：动态规划:用mxn的矩阵模拟，
//初始状态：dp[i][0]=1,dp[0][j]=1;
//状态转移方程：dp[i][j]=dp[i-1][j]+dp[i][j-1])    条件：i>0,j>0
//结果：dp[m-1][n-1];
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1)
			return 1;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++)  //第一列
			dp[i][0] = 1;
		for (int i = 0; i<n; i++)  //第一行
			dp[0][i] = 1;
		for (int i = 1; i<m; i++)
		{
			for (int j = 1; j<n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};

// 方法二：数学方法：排列组合
// 因为只能向下或者向右走，所以向下要走m-1步,向右要走n-1步，共m+n-2步。
// 当向下步数走完，向右只有一条路了；同理，向右步数走完，向下只有一条路了，
// 第一步：有m+n-2种走法
// 第二步：有（m+n-2）-1种走法...
// 第min（m-1，n-1）步：，就只有一条路可以选了。
// 数学C(m+n-2，m-1)  ==  C(m+n-2，n-1)
// 所以向下或者向右走顺序不重要，只要某条路走到头了，只能走唯一的一条路了。

//注意：由于m，n可能过大，超过INT_MAX，所以用long long 代替ans。
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1)
			return 1;
		long long ans = 1;

		//很妙的求C(m+n-2，m-1)的办法。
		for (int x = n, y = 1; y < m; ++x, ++y) {
			ans = ans * x / y;
		}
		return ans;
	}
};