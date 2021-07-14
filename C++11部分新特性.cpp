#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <array>
using namespace std;

//int main()
//{
//	// �������ͱ���
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//	// ����
//	int arr1[5] {1, 2, 3, 4, 5};
//	int arr2[]{1, 2, 3, 4, 5};
//
//}
//
//class A
//{
//public:
//	//explicit A(int a)
//	A(int a) // ���������캯��
//		:_a(a)
//	{}
//private:
//	int _a;
//};

class Point
{
public:
	//explicit Point(int x = 0, int y = 0)  // �����
	Point(int x = 0, int y = 0)  // �����
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
//	A aa2 = 2; // ��ʽ����ת����������ͣ�
//	string s = "bit";
//	vector<string> v;
//	v.push_back("bit");
//
//	// C++11
//	Point p1 = { 1, 2 }; // ��ʽ����ת����������ͣ�
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

// auto �������������ͣ�����������ֵ����
// auto ��Ҫ����ʱ�Ƶ����ͣ��﷨�����
// �ײ�ʵ�ֽǶȣ������ָ�����Ҫ�Ƚ���ջ֡
//void func(auto it)
//{
//
//}

// �˽�һ��
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "banana", "�㽶" } };
//
//	// ʹ�õ�������������, ����������̫����
//	//  �����Ƕ����
//	// auto �Ƶ���˫�н��﷨�������֪�����ض�������ͣ��ή�Ϳɶ���
//	//std::map<std::string, std::string>::iterator it = m.begin();
//	auto it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		++it;
//	}
//
//	// ��ȡ��������  ���˽�һ�£�
//	cout << typeid(it).name() << endl;
//	// dynamic_cast  ���潲
//
//	// ����һ����itһ�����͵Ķ���
//	// auto�Ǳ���ʱ��ͨ����ʼ�������Ƶ�
//	// decltype�Ǳ�����ʱͨ�������Ƶ�
//	auto copy1 = it;
//	decltype(it) copy2;
//	
//	return 0;
//}

// 
// �Ƚϳ��� ��Χfor���ײ�ԭ��:�滻�ɵ�����
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


// final��override  �˽�һ��

//  Ĭ�ϳ�Ա��������  �˽�һ��
// defalut  �ñ���������  -�� һ����ԵĹ��캯��
// delete   ������������  -�� һ����Ե��ǿ������죬��ֵ��������ء�
// C++98 ������/�����Ƽ��� -�� ֻ������ʵ��(��ֹ��������Ĭ�ϵ�) + ������˽�У���ֹ���������ⶨ�壩
// C++11 �ṩdelete���÷�����ʵ�ָ��򵥸��������
class A
{
public:
	explicit A(int a) 
		: _a(a)
	{}
	// ��ʽȱʡ���캯�����ɱ���������
	A() = default;

	// �����������������ⶨ��ʱ�ñ���������Ĭ�ϸ�ֵ���������
	//A& operator=(const A& a) = default;
private:
	int _a = 0; // C++11 ����Ա������ȱʡֵ
};

//int main()
//{
//	//array<int, 100> a1;
//	//array<int, 200> a2;
//
//	//cout << a1.size() << endl;
//	//cout << a2.size() << endl;
//	//
//	//// vector��resizeҲ�ܴﵽ��������ã�
//	//// array��ʵûɶ��
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
//	// ��ֵ����һ���Ǹ���ֵȡ����
//
//	const int& lr2 = int(1);
//	// const ��ֵ����Ҳ���Ը���ֵȡ����
//
//	int&& rr1 = int(1);
//	// ��ֵ����һ���Ǹ���ֵȡ����
//
//	// ?why ���潲���ڻ�����
//	int&& rr2 = move(val);
//	// ��ֵ���ò���ֱ�Ӹ���ȡ���������ǿ��Ը�move(��ֵ)
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

	// �������� -- ���
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}

	// �ƶ����� -- ǳ����
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		std::swap(_str, s._str);
	}

	// ������ֵ -- ���
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

	// �ƶ���ֵ -- ǳ����
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

//���ۣ���ֵ���أ����һ�ο�������ο����п��ܻᱻ�Ż���
//      ����ֵ���÷��أ�����һ�ο���
//  ��ֵ���õ����ã�
// <1>: �������ô���  --  ���ٿ��� +  ����Ͳ���
// <2>: �������ô�����ֵ -- ���ٿ���
// �������ã����Ч��+��߳���ɶ��ԣ�����Ҫ�ø���ָ�룩

// ��ֵ���ý��Ч�������ä������Щ�������ܴ����÷���(���ض����Ǿֲ�����ĺ���)
// ��ֵ�����������������⣬��ν���� 
// -- �����ƶ�������ƶ���ֵ�����ֳ���ֵ����ʱ�����ص�����ֵ(����ֵ)
//    ֱ���ƶ�������ƶ���ֵ��ǳ������ת�ƽ���ֵ����Դ������������������Ч��

// �漰resize / operator[]
class Solution {
public:
	// ����˼�룺�ҳ�������ǵĹ��ɣ�����ÿһ��ͷβ����1���м��[j]����������һ��[j-1]+[j]
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		// �ȿ���������ǵĿռ�
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);

			// ÿһ�еĵ�һ�������һ������1
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
//	//// �����Ż�������Ӧ�������ο������죬�����������Ż���һ��
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
//	// ���������ĳ��� ������ֵ���õ��ƶ�������ƶ���ֵ��Ч�����ܵõ���������
//	vector<vector<int>> ret1 = Solution().generate(5);
//	vector<vector<int>> ret2;
//	ret2 = Solution().generate(5);
//
//	return 0;
//}

//  ��ֵ����������
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