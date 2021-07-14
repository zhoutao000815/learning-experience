#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <array>
using namespace std;

//int main()
//{
//	// 内置类型变量
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//	// 数组
//	int arr1[5] {1, 2, 3, 4, 5};
//	int arr2[]{1, 2, 3, 4, 5};
//
//}
//
//class A
//{
//public:
//	//explicit A(int a)
//	A(int a) // 单参数构造函数
//		:_a(a)
//	{}
//private:
//	int _a;
//};

class Point
{
public:
	//explicit Point(int x = 0, int y = 0)  // 多参数
	Point(int x = 0, int y = 0)  // 多参数
		: _x(x)
		, _y(y)
	{

	}


private:
	int _x;
	int _y;
};

#include <initializer_list>

template<class T>
class Vector {
public:
	// ...    
	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0)
	{
	_array = new T[_capacity];
	for (auto e : l)
	_array[_size++] = e;
	}

	Vector<T>& operator=(initializer_list<T> l) {
		delete[] _array;
		size_t i = 0;
		for (auto e : l)
			_array[i++] = e;
		return *this;
	}
	// ...
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

//int main()
//{
//	// C++98
//	A aa1(1);
//	A aa2 = 2; // 隐式类型转换（相近类型）
//	string s = "bit";
//	vector<string> v;
//	v.push_back("bit");
//
//	// C++11
//	Point p1 = { 1, 2 }; // 隐式类型转换（相近类型）
//
//	vector<int> vi = { 1, 2, 3, 4, 5, 6 };
//
//	Vector<int> VI = { 1, 2, 3, 4, 5 };
//
//
//	// initializer_list<pair<string, int>>
//	map<string, int> countMap = { { "sort", 1 }, { "map", 3 }, { "set", 4 } };
//
//	return 0;
//}

// auto 不能做参数类型，不能做返回值类型
// auto 需要编译时推到类型，语法层概念
// 底层实现角度，编译成指令函数需要先建立栈帧
//void func(auto it)
//{
//
//}

// 了解一下
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "banana", "香蕉" } };
//
//	// 使用迭代器遍历容器, 迭代器类型太繁琐
//	//  类的内嵌类型
//	// auto 推导你双刃剑语法，如果不知道返回对象的类型，会降低可读性
//	//std::map<std::string, std::string>::iterator it = m.begin();
//	auto it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		++it;
//	}
//
//	// 获取对象类型  （了解一下）
//	cout << typeid(it).name() << endl;
//	// dynamic_cast  后面讲
//
//	// 定义一个跟it一样类型的对象
//	// auto是编译时，通过初始化对象推导
//	// decltype是编译器时通过对象推导
//	auto copy1 = it;
//	decltype(it) copy2;
//	
//	return 0;
//}

// 
// 比较常用 范围for，底层原理:替换成迭代器
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	for (auto e : v)
//	{
//		cout << e << endl;
//	}
//
//	int a[] = { 1, 2, 3, 4, 5 };
//	for (auto e : a)
//	{
//		cout << e << endl;
//	}
//
//	return 0;
//}


// final与override  了解一下

//  默认成员函数控制  了解一下
// defalut  让编译器生成  -》 一般针对的构造函数
// delete   不编译器生成  -》 一般针对的是拷贝构造，赋值运算符重载。
// C++98 防拷贝/防复制技术 -》 只声明不实现(防止编译生成默认的) + 声明成私有（防止别人在类外定义）
// C++11 提供delete，让防拷贝实现更简单更容易理解
class A
{
public:
	explicit A(int a) 
		: _a(a)
	{}
	// 显式缺省构造函数，由编译器生成
	A() = default;

	// 在类中声明，在类外定义时让编译器生成默认赋值运算符重载
	//A& operator=(const A& a) = default;
private:
	int _a = 0; // C++11 给成员变量给缺省值
};

//int main()
//{
//	//array<int, 100> a1;
//	//array<int, 200> a2;
//
//	//cout << a1.size() << endl;
//	//cout << a2.size() << endl;
//	//
//	//// vector用resize也能达到上面的作用，
//	//// array其实没啥用
//	//vector<int> v;
//	//v.resize(100, 1);
//
//	A  a1(1);
//	A  a2;
//
//	a1 = a2;
//
//	return 0;
//}

// 
//int main()
//{
//	int val = 10;
//	int& lr1 = val;  
//	// 左值引用一般是给左值取别名
//
//	const int& lr2 = int(1);
//	// const 左值引用也可以给右值取别名
//
//	int&& rr1 = int(1);
//	// 右值引用一般是给右值取别名
//
//	// ?why 后面讲了在回来看
//	int&& rr2 = move(val);
//	// 右值引用不能直接给左取别名，但是可以给move(左值)
//
//	return 0;
//}

class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// 拷贝构造 -- 深拷贝
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}

	// 移动构造 -- 浅拷贝
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		std::swap(_str, s._str);
	}

	// 拷贝赋值 -- 深拷贝
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	// 移动赋值 -- 浅拷贝
	//  s2 = String("xxxx");
	String& operator=(String&& s)
	{
		cout << "String& operator=(String&& s)" << endl;
		std::swap(_str, s._str);
		return *this;
	}

	// s1 += s2
	String& operator+=(const String& s)
	{
		 //... 

		return *this;
	}

	// s1 + s2
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);

		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

//结论：传值返回，会多一次拷贝（这次拷贝有可能会被优化）
//      传左值引用返回，会少一次拷贝
//  左值引用的作用：
// <1>: 函数引用传参  --  减少拷贝 +  输出型参数
// <2>: 函数引用传返回值 -- 减少拷贝
// 核心作用：提高效率+提高程序可读性（不需要用复杂指针）

// 左值引用解决效率问题的盲区：有些函数不能传引用返回(返回对象是局部对象的函数)
// 右值引用来解决上面的问题，如何解决？ 
// -- 借助移动构造和移动赋值，区分出传值返回时，返回的是右值(将亡值)
//    直接移动构造和移动赋值，浅拷贝，转移将亡值的资源，较少了深拷贝，提高了效率

// 涉及resize / operator[]
class Solution {
public:
	// 核心思想：找出杨辉三角的规律，发现每一行头尾都是1，中间第[j]个数等于上一行[j-1]+[j]
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		// 先开辟杨辉三角的空间
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);

			// 每一行的第一个和最后一个都是1
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}

		return vv;
	}
};

//int main()
//{
//	String s1("hello");
//	String s2("world");
//
//	//String s3 = s1 + s2; 
//	//cout << endl;
//	//// 编译优化，本来应该是两次拷贝构造，编译器可能优化成一次
//	//String s4 = s1 += s2;
//
//	//////////////////////////////////////////////////////
//	String s3;
//	s3 = s1 + s2;
//
//	cout << endl;
//
//	String s4;
//	s4 = s1 += s4;
//
//	// 类似这样的场景 有了右值引用的移动构造和移动赋值，效率你能得到极大的提高
//	vector<vector<int>> ret1 = Solution().generate(5);
//	vector<vector<int>> ret2;
//	ret2 = Solution().generate(5);
//
//	return 0;
//}

//  右值引用做参数
int main()
{
	list<String> lt;
	lt.push_back("hello11111111111111111111111111"); // void push_back(_Ty&& _Val)

	String s1("hello1111111111111111111111111");
	lt.push_back(s1);    // void push_back(const _Ty& _Val)

	String s2("hello1111111111111111111111111");
	lt.push_back(move(s2));    // void push_back(const _Ty&& _Val)


	return 0;
}