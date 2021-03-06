//225. 用队列实现栈
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//
//
//注意：
//
//你只能使用队列的基本操作 —— 也就是 push to back、peek / pop from front、size 和 is empty 这些操作。
//你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//
//
//示例：
//
//输入：
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 2, 2, false]
//
//解释：
//MyStack myStack = new MyStack();
//myStack.push(1);
//myStack.push(2);
//myStack.top(); // 返回 2
//myStack.pop(); // 返回 2
//myStack.empty(); // 返回 False
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-stack-using-queues
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//


//两个队列，一个保持空，一个非空。
//push往非空队列里push；top就是取非空队列的back.
//pop时，将非空队列的front出到空队列尾插，直到非空队列剩下最后一个数据。这个数据就是要出的数据，保存该值，pop，返回该值。
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