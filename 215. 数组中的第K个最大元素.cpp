//215. �����еĵ�K�����Ԫ��
//��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
//
//ʾ�� 1:
//
//���� : [3, 2, 1, 5, 6, 4] �� k = 2
//��� : 5
//	 ʾ�� 2 :
//
// ���� : [3, 2, 3, 1, 2, 4, 5, 5, 6] �� k = 4
//  ��� : 4


//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		//����һ��ȫ������,ɾ���Ѷ��������µ�����ѭ��k��
		// // �������е�Ԫ���ȷ������ȼ�������
		// priority_queue<int> p(nums.begin(), nums.end());
		// // �����ȼ�������ǰk-1��Ԫ��ɾ����
		// for(int i= 0; i < k-1; ++i)
		// {
		//     p.pop();
		// }
		// return p.top();

		//������������һ��K�����ֵ�С�ѣ�Ȼ����Ѷ���С�ıȽϣ����ڶѶ�����ѣ����µ�����
		//�������Ѷ����ݾ��ǵ�K��ģ�
		priority_queue <int, vector<int>, greater<int>> kMinHeap(nums.begin(), nums.begin() + k);
		for (int i = k; i<nums.size(); i++)
		{
			if (nums[i]>kMinHeap.top())
			{
				kMinHeap.pop();
				kMinHeap.push(nums[i]);
			}

		}
		return kMinHeap.top();

		//������:����ȡ��k�����ݡ�
		//  sort(nums.begin(),nums.end());
		//  return nums[nums.size()-k];
	}
};