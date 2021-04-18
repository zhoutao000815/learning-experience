#pragma once
#include<vector>
#include<assert.h>
#include<functional>
#include<iostream>
namespace zt
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& left,const T& right)
		{
			//ע�⣺���������T�ıȽ����������ʵ�����أ����û�У�ֻ���������Լ�ʵ��һ���ˡ�
			return left < right;
		}
	};

	template<class T>
	class grater
	{
	public:
		bool operator()(const T& left, const T& right)
		{
			//ע�⣺���������T�ıȽ����������ʵ�����أ����û�У�ֻ���������Լ�ʵ��һ���ˡ�
			return left > right;
		}
	};

	template < class T, class Container = std::vector<T>, class Compare = less<T>>  //stl��Ĭ��less�Ǵ�ѣ�grater��С�ѡ�
	class My_priority_queue
	{
	public:
		My_priority_queue()
			: _c()
		{}

		//ע�⣺����д���������»��н��ѣ�����[ ]���䡣
		template <class InputIterator>
		My_priority_queue(InputIterator first, InputIterator last)
			:_c(first,last)
		{
			//�������Ͻ��ѣ����µ�����
		/*	int lastparents = (_c.size() - 2) >> 1;
			for (int i = lastparents; i >= 0; i--)
			{
				AdJustDown(i);
			}*/

			//�������½��ѣ����ϵ�����
			size_t firstchild = 1;
			for (size_t i = firstchild; i < _c.size(); i++)
			{
				AdJustUp(i);
			}
		}
		
		void AdJustDown(size_t root = 0)
		{
			size_t parents = root;
			size_t child = parents * 2 + 1;
			while (child < _c.size())
			{
				if (child + 1 < _c.size() && cmp(_c[child], _c[child + 1]))
				{
					++child;
				}
				if (cmp(_c[parents], _c[child]))
				{
					std::swap(_c[parents], _c[child]);
					parents = child;
					child = parents * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void AdJustUp(int root)
		{
			int child = root;
			int parents = (child - 1) >> 1;
			while (child>0)       //parents >= 0.��Ϊ-1/2����������������0������parents��Զ>=0������ѭ����
			{
				if (cmp(_c[parents], _c[child]))
				{
					std::swap(_c[parents], _c[child]);
					child = parents;
					parents = (child - 1) >> 1;
				}
				else
				{
					break;
				}
			}
		}
	
		bool empty() const
		{
			return _c.empty();
		}

		size_t size() const
		{
			return _c.size();
		}

		T& top() 
		{
			return _c.front();
		}

		const T& top() const
		{
			return _c.front();
		}
		void push(const T& x)
		{
			_c.push_back(x);
			AdJustUp(_c.size() - 1);
		}

		void pop()
		{
			assert(size() > 0);
			std::swap(_c[0],_c[_c.size()-1]);
			_c.pop_back();
			AdJustDown(0);
		}

		//����������뷽����ԣ���ԭ�ӿ�
		void printf_My_priority_queue()
		{
			while (!empty())
			{
				std::cout << top() << " ";
				pop();
			}
			std::cout << std::endl;
		}
	private:
		Container _c;
		Compare cmp;
	};

};