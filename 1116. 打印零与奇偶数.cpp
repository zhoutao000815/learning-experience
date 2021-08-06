//1116. 打印零与奇偶数
//假设有这么一个类：
//
//class ZeroEvenOdd {
//	public ZeroEvenOdd(int n) { ... }      // 构造函数
//	public void zero(printNumber) { ... }  // 仅打印出 0
//	public void even(printNumber) { ... }  // 仅打印出 偶数
//	public void odd(printNumber) { ... }   // 仅打印出 奇数
//}
//相同的一个 ZeroEvenOdd 类实例将会传递给三个不同的线程：
//
//线程 A 将调用 zero()，它只输出 0 。
//线程 B 将调用 even()，它只输出偶数。
//线程 C 将调用 odd()，它只输出奇数。
//每个线程都有一个 printNumber 方法来输出一个整数。请修改给出的代码以输出整数序列 010203040506...，其中序列的长度必须为 2n。
//
//
//
//示例 1：
//
//输入：n = 2
//输出："0102"
//说明：三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
//示例 2：
//
//输入：n = 5
//输出："0102030405"
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/print-zero-even-odd
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路：用C++11自带线程、锁、条件变量去控制打印顺序。
//根据题目思路，每次打印完数字后要回到0值，所以需要一个标准位 is_zero说明该打印0了。
//另外打印数字的线程也有先后顺序，还是交替打印，所以需要另外一个标志位，0打完该打奇数还是偶数。
//o值线程用is_zero控制即可，奇数偶数线程必须得0打完，并且轮到自己时才打印。具体逻辑看代码注释
class ZeroEvenOdd {
private:
	int n;
	bool is_zero = true;
	bool flag = true;
	condition_variable cv;
	mutex mtx;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		int i = 0;
		while (i<n)          //一共要打i个0.
		{
			unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [&]()->bool{return is_zero; });     //is_zero为真则打印0值。
			printNumber(0);
			i++;
			is_zero = false;
			flag = !flag;                     //用逻辑取反来控制下一个该打印奇数或者偶数。
			cv.notify_all();
		}

	}

	void even(function<void(int)> printNumber) {
		int i = 2;
		while (i <= n)
		{
			unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [&]()->bool{return !is_zero && flag; });
			printNumber(i);
			i += 2;
			is_zero = true;                   //表明该回到打印0值线程
			cv.notify_all();
		}

	}

	void odd(function<void(int)> printNumber) {
		int i = 1;
		while (i <= n)
		{
			unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [&]()->bool{return !is_zero && !flag; });    //奇数线程先打印，flag初始为true
			printNumber(i);
			i += 2;
			is_zero = true;                  //表明该回到打印0值线程
			cv.notify_all();
		}

	}
};