//225. �ö���ʵ��ջ
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨ���е�ȫ�����ֲ�����push��top��pop �� empty����
//
//ʵ�� MyStack �ࣺ
//
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
//
//
//ע�⣺
//
//��ֻ��ʹ�ö��еĻ������� ���� Ҳ���� push to back��peek / pop from front��size �� is empty ��Щ������
//����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���б����� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
//
//
//ʾ����
//
//���룺
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
//�����
//[null, null, null, 2, 2, false]
//
//���ͣ�
//MyStack myStack = new MyStack();
//myStack.push(1);
//myStack.push(2);
//myStack.top(); // ���� 2
//myStack.pop(); // ���� 2
//myStack.empty(); // ���� False
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/implement-stack-using-queues
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//


//�������У�һ�����ֿգ�һ���ǿա�
//push���ǿն�����push��top����ȡ�ǿն��е�back.
//popʱ�����ǿն��е�front�����ն���β�壬ֱ���ǿն���ʣ�����һ�����ݡ�������ݾ���Ҫ�������ݣ������ֵ��pop�����ظ�ֵ��
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (!q1.empty())
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int> &NotEmptyq = ((!q1.empty()) ? q1 : q2);
		queue<int> &Emptyq = (q1.empty() ? q1 : q2);
		while (NotEmptyq.size() != 1)
		{
			Emptyq.push(NotEmptyq.front());
			NotEmptyq.pop();
		}
		int lastval = NotEmptyq.back();
		NotEmptyq.pop();
		return lastval;
	}

	/** Get the top element. */
	int top() {
		if (!q2.empty())
		{
			return q2.back();
		}
		return q1.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/