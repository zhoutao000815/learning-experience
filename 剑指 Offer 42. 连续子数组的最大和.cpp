//��ָ Offer 42. ���������������
//����һ���������飬�����е�һ������������������һ�������顣������������ĺ͵����ֵ��
//
//Ҫ��ʱ�临�Ӷ�ΪO(n)��
//
//
//
//ʾ��1 :
//
//���� : nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//��� : 6
// ���� : ����������[4, -1, 2, 1] �ĺ����Ϊ 6��
//
//
//
//
//	 ��Դ�����ۣ�LeetCode��
//	 ���ӣ�https ://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
//	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//����һ:���������������������
		//������:����

		//������:��̬�滮
		int max = nums[0];
		for (int i = 1; i<nums.size(); i++)
		{
			if (nums[i - 1] <= 0)
			{
				//nums[i]=nums[i];
			}
			else    //nums[i-1]>0
			{
				nums[i] += nums[i - 1];
			}
			if (nums[i]>max)
			{
				max = nums[i];
			}
		}
		return max;
	}
};