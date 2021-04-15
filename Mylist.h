#pragma once
#include<assert.h>
namespace zt
{
	//list的节点类
	template <class T>
	struct ListNode
	{
		ListNode(const T& value = T())  //构造匿名对象去初始化缺省参数，实现传不传参数均可的构造函数

		//初始化列表自动按顺序填充，
		: Date( value)
		, prev(nullptr)
		, next(nullptr)
		{ }

	public:
		T Date;
		ListNode<T>* prev;
		ListNode<T>* next;
	};

	//list的迭代器类模板
	//为什么要设计成模板呢?
	//=======================================================================================
	//对于普通类和const类，是否修改类成员，有 普通迭代器 和 const迭代器 的两种需求。
	//而调用者实现能否修改，由调用者解引用迭代器后获得的数据有没有被const修饰所决定的。
	//而直接用下面这种写法的话，由于解引用迭代器后返回值为T&和T*，是可以修改的，不可修改的返回值为const T& ,const T*。
	//而返回值是不能作为函数重载的区别依据的，只能重新定义一个const_ListIterator类，在这两个运算符重载的返回值上添加const。
	//因为两个成员函数的返回值多一个const，就要重新定义一个类是没必要的。大神就设计了一个迭代器模板，根据T&和T*设计出此模板，实现了iterator和const_iterator

	/*struct ListIterator
	{
		typedef ListNode<T>* PNode;
		ListIterator(PNode pNode = nullptr)
		{
			_PNode = pNode;
		}

		T& operator*() const
		{
			return _PNode->Date;
		}
		T* operator->() const
		{
			return &(_PNode->Date);
		}
	};*/

	//ListIterator<T, T&, T*>iterator;
	//ListIterator<T, const T&, const T*> const_iterator;
	template < class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator <T, Ref, Ptr> Self;
		ListIterator(PNode pNode = nullptr)
		{
			_PNode = pNode;
		}

		//拷贝构造和赋值用编译器默认即可，此迭代器类不涉及堆资源管理。我们需要的就是浅拷贝。
		//析构也不需要，我们没有new新节点，只是一个节点指针。


		//迭代器的使用形式和指针相同，
		//1. 指针可以解引用，迭代器的类中必须重载operator*()
		Ref operator*() const
		{
			return _PNode->Date;
		}

		//2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
		//当数据T是一个结构体时，此时的迭代器，就要充当结构体指针的角色，结构体指针是可以使用->的，所以要重载->。
		//而返回结构体指针T*以后，it.operator->()->（it->->）可读性太差，编译器优化省略了一个->
		Ptr operator->() const
		{
			return &(_PNode->Date);
		}

		Self& operator++()
		{
			_PNode = _PNode->next;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(_PNode);
			_PNode = _PNode->next;
			return temp;
		}

		Self& operator--()
		{
			_PNode = _PNode->prev;
			return *this;
		}
		Self& operator--(int)
		{
			Self temp(_PNode);
			_PNode = _PNode->next;
			return temp;
		}
		bool operator==(const Self& l) const
		{
			return _PNode == l._PNode;
		}
		bool operator!=(const Self& l) const
		{
			return _PNode != l._PNode;
		}

		PNode _PNode;
	};

	//list类
	template < class T>
	class  Mylist
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

	public:

		Mylist()
		{
			Creatphead();
		}

		Mylist(int n, const T& value = T())
		{
			Creatphead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}

		template <class Iterator>
		Mylist(Iterator first, Iterator last)
		{
			Creatphead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		Mylist(const Mylist<T>& l)
		{
			Creatphead();
			// 用l中的元素构造临时的temp,然后与当前对象交换
			Mylist<T> temp(l.cbegin(), l.cend());
			this->swap(temp);
		}
		Mylist<T>& operator=( Mylist<T> l)
		{
			this->swap(l);
			return *this;
		}
		~Mylist()
		{
			clear();
			delete _phead;
			_phead = nullptr;
		}
		///////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin()
		{
			//完全匹配写法
			//iterator it(_phead->next);
			//return it;

			//匿名对象
			//return iterator(_phead->next);

			//隐式类型转换
			return _phead->next;
		}
		iterator end()
		{
			return _phead;
		}
		const_iterator cbegin() const  
		{
			return _phead->next;
		}
		const_iterator cend() const
		{
			return _phead;
		}

		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t size()const
		{
			size_t len = 0;
			const_iterator begin = cbegin();
			while (begin != cend())
			{
				len++;
				begin++;
			}
			return len;
		}
		bool empty()const
		{
			return _phead == _phead->next;
		}
		////////////////////////////////////////////////////////////
		// List Access
		T& front()
		{
			assert(!empty());
			return _phead->next->Date;
		}
		const T& front()const
		{
			assert(!empty());
			return _phead->next->Date;
		}
		T& back()
		{
			assert(!empty());
			return _phead->prev->Date;
		}
		const T& back()const
		{
			assert(!empty());
			return _phead->prev->Date;
		}
		////////////////////////////////////////////////////////////
		// List Modify
		void push_back(const T& val)
		{
			/*PNode newNode = new Node(val);
			PNode tail = _phead->prev;

			tail->next = newNode;
			newNode->next = _phead;
			newNode->prev = tail;
			_phead->prev = newNode;*/

			insert(end(), val);
		}
		void pop_back(){ erase(--end()); }
		void push_front(const T& val){ insert(begin(), val); }
		void pop_front(){ erase(begin()); }
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			PNode newNode = new Node(val); 
			//PNode cur = pos;
			PNode cur = pos._PNode;
			PNode curprev = cur->prev;

			newNode->prev = curprev;
			newNode->next = cur;
			cur->prev = newNode;
			curprev->next = newNode;

			//return iterator(newNode);
			return newNode;  //隐式类型转换
		}

		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			PNode cur = pos._PNode;
			PNode next = cur->next;
			PNode prev = cur->prev;

			prev->next = next;
			next->prev = prev;
			delete cur;

			//return iterator(next);
			return next;
		}

		void clear()
		{
			iterator begin = this->begin();
			while (begin != end())
			{
				erase(begin++);
				//begin = erase(begin);
			}
		}
		void swap(Mylist<T>& l) 
		{
			std::swap(_phead, l._phead);
		}

	private:
		void Creatphead()
		{
			_phead = new Node;
			_phead->next = _phead;
			_phead->prev = _phead;
		}
	private:
		PNode _phead;
	};
}
