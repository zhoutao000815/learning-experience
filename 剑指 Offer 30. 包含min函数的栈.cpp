//剑指 Offer 30. 包含min函数的栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
//
//
//
//示例 :
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.min();   --> 返回 - 3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.min();   --> 返回 - 2.

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
