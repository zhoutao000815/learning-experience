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
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	Student stu;
//	
//	// 1.�����������Ը�ֵ���������/ָ��/����
//	Person per = stu;
//	Person* pp = &stu;
//	Person& rp = stu;
//
//	//2.��������ܸ�ֵ�����������/����
//	stu = per;
//	stu = (Student)per;  //����ǿ������ת��Ҳ����
//	Student& st= per;
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &stu;
//	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//	pp = &per;
//
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
//		cout << "person����Print����" << endl;
//	}
//protected:
//	string _name = "��ȫ"; // ����
//	int _num = 111; // ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "studet����Print����" << endl;
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	// �̳������ĸ��ಿ�ֵĳ�Ա��Ҫʹ�ø���Ĺ��캯��ȥ��ʼ��
//	// �����Լ���ʾ��ȥ��ʼ��
//	//Student(const char* name = "С��", int num = 1)
//	//	:_name(name)
//	//	, _num(num)
//	//{}
//
//	Student(const char* name = "С��", int num = 1)
//		:Person(name)
//		,_num(num)
//	{}
//
//	//��ʹ��д��������Ҳ���Զ����ɣ����ҵ��û���Ŀ�������͸�ֵ���������
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
//	// �����Ի�㣺
//	// 1����������������͸�������������������� ,��������������������ֻᱻͳһ�����destructor�����Ƕ�̬�Ŀ�!
//	// 2���Լ���ʾ���ã����ڸ��������������⣬������ջ�Ĺ���
//	~Student()
//	{
//		Person::~Person();
//	}
//
//protected:
//	int _num; //ѧ��
//};
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//
//	Student s3("��ȫ", 20);
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
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}

int main()
{
	TestPerson();
	return 0;
}