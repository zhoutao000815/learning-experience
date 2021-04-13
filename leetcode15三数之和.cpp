//15. ����֮��
//����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 �������ҳ����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
//
//ע�⣺���в����԰����ظ�����Ԫ�顣
//
//
//
//ʾ�� 1��
//
//���룺nums = [-1, 0, 1, 2, -1, -4]
//�����[[-1, -1, 2], [-1, 0, 1]]
//ʾ�� 2��
//
//���룺nums = []
//�����[]
//ʾ�� 3��
//
//���룺nums = [0]
//�����[]
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/3sum
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		// �ҳ�a + b + c = 0
		// a = nums[i], b = nums[left], c = nums[right]
		for (int i = 0; i < nums.size(); i++) {
			// ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ�飬ֱ�ӷ��ؽ���Ϳ�����
			if (nums[i] > 0) {
				return result;
			}
			// ����ȥ�ط���������©��-1,-1,2 �������
			/*
			if (nums[i] == nums[i + 1]) {
			continue;
			}
			*/
			// ��ȷȥ�ط���
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left) {
				// ȥ�ظ��߼�����������0��0��0 �����������ֱ�ӵ��� right<=left �ˣ��Ӷ�©���� 0,0,0 ������Ԫ��
				/*
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;
				*/
				if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				}
				else {
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					// ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮��
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;

					// �ҵ���ʱ��˫ָ��ͬʱ����
					right--;
					left++;
				}
			}

		}
		return result;
	}
};