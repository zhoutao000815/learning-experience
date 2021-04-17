//������ 03.04.��ջΪ��
//ʵ��һ��MyQueue�࣬����������ջ��ʵ��һ�����С�
//
//
//ʾ����
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // ���� 1
//queue.pop();   // ���� 1
//queue.empty(); // ���� false
//
//˵����
//
//��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek / pop from top, size �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������
//
//�У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������
//ͨ������18, 178�ύ����25, 605
//��������������Ƹ���������⣿
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������



//һ��ջ����push��һ������pop��
//pushֱ��push���ɡ�
//����Ҫȡpop��ͷ��ȡ��ͷʱ�����popջΪ�գ��ͽ�push ջ������ݵ���ȥ����ʱpopջ�Ͳ�Ϊ���ˡ�
//popջ��Ϊ��ʱ��popջ��ջ��Ԫ�ؾ���pushջ�����Ƚ�����Ԫ�أ�ȡ��ȡ�����򱣴����
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		Spush.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int Fval = peek();
		Spop.pop();
		return Fval;
	}

	/** Get the front element. */
	int peek() {
		if (Spop.empty())
		{
			while (!Spush.empty())
			{
				Spop.push(Spush.top());
				Spush.pop();
			}
		}
		return Spop.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return Spush.empty() && Spop.empty();
	}
private:
	stack<int> Spush;
	stack<int> Spop;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/