//74. 搜索二维矩阵
//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//每行中的整数从左到右按升序排列。
//每行的第一个整数大于前一行的最后一个整数。
//
//
//示例 1：
//
//
//输入：matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 3
//输出：true
//
//输入：matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 13
//输出：false
//
//
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/search-a-2d-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//方法一:当作一维有序数组，二分查找
		//行：line  列：row
		int line = matrix.size();
		int row = matrix[0].size();
		int vvsize = line*row;

		//用于二分查找
		int left = 0, right = vvsize - 1;
		int mid, midline, midrow;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			midline = mid / row;
			midrow = mid%row;
			if (target<matrix[midline][midrow])
			{
				right = mid - 1;
			}
			else if (target>matrix[midline][midrow])
			{
				left = mid + 1;
			}
			else
			{
				return true;
			}
		}
		return false;

		//方法二:两次二分查找，竖着找一次确定行数，横着找一次确定结果
	}
};