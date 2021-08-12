#pragma once
#include<iostream>
#include<vector>

template<size_t N>
class my_bitset
{
public:
	my_bitset()
	{
		size_t cap = (N >> 5) + 1;
		_bits.resize(cap, 0);
	}

	int size() const
	{
		return N;
	}

	void set(size_t pos)
	{
		size_t index = pos >> 5;
		size_t num = pos % 32;
		_bits[index] |= (1 << num);
	}

	void reset(size_t pos)
	{
		size_t index = pos >> 5;
		size_t num = pos % 32;
		_bits[index] &= ~(1 << num);
	}

	bool test(size_t pos)
	{
		size_t index = pos >> 5;
		size_t num = pos % 32;
		bool res = (_bits[index] & (1 << num)) > 0 ? true : false;
		return res;
	}

	size_t count()
	{
		size_t bit_count = 0;
		for (size_t i = 0; i < _bits.size(); i++)
		{
			int temp = _bits[i];
			while (temp>0)
			{
				temp &= temp - 1;
				bit_count++;
			}
		}
		return bit_count;
	}
private:
	std::vector<int> _bits;
};

//test.cpp
//#include <iostream>
//#include <bitset>
//#include"my_bitset.h"
//using namespace std;
//
//void My_bit_set_test()
//{
//	//观察自己写的位图 和 官方给出的位图的现象，是否相同。
//	my_bitset<101> t;
//	//bitset<101> t;
//
//	t.set(0);
//	t.set(10);
//	t.set(20);
//	t.set(30);
//	t.set(40);
//	t.set(50);
//	t.set(60);
//	t.set(70);
//	t.set(80);
//	t.set(90);
//	t.set(100);
//	cout << "size:" << t.size() << endl;
//	cout << t.count() << "个bit为1" << endl;
//	for (int i = 0; i <= 100; i += 10)
//	{
//		cout << "位置" << i << " :" << t.test(i) << endl;
//		t.reset(i);
//	}
//	cout << t.count() << "个bit为1" << endl;
//	for (int i = 0; i <= 100; i += 10)
//	{
//		cout << "位置" << i << " :" << t.test(i) << endl;
//	}
//}
//
//int main()
//{
//	My_bit_set_test();
//	return 0;
//}