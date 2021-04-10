#include "MyVector.h"
#include<algorithm>
#include<string>

using namespace zt;

void test1()  //(constructor)模块测试
{
	MyVector<int> v;

	MyVector<std::string> v1(5);
	MyVector<std::string> v2(5,"hello");

	std::string s = "hello world!";
	MyVector<char> v4(s.begin(),s.end());

	MyVector<char> v5(v4);

	MyVector<std::string> v6;
	v6 = v2;

	v.Vprintf();
	v1.Vprintf();
	v2.Vprintf();
	v4.Vprintf();
	v5.Vprintf();
	v6.Vprintf();
}

void test2()	//capacity 模块测试
{
	/*const MyVector<int> v1(2, 0);
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	std::cout << v1.empty() << std::endl;*/

	MyVector<int> v2(1, 2);
	std::cout << v2.capacity() << std::endl;
	v2.reserve(3);
	std::cout << v2.capacity() << std::endl;
	v2.resize(4, 0);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v2.Vprintf();
	v2.resize(2);
	v2.Vprintf();
	std::cout << v2.capacity() << std::endl;
}

void test3()	//Modifiers 模块测试
{
	//内置类型
	int tmp[] = { 1, 2, 3, 4 };
	MyVector<int> v1(tmp, tmp + 4);
	v1.insert(v1.begin()+2, 20);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	MyVector<int>::iterator pos = std::find(v1.begin(), v1.end(), 2);
	v1.erase(pos);
	v1.Vprintf();
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;

	//自定义类型
	//std::string s1 = "zt";
	//MyVector<std::string> v2(4, "hello");
	//v2.insert(v2.begin()+4, s1);
	//v2.push_back("world!");
	//v2.push_back("world!!!");
	//v2.push_back("world!");
	//v2.push_back("world!");
	//v2.erase(v2.begin() + 4);
	//v2.pop_back();
	//v2.pop_back();
	//v2.Vprintf();
	
	//std::cout << v2[6] << std::endl;
	//std::cout << v2[6][0] << std::endl;

	//std::cout << v2.size() << std::endl;
	//std::cout << v2.capacity() << std::endl;
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}