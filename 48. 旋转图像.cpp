//48. 旋转图像
//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
//
//
//
//示例 1：
//
//
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
//示例 2：
//
//
//输入：matrix = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
//输出：[[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]
//示例 3：
//
//输入：matrix = [[1]]
//输出：[[1]]
//示例 4：
//
//输入：matrix = [[1, 2], [3, 4]]
//输出：[[3, 1], [4, 2]]
//
//
//提示：
//
//matrix.length == n
//matrix[i].length == n
//1 <= n <= 20
//- 1000 <= matrix[i][j] <= 1000

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/rotate-image/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<iostream>
#include<Windows.h>
using namespace std;

void fourNumsReverse(int *a1, int *a2, int *a3, int *a4) //顺时针替换。
{
	int temp = *a1;
	*a1 = *a4;
	*a4 = *a3;
	*a3 = *a2;
	*a2 = temp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
	//原地旋转，使用辅助二维数组太简单了
	//思路：将这个二维数组看成‘回’字状，有n/2+n%2个‘口’。一次旋转一个口即可。
	//如何旋转?不难发现：因为正方形的缘故，要对应的四个位置原地旋转一次（90°），旋转一条边后，就完成了一个‘口’。

	//迭代和递归都能完成，但是对应的位置关系如何找？仔细考虑会发现规律

	//迭代法
	int n1 = *matrixColSize;   //n1用来表示最外层口，用来控制进行几个‘口’的旋转的计算
	int n2 = n1;              //n2表示每一个‘口’的边长，每一个口完成旋转后，边长会-=2；
	for (int groups = 0; groups <n1 / 2; groups++)  //奇数个口的话，余数对应的口为1x1，无需旋转，偶数能整除。
	{
		//行：row 列：col
		//下面表示每一条边对应的四个位置，以及每一轮‘口’旋转后向内缩一圈
		int pos1row = 0 + groups, pos1col = 0 + groups;
		int pos2row = 0 + groups, pos2col = n1 - groups - 1;
		int pos3row = n1 - groups - 1, pos3col = n1 - groups - 1;
		int pos4row = n1 - groups - 1, pos4col = 0 + groups;
		for (int edge = 0; edge<n2 - 1; edge++)  //一条边不需要旋转N个数字，N-1个即可。
		{
			fourNumsReverse(&matrix[pos1row][pos1col], &matrix[pos2row][pos2col], &matrix[pos3row][pos3col], &matrix[pos4row][pos4col]);
			//条件更新，
			pos1col++;   //pos1向右移动，列++
			pos2row++;   //pos2向下移动，行++
			pos3col--;   //pos3向左移动，列--
			pos4row--;   //pos4向上移动，行--
		}
		n2 -= 2;
	}

	//递归法，其实和迭代没有区别，只是将循环变成了-1式的递归，
}
int main()
{

	system("pause");
}