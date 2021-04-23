//剑指 Offer 59 - II.队列的最大值
//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//
//若队列为空，pop_front 和 max_value 需要返回 - 1
//
//示例 1：
//
//输入 :
//["MaxQueue", "push_back", "push_back", "max_value", "pop_front", "max_value"]
//[[], [1], [2], [], [], []]
//输出 : [null, null, null, 2, 1, 2]
//	示例 2：
//
//输入 :
//	 ["MaxQueue", "pop_front", "max_value"]
//	 [[], [], []]
// 输出 : [null, -1, -1]
//
// 输出 : [null, -1, -1]
//
//
//	  限制：
//
//	  1 <= push_back, pop_front, max_value的总操作数  <= 10000
//	  1 <= value <= 10 ^ 5
//
//
//
//	  来源：力扣（LeetCode）
//  链接：https ://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
//	  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
//=======================================================================、
//思路
//一般这种最大队列，之前还有一个最小栈，都不能单单的用一个int去存放max，因为涉及到删数据，刚好把之前那个最大值删掉了呢?最大值现在又是谁呢?
//所以，一般都有一个辅助保存最值的数据结构，之前最小栈是一个辅助栈，这个最大队列用一个栈显然不行的，
//假设是个递增的辅助栈max，如果队列出数据，栈顶最后进，队列删完了，栈还没有完。错！
//假设用一个递增的辅助队列，如果在最大值之后，又插入了较小的；这时开始出数据，当出数据出到最大值，我们发现，max队列出完了，但是队列还有！错！
//上述两者都是最大值的删除之后，被小数据影响了。既然递增会被小数据影响，来试试递减。
//弄一个保持递减的辅助队列，当出现比当前队尾大的，我们保存他it，这样即使删到这个较大值，前面的小数据也被删完了，而后面的数据一样会因为保持递减队列保存。
//现在的问题是，如何保存这个it，要保持这个辅助队列递减，这个it又比之前的数据大，一定涉及尾部删除小数据，双端队列可以。
//其实用vector模拟双端队列也可以，只不过涉及数据挪动效率问题，而且还要自己控制头尾。

class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		if (Q.empty())
		{
			return -1;
		}
		return Max.front();
	}

	void push_back(int value) {
		if (Q.empty())
		{
			Max.push_back(value);
			Q.push(value);
			return;
		}
		if (value>Q.back())
		{
			while (!Max.empty() && Max.back()<value)
			{
				Max.pop_back();
			}
		}
		Max.push_back(value);
		Q.push(value);
	}

	int pop_front() {
		if (Q.empty())
		{
			return -1;
		}
		if (Q.front() == Max.front())
		{
			Max.pop_front();
		}
		int ret = Q.front();
		Q.pop();
		return ret;
	}

private:
	queue<int> Q;
	deque<int> Max;
};

/**
* Your MaxQueue object will be instantiated and called as such:
* MaxQueue* obj = new MaxQueue();
* int param_1 = obj->max_value();
* obj->push_back(value);
* int param_3 = obj->pop_front();
*/