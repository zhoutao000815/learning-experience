//209. ������С��������
//����һ������ n ���������������һ�������� target ��
//
//�ҳ���������������� �� target �ĳ�����С�� ����������[numsl, numsl + 1, ..., numsr - 1, numsr] ���������䳤�ȡ���������ڷ��������������飬���� 0 ��
//
//
//
//ʾ�� 1��
//
//���룺target = 7, nums = [2, 3, 1, 2, 4, 3]
//�����2
//���ͣ�������[4, 3] �Ǹ������µĳ�����С�������顣
//ʾ�� 2��
//
//���룺target = 4, nums = [1, 4, 4]
//�����1
//ʾ�� 3��
//
//���룺target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
//�����0
//
//
//��ʾ��
//
//1 <= target <= 109
//1 <= nums.length <= 105
//1 <= nums[i] <= 105

//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/minimum-size-subarray-sum/
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		// �ⷨһ��������
		// ��ʱ
		// int add=0;
		// int addlenth=0;
		// int Minaddlenth=nums.size()+1;
		// bool HaveRet=false;
		// for(int i=0;i<nums.size();i++)
		// {
		//     add=0;
		//     for(int j=i;j<nums.size();j++)
		//     {
		//         add+=nums[i];
		//         if(add>=target)
		//         {
		//             HaveRet=true;
		//             addlenth=j-i+1;
		//             Minaddlenth=(Minaddlenth<addlenth?Minaddlenth:addlenth);
		//         }
		//     }
		// }
		// if(HaveRet)
		// {
		//     return Minaddlenth;
		// }
		// return 0;
		//=====================================================================
		//�ⷨ��:��������
		int subarrsize = nums.size() + 1;  //���ȿ���Ϊ���鳤��+1�������ҳ�������С������
		int add = 0, addlenth = 0;
		int left = 0;
		for (int right = 0; right<nums.size(); right++)
		{
			add += nums[right];
			while (add >= target)       //���ھ��貿��
			{
				addlenth = right - left + 1;
				subarrsize = (subarrsize<addlenth ? subarrsize : addlenth);
				add -= nums[left++];          //��ȥ��ߵ�ֵ�����������ƶ���ָ�롣
			}
		}
		return subarrsize = (subarrsize == nums.size() + 1 ? 0 : subarrsize);
	}
};