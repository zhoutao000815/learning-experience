#include"My_priority_queue.h"
using namespace zt;
int main()
{
	std::vector<int> v1 = { 13, 26, 54, 25, 36, 23, 77, 98, 69 };
	My_priority_queue <int, std::vector<int>> q1(v1.begin(), v1.end());
	std::cout << "size：" << q1.size() << std::endl;
	q1.printf_My_priority_queue();
	std::cout << "size：" << q1.size() << std::endl;

	My_priority_queue <int, std::vector<int>, grater<int>> q2;
	//当我们比较的是自定义类型，而且没有重载比较运算符时，又不能修改自定义类。该怎么办呢?
	//直接在创建优先级队列之前，写一个仿函数出来，在（）运算符重载里，实现比较逻辑。
	q2.push(13);
	q2.push(3);
	q2.push(1);
	q2.push(1);
	q2.push(9);
	q2.push(8);
	q2.push(66);
	q2.push(33);
	q2.push(123);
	std::cout << "top：" << q2.top() << std::endl;
	std::cout << "size：" << q2.size() << std::endl;
	q2.printf_My_priority_queue();
	std::cout << "size：" << q2.size() << std::endl;
	return 0;
}