//215. 数组中的第K个最大元素
//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//示例 1:
//
//输入 : [3, 2, 1, 5, 6, 4] 和 k = 2
//输出 : 5
//	 示例 2 :
//
// 输入 : [3, 2, 3, 1, 2, 4, 5, 5, 6] 和 k = 4
//  输出 : 4


//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		//方法一：全部建堆,删除堆顶，再向下调整。循环k次
		// // 将数组中的元素先放入优先级队列中
		// priority_queue<int> p(nums.begin(), nums.end());
		// // 将优先级队列中前k-1个元素删除掉
		// for(int i= 0; i < k-1; ++i)
		// {
		//     p.pop();
		// }
		// return p.top();

		//方法二：建立一个K个数字的小堆，然后与堆顶最小的比较，大于堆顶则入堆，向下调整。
		//最后这个堆顶数据就是第K大的，
		priority_queue <int, vector<int>, greater<int>> kMinHeap(nums.begin(), nums.begin() + k);
		for (int i = k; i<nums.size(); i++)
		{
			if (nums[i]>kMinHeap.top())
			{
				kMinHeap.pop();
				kMinHeap.push(nums[i]);
			}

		}
		return kMinHeap.top();

		//方法三:排序，取第k个数据。
		//  sort(nums.begin(),nums.end());
		//  return nums[nums.size()-k];
	}
};