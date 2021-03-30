#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string s = "123456789";    
	//string::iterator it = s.begin();
	//s.erase(0,5);                  //删掉前五个数据
	//while (it != s.end())          //挪动数据了，但是没有失效
	//{
	//	cout << *it;
	//	++it;
	//}

	//string s = "hello world!";
	//string::iterator it = s.begin();
	//string::iterator end = s.end();     //迭代器失效
	//s.erase(0,3);                       //删除数据导致数据挪动，引起迭代器指向的空间变成了非法空间
	//while (it != end)                   //崩溃位置，因为end指向了一块非法内存
	//{
	//	cout << *it ;
	//	++it;
	//}

	//string s1 = "hello world";
	//string s2 = "change world";
	//string::iterator it = s1.begin();          //迭代器失效
	//swap(s1, s2);                              //交换数据导致数据挪动
	//while (it != s1.end())                     //崩溃位置
	//{
	//	cout << *it;
	//}
	//cout << endl;



	//string::reverse_iterator rit = s.rbegin();
	//while (rit != s.rend())             //迭代器类似于用指针指向的空间，控制循环
	//	cout << *rit << endl;


		string str = "Hello Bit.";
		string::iterator it = str.begin();
		while (it != str.end())
		{
			if (*it != ' ')
			{
				cout << *it;
			}
			else
			{
				str.erase(it);
				//cout << *it;
			}
			it++;
		}
		//输出Helloit，

	return 0;
}
