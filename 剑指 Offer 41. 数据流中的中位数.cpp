//剑指 Offer 41. 数据流中的中位数
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
//
//例如，
//
//[2, 3, 4] 的中位数是 3
//
//[2, 3] 的中位数是(2 + 3) / 2 = 2.5
//
//设计一个支持以下两种操作的数据结构：
//
//void addNum(int num) - 从数据流中添加一个整数到数据结构中。
//double findMedian() - 返回目前所有元素的中位数。
//示例 1：
//
//输入：
//["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
//[[], [1], [2], [], [3], []]
//输出：[null, null, null, 1.50000, null, 2.00000]
//示例 2：
//
//输入：
//["MedianFinder", "addNum", "findMedian", "addNum", "findMedian"]
//[[], [2], [], [3], []]
//输出：[null, null, 2.00000, null, 2.50000]
//
//
//限制：
//最多会对 addNum、findMedian 进行 50000 次调用。
//
//站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/
//
//通过次数49, 424提交次数85, 559
//请问您应聘的哪家公司？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//


//思路：其实我们并不需要给整个数据流排序，我们只要维持两个堆，
//所有小于中位数的为一个大堆，大于中位数的为一个小堆。
//这样中位数必然取自两个堆的堆顶。或为平均数，或为单个堆顶。
//难点：如何确认新来的数据应该在哪一个堆呢？光凭两个堆的size来分配是不正确的，很有可能应该在左堆去了右堆，或相反。
//解决办法:
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}
	// 当两堆的数据个数相等时候，左边堆添加元素。
	// 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
	// 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
	// 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
	void addNum(int num) {
		if (maxHeap.size() == minHeap.size())
		{
			minHeap.push(num);
			int min_top_num = minHeap.top();
			maxHeap.push(min_top_num);
			minHeap.pop();
		}
		else
		{
			maxHeap.push(num);
			int max_top_num = maxHeap.top();
			minHeap.push(max_top_num);
			maxHeap.pop();
		}
	}

	//如果数据为偶数个：我们只要左边的最大值，右边的最小值，相加除2.0即可。并不需要之前的数字有序。
	//如果数据为奇数个：我们只要左边的最大值。
	double findMedian() {
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top())*1.0 / 2;
		else
			return maxHeap.top()*1.0;
	}
private:
	//假设用伪升序来取中位数，左边用大堆，右边用小堆。

	// 最大堆，存储左边一半的数据，堆顶为最大值
	priority_queue<int, vector<int>, less<int>> maxHeap;
	// 最小堆， 存储右边一半的数据，堆顶为最小值
	priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/