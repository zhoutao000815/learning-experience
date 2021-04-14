//18. ����֮��
//����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣
//
//ע�⣺���в����԰����ظ�����Ԫ�顣
//
//
//
//ʾ�� 1��
//
//���룺nums = [1, 0, -1, 0, -2, 2], target = 0
//�����[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
//ʾ�� 2��
//
//���룺nums = [], target = 0
//�����[]
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/4sum
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/4sum/
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int size = nums.size();
		if (size<4)
		{
			return result;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i<size; i++)
		{
			if (nums[i] > target)
			{
				return result;
			}
			if (i>0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			for (int j = i + 1; j<size; j++)
			{
				if (j>i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				int left = j + 1;
				int right = size - 1;
				while (left<right)
				{
					if (left<right && nums[i] + nums[j] + nums[left] + nums[right]>target)
					{
						right--;
					}
					else if (left<right && nums[i] + nums[j] + nums[left] + nums[right]<target)
					{
						left++;
					}
					else
					{
						result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						while (left<right && nums[right] == nums[right - 1]) { right--; }
						while (left<right && nums[left] == nums[left + 1]) { left++; }
						right--;
						left++;
					}

				}
			}
		}
		return result;
	}
};