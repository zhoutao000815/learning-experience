#include"stackAndQueue.h"
#include<iostream>
#include<string>
#include<vector>
using namespace zt;
void stackTest()
{
	stack <int> s1;
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	while (!s1.empty())
	{
		std::cout << s1.top() << " ";
		s1.pop();
	}
	std::cout << "size:"<<s1.size() << std::endl;
	
	stack <int,std::vector<int>> s2;
	s2.push(9);
	std::cout << s2.top() << std::endl;
}

void QueueTest()
{
	queue <std::string> q1;

	q1.push("hello");
	q1.push("world");
	while (!q1.empty())
	{
		std::cout << q1.front() << " ";
		q1.pop();
	}
	std::cout <<std::endl;
	std::cout << "size:" << q1.size() << std::endl;
}
int main()
{
	stackTest();
	QueueTest();
	return 0;
}