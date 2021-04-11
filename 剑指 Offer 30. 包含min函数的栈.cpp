//��ָ Offer 30. ����min������ջ
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У����� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��
//
//
//
//ʾ�� :
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.min();   --> ���� - 3.
//minStack.pop();
//minStack.top();      --> ���� 0.
//minStack.min();   --> ���� - 2.

//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		st.push(x);
		if (min_st.empty() || min_st.top() >= x)
		{
			min_st.push(x);
		}
	}

	void pop() {
		if (st.top() == min_st.top())
		{
			min_st.pop();
		}
		st.pop();
	}

	int top() {
		return st.top();
	}

	int min() {
		return min_st.top();
	}
private:
	stack<int> st;
	stack<int> min_st;
};
