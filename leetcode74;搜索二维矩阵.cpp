//74. ������ά����
//��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
//
//ÿ���е����������Ұ��������С�
//ÿ�еĵ�һ����������ǰһ�е����һ��������
//
//
//ʾ�� 1��
//
//
//���룺matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 3
//�����true
//
//���룺matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 13
//�����false
//
//
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/search-a-2d-matrix
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//����һ:����һά�������飬���ֲ���
		//�У�line  �У�row
		int line = matrix.size();
		int row = matrix[0].size();
		int vvsize = line*row;

		//���ڶ��ֲ���
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

		//������:���ζ��ֲ��ң�������һ��ȷ��������������һ��ȷ�����
	}
};