#include "Mylist.h"
#include <iostream>
using namespace zt;
template<class T>
void const_list_printf(const Mylist<T> &L)
{
	Mylist<T>::const_iterator begin= L.cbegin();
	while (begin != L.cend())
	{
		//const T& operator*()=;
		//*begin = 100;
		std::cout << *begin << "  ";
		begin++;
	}
	std::cout<<std::endl;
}


void list_printf(Mylist<int> &L)
{
	Mylist<int>::iterator begin = L.begin();
	while (begin != L.end())
	{
		*begin = 9;
		std::cout << *begin << "  ";
		begin++;
	}
	std::cout << std::endl;
}
void Mylist_test0()
{
	Mylist<int> L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	list_printf(L1);
	const_list_printf(L1);
}
void Mylist_test1()
{
	zt::Mylist<int> l1;
	zt::Mylist<int> l2(10, 5);
	const_list_printf(l2);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	zt::Mylist<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	const_list_printf(l3);
	zt::Mylist<int> l4(l3);
	const_list_printf(l4);
	l1 = l4;
	const_list_printf(l1);
}
// PushBack()/PopBack()/PushFront()/PopFront()
void Mylist_test2()
{
	// 测试PushBack与PopBack
	zt::Mylist<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	const_list_printf(l);
	l.pop_back();
	l.pop_back();
	const_list_printf(l);
	l.pop_back();
	std::cout << l.size() << std::endl;
	// 测试PushFront与PopFront
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	const_list_printf(l);
	l.pop_front();
	l.pop_front();
	const_list_printf(l);
	l.pop_front();
	std::cout << l.size() << std::endl;
}
void Mylist_test3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	zt::Mylist<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto pos = l.begin();
	l.insert(l.begin(), 0);
	const_list_printf(l);
	++pos;
	l.insert(pos, 2);
	const_list_printf(l);
	l.erase(l.begin());
	l.erase(pos);
	const_list_printf(l);
	// pos指向的节点已经被删除，pos迭代器失效
	std::cout << *pos << std::endl;
	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	std::cout << l.size() << std::endl;
}
int main()
{
	//Mylist_test0();
	//Mylist_test1();
	//Mylist_test2();
	Mylist_test3();
	return 0;
}