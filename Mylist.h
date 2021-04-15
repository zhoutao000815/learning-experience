#pragma once
#include<assert.h>
namespace zt
{
	//list�Ľڵ���
	template <class T>
	struct ListNode
	{
		ListNode(const T& value = T())  //������������ȥ��ʼ��ȱʡ������ʵ�ִ������������ɵĹ��캯��

		//��ʼ���б��Զ���˳����䣬
		: Date( value)
		, prev(nullptr)
		, next(nullptr)
		{ }

	public:
		T Date;
		ListNode<T>* prev;
		ListNode<T>* next;
	};

	//list�ĵ�������ģ��
	//ΪʲôҪ��Ƴ�ģ����?
	//=======================================================================================
	//������ͨ���const�࣬�Ƿ��޸����Ա���� ��ͨ������ �� const������ ����������
	//��������ʵ���ܷ��޸ģ��ɵ����߽����õ��������õ�������û�б�const�����������ġ�
	//��ֱ������������д���Ļ������ڽ����õ������󷵻�ֵΪT&��T*���ǿ����޸ĵģ������޸ĵķ���ֵΪconst T& ,const T*��
	//������ֵ�ǲ�����Ϊ�������ص��������ݵģ�ֻ�����¶���һ��const_ListIterator�࣬����������������صķ���ֵ�����const��
	//��Ϊ������Ա�����ķ���ֵ��һ��const����Ҫ���¶���һ������û��Ҫ�ġ�����������һ��������ģ�壬����T&��T*��Ƴ���ģ�壬ʵ����iterator��const_iterator

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

		//��������͸�ֵ�ñ�����Ĭ�ϼ��ɣ��˵������಻�漰����Դ����������Ҫ�ľ���ǳ������
		//����Ҳ����Ҫ������û��new�½ڵ㣬ֻ��һ���ڵ�ָ�롣


		//��������ʹ����ʽ��ָ����ͬ��
		//1. ָ����Խ����ã������������б�������operator*()
		Ref operator*() const
		{
			return _PNode->Date;
		}

		//2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
		//������T��һ���ṹ��ʱ����ʱ�ĵ���������Ҫ�䵱�ṹ��ָ��Ľ�ɫ���ṹ��ָ���ǿ���ʹ��->�ģ�����Ҫ����->��
		//�����ؽṹ��ָ��T*�Ժ�it.operator->()->��it->->���ɶ���̫��������Ż�ʡ����һ��->
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

	//list��
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
			// ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
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
			//��ȫƥ��д��
			//iterator it(_phead->next);
			//return it;

			//��������
			//return iterator(_phead->next);

			//��ʽ����ת��
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
		// ��posλ��ǰ����ֵΪval�Ľڵ�
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
			return newNode;  //��ʽ����ת��
		}

		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
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
