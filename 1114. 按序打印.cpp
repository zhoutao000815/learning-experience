//1114. 按序打印
//我们提供了一个类：
//
//public class Foo {
//	public void first() { print("first"); }
//	public void second() { print("second"); }
//	public void third() { print("third"); }
//}
//三个不同的线程 A、B、C 将会共用一个 Foo 实例。
//
//一个将会调用 first() 方法
//一个将会调用 second() 方法
//还有一个将会调用 third() 方法
//请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。
//
//
//
//示例 1:
//
//输入 : [1, 2, 3]
//输出 : "firstsecondthird"
// 解释 :
//	有三个线程会被异步启动。
//	输入[1, 2, 3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。
//	正确的输出是 "firstsecondthird"。
//	示例 2 :
//
//输入 : [1, 3, 2]
// 输出 : "firstsecondthird"
//  解释 :
//	 输入[1, 3, 2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。
//	 正确的输出是 "firstsecondthird"。
//
//
//	 提示：
//
//	 尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
//	 你看到的输入格式主要是为了确保测试的全面性。

//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/print-in-order
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Foo {
private:
	mutex mtx;
	condition_variable cv;
	bool first_cond = false;
	bool second_cond = false;
public:
	Foo() {

	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		first_cond = true;
		cv.notify_all();								    //有两个线程都在cv下等，唤醒一个的话不能保证唤醒的是second，
	}

	void second(function<void()> printSecond) {
		unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&]()->bool{return first_cond; });
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		second_cond = true;
		cv.notify_one();									//只剩下一个线程在cv下等了。
	}

	void third(function<void()> printThird) {
		unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&]()->bool{return second_cond; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
		//second_cond=false;
	}
};