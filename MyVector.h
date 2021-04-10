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

		//�������д�Ľӿڣ�����vector�ٷ��ӿ�
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

			//����������������ص㣡�����reserveģ��
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
			//�ص�
			if (n > capacity())
			{
				T* tmp = new T[n];//�����û�����ݵ�ԭvector������Ҫ�������ݣ��ж�һ��

				////�����memcpy������������T*��ָ����ԭ���ĵ�ַ�ռ��������.
				////�������������ǿ��Եģ����Ƕ�������Դ���䣨new�����Զ���������?
				//if (_start != nullptr)
				//{
				//	memcpy(tmp, _start, sizeof(T)*size());
				//}

				//�����һ����Դ���䣨new�����Զ������ͣ�����T*ָ��������ǲ��еģ�
				//����T�Ǹ�string����������memcpy����ʹtmp���string��� char* str��ָ��ԭ����str�ռ䡣
				//Ȼ�������ʱ����tmp��ԭ����_start���string��ָ����ԭ����string���˳�ʱ��ͬһ���ռ�����string�����������ã��������
				size_t i;
				if (_start != nullptr)
				{
					for (i = 0; i < size(); i++)
					{
						tmp[i] = _start[i];        //�������������ͣ������Զ������ͣ���ֱ�������ǵĸ�ֵ������������T*��ָ�ռ����������ݵĿ�����
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

				//��������ˣ���ô��������ʧЧ�ˣ����¸�ֵʹ����Ч��
				pos = _start + posi;
			}
			iterator tmp = pos;

			//����ͬ�����У�memcpy��ı��˿ռ��ϵ�ӳ���ϵ��������T*���Ͷ�Ӧ�����ϵĿ�����
			//����ͷ�壬��ôstart��start+1��ָ����start[0]��
			//��finish��ָ����finishǰһ���Ŀռ䣬��������������ռ�ʲô��û�С�
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
			
			//ͬ��
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