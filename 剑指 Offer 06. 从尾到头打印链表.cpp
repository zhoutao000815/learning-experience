//��ָ Offer 06. ��β��ͷ��ӡ����
//����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
//
//
//
//ʾ�� 1��
//
//���룺head = [1, 3, 2]
//�����[2, 3, 1]
//
//���룺head = [1, 3, 2]
//�����[2, 3, 1]
//
//
//���ƣ�
//
//0 <= ������ <= 10000
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> v;
		while (head != NULL)
		{
			v.push_back(head->val);
			head = head->next;
		}
		std::reverse(v.begin(), v.end());
		return v;
	}
};