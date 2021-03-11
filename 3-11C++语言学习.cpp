#include<iostream>
using namespace std;
//
////class Date
////{
////public:
////	Date(int year = 0, int month = 1, int day = 1)
////		:_year(year)
////		, _month(month)
////		, _day(day)
////	{}
////
////	~Date()
////	{}
////
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////
////int main()
////{
////	Date* p1 = (Date*)malloc(sizeof(Date));
////	free(p1);
////
////	//
////	//Date* p2 = new Date;
////	Date* p2 = new Date(2021, 3, 11);
////	delete p2;
////
////	//Date* p3 = new Date[10](2021, 3, 11);
////	// ֻ�ܵ���Ĭ�ϵĹ��캯��
////	Date* p3 = new Date[10];
////	delete[] p3;
////
////	// ����Ҳ�ǵ���Ĭ�Ϲ��캯��������һ�㲻����Ӻ����()
////	Date* p4 = new Date();
////	delete p4;
////
////	Date d1(); // ����û�ж���d1��������������
////	Date d2;
////
////	return 0;
////}
//
//struct ListNode
//{
//	//struct ListNode* _next;
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//};
//
//ListNode* BuyListNode(int val)
//{
//	// ���ռ�+��ʼ��
//	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//	node->_next = nullptr;
//	node->_prev = nullptr;
//	node->_val = val;
//
//	return node;
//}
//
////int main()
////{
////	//ListNode* newnod_c = BuyListNode(1);
////	//ListNode* newnod_cpp = new ListNode(1);
////
////
////	return 0;
////}
//
//// operator new��operator delete������C++����/�ͷ��ڴ�Ŀ⺯��
//// ����new/delete�����أ� operator new���Ǻ���������������һ������
//// �÷���malloc/free��һ����
//
//// operator new��malloc�������ǣ�
//// C���Դ������ķ�ʽһ���Ƿ��ش����룬����mallocʧ�ܷ���0
//// C++�������ķ�ʽһ�����쳣������operator new��newʧ�����쳣
//
//int main()
//{
//	ListNode* node = (ListNode*)operator new(sizeof(ListNode));
//	operator delete(node);
//
//	void* p1 = malloc(0x7fffffff);
//
//	try
//	{
//		//void* p2 = operator new(0x7fffffff);
//		char* p3 = new char[0x7fffffff];
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	ListNode* newnode = new ListNode(1);
//
//	return 0;
//}

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _val;

	/*void* operator new(size_t n)
	{
	void* p = nullptr;
	p = allocator<ListNode>().allocate(1);
	cout << "memory pool allocate" << endl;
	return p;
	}

	void operator delete(void* p)
	{
	allocator<ListNode>().deallocate((ListNode*)p, 1);
	cout << "memory pool deallocate" << endl;

	}*/

	ListNode(int val)
		:_next(nullptr)
		, _prev(nullptr)
		, _val(val)
	{
		cout << "ListNode(int val)" << endl;
	}

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode(0);
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}

		delete _head;
		_head = nullptr;
	}

private:
	ListNode* _head;
};

//int main()
//{
//	//List l;
//
//	ListNode* node = new ListNode(1);
//	//ListNode* array = new ListNode[10];
//	// ��������޸�ListNode,�ܷ���������ʽ����������ListNode�����أ�
//	// 
//
//	// ģ��new �� delete���÷�������ʵ����һ���ǲ�����ô�õ�
//	// һ��ֻ��һ�����ʹ�ö�λnew���ռ��Ѿ�������(������ڴ������)����Ҫ���ù��캯����ʼ��
//	int n = 10;
//	ListNode* array = (ListNode*)operator new(sizeof(ListNode) * n);
//	// ��ʾ���ù��캯��ȥ��ʼ��һ�����еĿռ� -- ��λnew(replacenew)
//	for (int i = 0; i < n; ++i)
//	{
//		new(array + i)ListNode(0);
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		(array + i)->~ListNode();
//	}
//	operator delete(array);
//
//	return 0;
//}


//int main()
//{
//	// 1G = 1024M = 1024*1024KB = 1024*1024*1024Byte
//	void* p1 = malloc(1024u * 1024 * 1024*4);
//
//	return 0;
//}

// ģ��  -- ����ģ�� + ��ģ��
// ���ͱ��
//template<typename T>

//template<class T>
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	//int a = 1, b = 2;
//	//double d1 = 2.2, d2 = 4.44;
//	//Swap(a, b);
//	//Swap(d1, d2);
//
//	//char ch1 = 'A', ch2 = 'B';
//	//Swap(ch1, ch2);
//
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, (int)d2);
//
//	// ��ʾʵ��������������
//	Add<int>(a1, d2);
//
//	return 0;
//}


// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}

// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}

//int main()
//{
//	Add(1, 2);       // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2);  // ���ñ������ػ���Add�汾
//	Add(1.1, 2.2);
//
//	return 0;
//}

// ��ģ��
// ��ͨ��,������������
// ��ģ�壬���ͣ�Stack<T>
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_a(new T[4])
		, _top(0)
		, _capacity(4)
	{}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

	// ����
	void Push(const T& x);

private:
	T* _a;
	int _top;
	int _capacity;
};

// ��ģ���Ա��������
template<class T>
void Stack<T>::Push(const T& x)
{
	//..
}

int main()
{
	// 
	Stack<int> st1;		// int
	Stack<double> st2;  // double

	st1.Push(1);


	return 0;
}