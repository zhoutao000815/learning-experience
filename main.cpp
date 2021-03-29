#include"MyString.h"
using namespace zt;
int main()
{
	//构造、拷贝构造、'='、析构。测试
	/*zt::string s1("hello");
	zt::string s2(s1);
	zt::string s3 = "world!";
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;*/

	//迭代器测试
	//zt::string s1("hello");
	//zt::string::iterator begin = s1.begin();
	//zt::string::iterator end = s1.end();
	//while (begin != end)
	//{
	//	cout << begin << ' ';
	//	begin++;
	//}

	//capacity模块测试
	/*zt::string s1 = "C++ is so easy!";
	size_t size = s1.size();
	bool IsEmpty = s1.empty();
	s1.resize(size + 2, '!');
	s1.reserve(s1.capacity()*2);
	cout << size << endl << IsEmpty << endl << s1.size() << endl << s1.capacity() << endl;*/

	// modify 模块测试
	//zt::string s1 = "C++ is so easy?";
	//zt::string s2 = "Linux is difficult!";
	//cout << s1.c_str() << endl;
	//cout << s2.c_str() << endl;
	//s1.swap(s2);
	//cout << s1.c_str() << endl;
	//cout << s2.c_str() << endl;
	//s1 += "!!";
	//s2 += "??";
	//cout << s1.c_str() << endl;
	//cout << s2.c_str() << endl;
	//s1.clear();
	//s2 += 'Y';
	//cout << s1.c_str() << endl;
	//cout << s2.c_str() << endl;

	// []重载测试
	//zt::string s1("hello");
	//cout << s1.c_str() << endl;
	//s1[0] = 'H';
	//cout << s1.c_str() << endl;

	//relational operators  测试
	//zt::string s1("abcde");
	//zt::string s2("abcde123");
	//zt::string s3("ABCDE");
	//zt::string s4("ABCDE");
	//cout << (s1 > s2) << endl << (s1 >= s2) << endl << (s3 == s4) << endl << (s3 <= s4) << endl;

	//find、insert、earse以及输入>>输出<<重载测试测试
	zt::string s1("12345");
	std::cout << s1 << std::endl;;
	s1.insert(5, '6');
	std::cout << s1 << std::endl;
	s1.insert(4, "hello");
	std::cout << s1 << std::endl;
	std::cout << s1.find("hello") << std::endl;
	std::cout << s1.find("o") << std::endl;
	std::cout << s1.erase(6,4) << std::endl;
	std::cout << s1.erase(6) << std::endl;

	return 0;
}