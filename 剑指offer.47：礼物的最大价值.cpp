//剑指 Offer 47. 礼物的最大价值
//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
//
//示例 1:
//
//输入 :
//	[
//		[1, 3, 1],
//		[1, 5, 1],
//		[4, 2, 1]
//	]
//输出 : 12
//解释 : 路径 1→3→5→2→1 可以拿到最多价值的礼物
//
//
//	 提示：
//
//	 0 < grid.length <= 200
//	 0 < grid[0].length <= 200
//
//
//	 来源：力扣（LeetCode）
// 链接：https ://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int row = grid.size(), col = grid[0].size();
		//动态规划
		//由于只能向下或者向右走，只要求出走到当前格子能获得的最大价值，然后依次递推，求出右下即可。
		//第一行只能从左边累计，第一列只能从上边累计。
		//其他的都需要判断，判断上面累加的大，还是左边累加的大，将大的累加到当前格子即可。
		for (int i = 1; i<col; i++)  //处理第一行
		{
			grid[0][i] += grid[0][i - 1];
		}

		for (int i = 1; i<row; i++) //处理第一列
		{
			grid[i][0] += grid[i - 1][0];
		}

		for (int i = 1; i<row; i++)
		{
			for (int j = 1; j<col; j++)
			{
				grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[row - 1][col - 1];
	}
};