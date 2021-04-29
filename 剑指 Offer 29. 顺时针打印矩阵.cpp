//剑指 Offer 29. 顺时针打印矩阵
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//
//
//
//示例 1：
//
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]
//示例 2：
//
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//
//
//限制：
//
//0 <= matrix.length <= 100
//0 <= matrix[i].length <= 100
//
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//
//
//限制：
//
//0 <= matrix.length <= 100
//0 <= matrix[i].length  <= 100
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路:模拟转圈，自己写出来以后，一个一个测试用例侧过去，发现四种特殊情况。
//情况一:一行多列
//情况二:一列多行
//情况三:行比列多时，最后一圈，是向下走的一列，类比情况二
//情况四：列比行多，最后一圈，是向右走的一行，类比情况一

//虽然特殊情况处理后，依旧跑过了，但是代码冗杂，
//===========================================================================
//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		//方法一：层模拟
//		vector<int> rel;
//		if (matrix.size() == 0 || matrix[0].size() == 0)
//		{
//			return rel;
//		}
//
//		int row = matrix.size();     //行号
//		int col = matrix[0].size();    //列号
//		int rowcur = 0, colcur = 0;
//		if (row == 1)
//		{
//			for (; colcur<col; colcur++)
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//			return rel;
//		}
//		if (col == 1)
//		{
//			for (; rowcur<row; rowcur++)
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//			return rel;
//		}
//		int quares = min(row, col) / 2;  //圈数取决于行列中小的那个
//		bool rowmorecol = false;          //长出来的
//		bool colmorerow = false;
//		if (min(row, col) % 2)
//		{
//			if (row>col)
//			{
//				rowmorecol = true;
//			}
//			colmorerow = true;
//		}
//
//		for (int q = 0; q<quares; q++)
//		{
//			for (; colcur<col - 1; colcur++)  //-1后，最后一个交给列处理了，所以特殊情况四:只剩下一行的时候，没有加最右边的那个
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//			for (; rowcur<row - 1; rowcur++)  //同样，这里的-1，把最后一个交给底行处理了，所以特殊情况三:只剩下一列的时候，没有加最下面的那个
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//			//注意这里，面对一行多列，或者一列多行的情况，判定条件只能判定行是否满足或者列是否满足，另外那个就会越界。
//			for (; colcur>q; colcur--)
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//			for (; rowcur>q; rowcur--)
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//			rowcur++;
//			colcur++;
//			row--;
//			col--;
//		}
//		if (rowmorecol)
//		{
//			for (; rowcur<row - 1; rowcur++)
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//		}
//		if (colmorerow)
//		{
//			for (; colcur<col; colcur++)
//			{
//				rel.push_back(matrix[rowcur][colcur]);
//			}
//		}
//		return rel;
//	}
//};
//===========================================================================

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
			if (left<right && up<down)      //针对行列不均时，剩下的哪一行或一列，已经在上面处理了，判断一下是否进入，防止越界
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