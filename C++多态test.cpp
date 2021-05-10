#include <iostream>
#include <string>

using namespace std;

//class Person {
//public:
//	// 各种开后门特例，本质都是为了析构函数构成重写
//	// 因为如果不构成重写，特殊情况下，可能会存在内存泄露
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	//Person p;
//	//Student s;
//	Person* p1 = new Person;
//	delete p1;
//
//	Person* p2 = new Student;
//	delete p2;
//
//	return 0;
//}


// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//	
//
//private:
//	int _b = 1;
//};
//
//Base b;
//int main()
//{
//	cout << sizeof(Base) << endl;
//
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	return 0;
//}




//面试题1：以下程序输出什么?
//class A
//{
//public:
//	A() :m_iVal(0){ test(); }
//	virtual void func() { std::cout << m_iVal << ' '; }
//	void test(){ func(); }
//public:
//	int m_iVal;
//};
//
//
//class B : public A
//{
//public:
//	B(){ test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << ' ';
//	}
//};
//
//
//int main(int argc, char* argv[])
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}
//
//面试题2：以下程序输出什么?
class A
{
public:
	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
	virtual void test(){ func(); }
};
class B : public A
{
public:
	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}

//
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int b = 1;
//};
//
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int d = 2;
//};
//
//typedef void(*VFUNC)();  //将函数指针类型，命名为VFUNC
//
////int* p1;
////void(*p2)();
////int (*p)[10]
//
//void PrintVFT(VFUNC* vftable)
//{
//	printf("虚表指针：%p\n", vftable);
//	for (int i = 0; vftable[i] != nullptr; ++i)
//	{
//		printf("vftale[%d]:%p->", i, vftable[i]);
//		VFUNC f = vftable[i];
//		f();
//		//(*f)();
//	}
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	PrintVFT((VFUNC*)(*((int*)&d)));
//	cout << endl << endl;
//
//	PrintVFT((VFUNC*)(*((int*)&b)));
//
//
//	return 0;
//}