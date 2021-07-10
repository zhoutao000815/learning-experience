//54. 螺旋矩阵
//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//示例 1：
//
//
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]
//示例 2：
//
//
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//
//
//提示：
//
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 10
//- 100 <= matrix[i][j] <= 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/spiral-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//层模拟
//注意：边界的控制，以及特殊情况：行列不均的情况
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> rel;
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return rel;
		}
		//四个边界
		int left = 0, up = 0;
		int down = matrix.size() - 1;
		int right = matrix[0].size() - 1;
		while (left <= right &&  up <= down)
		{
			for (int row = up, col = left; col <= right; col++)//完整的一行
			{
				rel.push_back(matrix[row][col]);
			}
			for (int row = up + 1, col = right; row <= down; row++) //完整的一列
			{
				rel.push_back(matrix[row][col]);
			}
			if (left<right && up<down)    //针对行列不均时，剩下的哪一行或一列，已经在上面处理了，判断一下是否进入，防止越界
			{
				for (int row = down, col = right - 1; col >= left; col--)
				{
					rel.push_back(matrix[row][col]);
				}
				for (int row = down - 1, col = left; row>up; row--)
				{
					rel.push_back(matrix[row][col]);
				}
			}
			left++; up++; right--; down--;
		}
		return rel;
	}
};


//59. 螺旋矩阵 II
//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//示例 1：
//
//
//输入：n = 3
//输出：[[1, 2, 3], [8, 9, 4], [7, 6, 5]]
//示例 2：
//
//输入：n = 1
//输出：[[1]]
//
//
//提示：
//1 <= n <= 20
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/spiral-matrix-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> rel(n, vector<int>(n, 0));
		int left = 0; int up = 0;
		int right = n - 1; int down = n - 1;
		int qcount = 1;
		while (left <= right && up <= down)
		{
			for (int row = up, col = left; col <= right; col++)
				rel[row][col] = qcount++;
			for (int row = up + 1, col = right; row <= down; row++)
				rel[row][col] = qcount++;
			//由于是n*n的矩阵，不存在圈模拟时有剩余一行或一列的情况，无需判断。
			for (int row = down, col = right - 1; col >= left; col--)
				rel[row][col] = qcount++;
			for (int row = down - 1, col = left; row>up; row--)
				rel[row][col] = qcount++;
			left++; right--; up++; down--;
		}
		return rel;
	}
};

