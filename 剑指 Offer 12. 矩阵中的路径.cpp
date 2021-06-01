//剑指 Offer 12. 矩阵中的路径
//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//
//例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
//
//
//示例 1：
//
//输入：board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word = "ABCCED"
//输出：true
//示例 2：
//
//输入：board = [["a", "b"], ["c", "d"]], word = "abcd"
//输出：false
//
//
//提示：
//
//1 <= board.length <= 200
//1 <= board[i].length <= 200
//board 和 word 仅由大小写英文字母组成
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         rows = board.size();
//         cols = board[0].size();
//         for(int i = 0; i < rows; i++) {
//             for(int j = 0; j < cols; j++) {
//                 if(dfs(board, word, i, j, 0)) return true;
//             }
//         }
//         return false;
//     }
// private:
//     int rows, cols;
//     bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
//         if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
//         if(k == word.size() - 1) return true;
//         board[i][j] = '\0';
//         bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
//                       dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
//         board[i][j] = word[k];
//         return res;
//     }
// };

//上述代码虽然简单好理解，但是剪枝做的较少，时间复杂度高一点。
//DFS+剪枝
class Solution {
public:
	bool _exist(vector<vector<char>>& board, vector<vector<bool>> &bool_board, string word, int cur_row, int cur_col, int cur_char)
	{
		bool_board[cur_row][cur_col] = true;
		if (++cur_char == word.size())
			return true;
		//上搜
		if (cur_row>0 && bool_board[cur_row - 1][cur_col] == false && board[cur_row - 1][cur_col] == word[cur_char])
		{
			if (true == _exist(board, bool_board, word, cur_row - 1, cur_col, cur_char))
				return true;
		}
		//下搜
		if (cur_row<board.size() - 1 && bool_board[cur_row + 1][cur_col] == false && board[cur_row + 1][cur_col] == word[cur_char])
		{
			if (true == _exist(board, bool_board, word, cur_row + 1, cur_col, cur_char))
				return true;
		}
		//左搜
		if (cur_col>0 && bool_board[cur_row][cur_col - 1] == false && board[cur_row][cur_col - 1] == word[cur_char])
		{
			if (true == _exist(board, bool_board, word, cur_row, cur_col - 1, cur_char))
				return true;
		}
		//右搜
		if (cur_col<board[0].size() - 1 && bool_board[cur_row][cur_col + 1] == false && board[cur_row][cur_col + 1] == word[cur_char])
		{
			if (true == _exist(board, bool_board, word, cur_row, cur_col + 1, cur_char))
				return true;
		}
		bool_board[cur_row][cur_col] = false;  //走到这里说明无路可走，当前路径错误，所以将当前节点恢复为未走。
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<col; j++)
			{
				if (board[i][j] == word[0])
				{
					vector<vector<bool>> bool_board(row, vector<bool>(col, false)); //false标识还没有搜查过；true标识搜查过
					if (_exist(board, bool_board, word, i, j, 0) == true)
					{
						return true;
					}
					else
					{
						continue;
					}
				}
			}
		}
		return false;
	}
};