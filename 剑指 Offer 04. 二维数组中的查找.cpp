//��ָ Offer 04. ��ά�����еĲ���
//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������
//
//
//
//ʾ�� :
//
//���о��� matrix ���£�
//
//[
//	[1, 4, 7, 11, 15],
//	[2, 5, 8, 12, 19],
//	[3, 6, 9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//���� target = 5������ true��
//
//���� target = 20������ false��
//
//
//
//���ƣ�
//
//0 <= n <= 1000
//
//0 <= m <= 1000
//
//ע�⣺��������վ 240 ����ͬ��https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
//
//leetcode���ӣ�https ://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

//�������Ĳ������ӣ�https://blog.csdn.net/Zhou000815/article/details/115032592
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
	if (matrixSize == 0 || *matrixColSize == 0)
	{
		return false;
	}
	//����һ:��������
	//�Ͳ�д�ˣ�˫��ѭ����������Ԫ�����У������Աȼ��ɡ�

	//������:�����ϻ�����Ϊ��׼����,Ϊʲô?
	//�У�matrixSize 
	int row = matrixSize, col = *matrixColSize;
	int i = 0; //�м���
	int j = col - 1; //�м���
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