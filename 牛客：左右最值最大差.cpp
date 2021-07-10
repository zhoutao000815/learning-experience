//链接：https://www.nowcoder.com/questionTerminal/f5805cc389394cf69d89b29c0430ff27
//来源：牛客网
//
//左右最值最大差
//热度指数：8471时间限制：C / C++ 3秒，其他语言6秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，右部分A[K + 1..N - 1]，K可以取值的范围是[0, N - 2]。求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？
//
//给定整数数组A和数组的大小n，请返回题目所求的答案。
//
//测试样例：
//[2, 7, 3, 1, 1], 5
//返回：6

//贪心：
//首先找到最大值以及最大值所在的位置pos：
//1.如果pos=0，那么最大差值肯定是A[[0]-A[n-1]，因为左部分最大值必然是A[0]，
//右部分必然要包含A[n-1]，那么右部分要取的最大值只会>=A[n-1]，因为是取大值比较。
//2.如果pos=n-1，那么最大差值肯定是A[n-1]-A[0]，道理和1一样
//3.如果pos是在中间位置，那么就是取(A[pos] - A[0]) 和(A[pos] - A[n-1])中最大的一个。 /***/
class MaxGap{
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		int max = 0;
		int pos = 0;
		for (int i = 0; i < n; i++)
		if (max < A[i]){
			max = A[i];
			pos = i;
		}
		if (pos == 0)
			return A[0] - A[n - 1];
		if (pos == n - 1)
			return A[n - 1] - A[0];
		int left = (A[pos] - A[0]);
		int right = (A[pos] - A[n - 1]);
		return left > right ? left : right;
	}
};

//笨蛋暴力法:两个数据结构，左边大堆，右边set排序。
//分别取A[i]每个位置左边插入，右边删除，进行n-2次，求出两个数据结构最大值差值。
//保留最大的差值返回。
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		priority_queue<int> big_heap;
		big_heap.push(A[0]);
		set<int> s(A.begin() + 1, A.end());
		int bignum_left = A[0];
		int bignum_right = *(--s.end());
		int rel = abs(bignum_left - bignum_right);
		for (int i = 1; i<n - 1; i++)
		{
			big_heap.push(A[i]);
			s.erase(A[i]);
			bignum_left = big_heap.top();
			bignum_right = *(--s.end());
			rel = max(rel, abs(bignum_left - bignum_right));
		}
		return rel;
	}
};