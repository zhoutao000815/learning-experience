#pragma once
#include <iostream>
#include <assert.h>
namespace zt
{
	template <class T>
	class MyVector
	{
	public:
		//  iterator===========================================================

		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		//方便测试写的接口，并非vector官方接口
		void Vprintf()
		{
			iterator first = begin();
			iterator last = end();
			while (first != last)
			{
				std::cout << *first++ << std::endl;
			}
			//std::cout << std::endl;
		}

		//construct and destory=======================================
		MyVector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{		}

		MyVector(int size, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[size];
			for (int i = 0; i < size; i++)
			{
				_start[i] = value;
			}
			_finish = _end_of_storage = _start + size;
		}

		template <class InputIterator>
		//[ , )
		MyVector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[last - first];
			int i = 0;

			//下面这个拷贝！！重点！详解在reserve模块
			while (first != last)
			{
				_start[i++] = *first;
				first++;
			}

			_finish = _end_of_storage = _start + i;
		}

		//v1(v2)
		MyVector(const MyVector & v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			MyVector tmp(v.cbegin(), v.cend());
			swap(tmp);
		}

		MyVector<T>& operator =(MyVector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		~MyVector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_end_of_storage = nullptr;
		}

		//Capacity:===================================================
		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void reserve(size_t n)
		{
			//重点
			if (n > capacity())
			{
				T* tmp = new T[n];//如果是没有数据的原vector，则不需要拷贝数据，判断一下

				////如果用memcpy拷贝的是三个T*，指向了原来的地址空间里的内容.
				////对于内置类型是可以的，但是对于有资源分配（new）的自定义类型呢?
				//if (_start != nullptr)
				//{
				//	memcpy(tmp, _start, sizeof(T)*size());
				//}

				//如果是一个资源分配（new）的自定义类型，拷贝T*指向的类型是不行的，
				//假设T是个string，我们再用memcpy，会使tmp里的string里的 char* str仍指向原来的str空间。
				//然后这个临时对象tmp和原对象_start里的string都指向了原来的string，退出时，同一个空间两次string析构函数调用，程序崩溃
				size_t i;
				if (_start != nullptr)
				{
					for (i = 0; i < size(); i++)
					{
						tmp[i] = _start[i];        //不论是内置类型，还是自定义类型，都直接用他们的赋值运算符重载完成T*所指空间上所有数据的拷贝。
					}
				}
				delete[] _start;
				_start = tmp;
				_finish = tmp + i;
				_end_of_storage = tmp + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n>size())
			{
				if (n > capacity())
				{
					reserve(n);
				}
				for (size_t i = size(); i < n; i++)
				{
					_start[i] = value;
				}
				_finish = _start + n;
			}
		}

		//access=================================================

		T& operator[](size_t pos)
		{
			return *(_start + pos);
		}

		const T& operator[](size_t pos)const
		{
			return *(_start + pos);
		}

		//Modifiers:================================================

		void swap(MyVector<T> &v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}



		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}


		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			size_t posi = pos - _start;
			if (_finish == _end_of_storage)
			{
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);

				//如果增容了，那么迭代器就失效了，重新赋值使其有效，
				pos = _start + posi;
			}
			iterator tmp = pos;

			//这里同样不行，memcpy会改变了空间上的映射关系，而不是T*类型对应数据上的拷贝。
			//假设头插，那么start和start+1都指向了start[0]。
			//而finish又指向了finish前一个的空间，新增出来的这个空间什么都没有。
			//memcpy(pos + 1, pos, sizeof(T*)*(end() - pos));
			
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*tmp = x;
			++_finish;
			return pos;
		}
	
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			
			//同上
			//memcpy(pos, pos+1, sizeof(T*)*(end() - pos));

			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}