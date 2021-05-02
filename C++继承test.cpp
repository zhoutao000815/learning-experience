#include <iostream>
#include<string>
using namespace std;

//class A
//{
//public:
//	A(int a1=9,int a2=99,int a3=999)
//	{
//		_a1 = a1;
//		_a2 = a2;
//		_a3 = a3;
//	}
//public:
//	int _a1;
//protected:
//	int _a2;
//private:
//	int _a3;
//};
//
//class B :protected A
//{
//public:
//	B()
//	{
//		cout << _a1 << endl;
//		cout << _a2 << endl;
//		//cout << _a3 << endl;
//	}
//
//private:
//
//};
//class C :public B
//{
//public:
//	C()
//	{
//		cout << _a1 << endl;
//		cout << _a2 << endl;
//		//cout << _a3 << endl;
//	}
//
//private:
//
//};
//int main()
//{
//	A at;
//	B bt;
//	C ct;
//	ct._a1;
//	return 0;
//}



//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student stu;
//	
//	// 1.派生类对象可以赋值给基类对象/指针/引用
//	Person per = stu;
//	Person* pp = &stu;
//	Person& rp = stu;
//
//	//2.基类对象不能赋值给派生类对象/引用
//	stu = per;
//	stu = (Student)per;  //即便强制类型转换也不行
//	Student& st= per;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &stu;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	pp = &per;
//
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "person：：Print（）" << endl;
//	}
//protected:
//	string _name = "周全"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "studet：：Print（）" << endl;
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Person::Print();
//	s1.Print();
//};
//
//int main()
//{
//	Test();
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name="xiaom")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	// 继承下来的父类部分的成员，要使用父类的构造函数去初始化
//	// 不能自己显示的去初始化
//	//Student(const char* name = "小明", int num = 1)
//	//	:_name(name)
//	//	, _num(num)
//	//{}
//
//	Student(const char* name = "小明", int num = 1)
//		:Person(name)
//		,_num(num)
//	{}
//
//	//即使不写，编译器也会自动生成，并且调用基类的拷贝构造和赋值运算符重载
//	//Student(const Student& s)
//	//	:Person(s)
//	//	, _num(s._num)
//	//{}
//
//	//Student& operator=(const Student& s)
//	//{
//	//	if (this != &s)
//	//	{
//	//		Person::operator=(s);
//	//		_num = s._num;
//	//	}
//
//	//	return *this;
//	//}
//
//	// 两个迷惑点：
//	// 1、子类的析构函数和父类的析构函数构成隐藏 ,所有类的析构函数，名字会被统一处理成destructor，又是多态的坑!
//	// 2、自己显示调用，存在父类先析构的问题，不符合栈的规则
//	~Student()
//	{
//		Person::~Person();
//	}
//
//protected:
//	int _num; //学号
//};
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//
//	Student s3("周全", 20);
//	s1 = s3;
//
//
//	return 0;
//}

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}

int main()
{
	TestPerson();
	return 0;
}