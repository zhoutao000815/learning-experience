//64. 最小路径和
//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//示例 1：
//
//
//输入：grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
//示例 2：
//
//输入：grid = [[1, 2, 3], [4, 5, 6]]
//输出：12
//
//
//提示：
//
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 200
//0 <= grid[i][j] <= 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-path-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//与剑指offer：礼物的最大价值相反，这个是最小价值
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		vector<vector<int>> grid_cpy(grid);
		size_t m = grid.size();
		size_t n = grid[0].size();

		for (size_t i = 1; i<m; i++)                 //第一列  
			grid_cpy[i][0] += grid_cpy[i - 1][0];
		for (size_t i = 1; i<n; i++)                 //第一列
			grid_cpy[0][i] += grid_cpy[0][i - 1];

		for (int i = 1; i<m; i++)
		{
			for (int j = 1; j<n; j++)
			{
				grid_cpy[i][j] += min(grid_cpy[i - 1][j], grid_cpy[i][j - 1]);
			}
		}
		return grid_cpy[m - 1][n - 1];
	}
};