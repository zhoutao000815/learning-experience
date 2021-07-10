//63. 不同路径 II
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//
//网格中的障碍物和空位置分别用 1 和 0 来表示。
//
//
//示例 1：
//
//
//输入：obstacleGrid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
//输出：2
//解释：
//3x3 网格的正中间有一个障碍物。
//从左上角到右下角一共有 2 条不同的路径：
//1. 向右->向右->向下->向下
//2. 向下->向下->向右->向右
//示例 2：
//
//
//输入：obstacleGrid = [[0, 1], [0, 0]]
//输出：1
//
//
//提示：
//
//m == obstacleGrid.length
//n == obstacleGrid[i].length
//1 <= m, n <= 100
//obstacleGrid[i][j] 为 0 或 1
//
//n == obstacleGrid[i].length
//1 <= m, n <= 100
//obstacleGrid[i][j] 为 0 或 1
//通过次数156, 984提交次数406, 876
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/unique-paths-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//初始化第一行，第一列，由于移动方向限制，进行初始化。
//以下为状态转移方程逻辑
// if (obstacleGrid[i][j] == 0) {          // 当(i, j)没有障碍的时候，再推导dp[i][j]
//     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
// }
// else
//     dp[i][j]=0;

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));                          //全部初始化为0，第一行列无障碍物设1
//         for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;   //一旦有一个障碍物，后面的都是0
//         for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;   //同理
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (obstacleGrid[i][j] == 1) continue;
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

//由于这里 f(i, j)f(i,j) 只与 f(i - 1, j)f(i−1,j) 和 f(i, j - 1)f(i,j−1) 相关，
//我们可以运用「滚动数组思想」把空间复杂度优化称 O(m)。

​class Solution{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<int> dp(n, 0);
		dp[0] = (0 == obstacleGrid[0][0]);      //出发点有无障碍
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[j] = 0;
					continue;               //如果没有执行continue，说明该位置无障碍，反之则下一个位置。
				}
				if (j>0)
					dp[j] += dp[j - 1];         //dp[j]本身就为obstacleGrid[i-1][j],对应状态转移方程
			}
			//每一行结束后，dp[]本身就变成下次开始时的上一行。
		}
		return dp[n - 1];
	}
};