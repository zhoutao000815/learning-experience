//面试题 03.04.化栈为队
//实现一个MyQueue类，该类用两个栈来实现一个队列。
//
//
//示例：
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // 返回 1
//queue.pop();   // 返回 1
//queue.empty(); // 返回 false
//
//说明：
//
//你只能使用标准的栈操作 -- 也就是只有 push to top, peek / pop from top, size 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
//
//列）来模拟一个栈，只要是标准的栈操作即可。
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
//通过次数18, 178提交次数25, 605
//请问您在哪类招聘中遇到此题？
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//一个栈用来push，一个用来pop。
//push直接push即可。
//当需要取pop队头和取队头时，如果pop栈为空，就将push 栈里的数据倒过去。这时pop栈就不为空了。
//pop栈不为空时，pop栈的栈顶元素就是push栈的最先进来的元素，取则取，出则保存出。
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