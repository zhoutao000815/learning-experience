//��ָ Offer 31. ջ��ѹ�롢��������
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ����磬����{ 1, 2, 3, 4, 5 } ��ĳջ��ѹջ���У�����{ 4, 5, 3, 2, 1 } �Ǹ�ѹջ���ж�Ӧ��һ���������У���{ 4, 3, 5, 1, 2 } �Ͳ������Ǹ�ѹջ���еĵ������С�
//
//
//
//ʾ�� 1��
//
//���룺pushed = [1, 2, 3, 4, 5], popped = [4, 5, 3, 2, 1]
//�����true
//���ͣ����ǿ��԰�����˳��ִ�У�
//push(1), push(2), push(3), push(4), pop() -> 4,
//push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
//ʾ�� 2��
//
//���룺pushed = [1, 2, 3, 4, 5], popped = [4, 3, 5, 1, 2]
//�����false
//���ͣ�1 ������ 2 ֮ǰ������
//
//
//��ʾ��
//
//0 <= pushed.length == popped.length <= 1000
//0 <= pushed[i], popped[i] < 1000
//pushed �� popped �����С�

//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() != popped.size())
		{
			return false;
		}

		stack<int> st;
		//��һ��ջȥģ��ʵ����ջ��ջ�Ķ��������ģ�⣿
		//����ָ��ֱ����push ��i����pop ��j��������ʼ��
		//��push���鿪ʼ�жϣ�������pop����ջ��i++������˵�����뼴����j++���������ж�ջ��Ԫ�غ�pop��j������ջ��Ϊ�յ�ǰ���£�������ջ��
		//������������ȷ���������У��ض���˫ָ�붼����ģ��жϵó������

		int pushedsize = pushed.size();
		int poppedsize = popped.size();
		int i = 0, j = 0;
		while (i<pushedsize)
		{
			if (pushed[i] != popped[j])
			{
				st.push(pushed[i]);
			}
			else
			{
				j++;                             //����ʱ�����뼴����û��Ҫ��ģ�⣬ֱ��j++��
				while (!st.empty() && st.top() == popped[j])
				{
					st.pop();
					j++;
				}
			}
			i++;
		}
		if (i == pushedsize && j == poppedsize)
			return true;

		return false;
	}
};