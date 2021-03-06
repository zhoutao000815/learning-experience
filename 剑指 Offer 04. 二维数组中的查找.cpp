//剑指 Offer 04. 二维数组中的查找
//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//
//
//
//示例 :
//
//现有矩阵 matrix 如下：
//
//[
//	[1, 4, 7, 11, 15],
//	[2, 5, 8, 12, 19],
//	[3, 6, 9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//给定 target = 5，返回 true。
//
//给定 target = 20，返回 false。
//
//
//
//限制：
//
//0 <= n <= 1000
//
//0 <= m <= 1000
//
//注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
//
//leetcode链接：https ://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

//帮助理解的博客链接：https://blog.csdn.net/Zhou000815/article/details/115032592
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
	if (matrixSize == 0 || *matrixColSize == 0)
	{
		return false;
	}
	//方法一:暴力遍历
	//就不写了，双层循环控制数组元素排列，挨个对比即可。

	//方法二:以右上或左下为标准搜索,为什么?
	//行：matrixSize 
	int row = matrixSize, col = *matrixColSize;
	int i = 0; //行计数
	int j = col - 1; //列计数
	while (i<row && j>-1)
	{
		if (matrix[i][j]>target)
		{
			j--;
			if (j == -1)
			{
				return false;
			}
		}
		else if (matrix[i][j]<target)
		{
			i++;
			if (i == row)
			{
				return false;
			}
		}
		else  //(matrix[i][j]==target)
		{
			return true;
		}
	}
	return false;
}