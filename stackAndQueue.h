#pragma once
#include<deque>
#include<assert.h>
namespace zt
{
	template<class T, class Con = std::deque<T>>
	class stack
	{
	public:
		stack()
			//:_c(Con())
		{}

		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			assert(!_c.empty());
			_c.pop_back();
		}

		T& top()
		{
			return _c.back();
		}

		const T& top()const
		{
			return _c.back();
		}

		size_t size()const
		{
			return _c.size();
		}

		bool empty()const
		{
			return _c.empty();
		}

	private:
		Con _c;
	};

	template<class T, class Con = std::deque<T>>

	class queue
	{

	public:
		queue()
			//:_c(Con())
		{}

		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			assert(!_c.empty());
			_c.pop_front();
		}

		T& back()
		{
			return _c.back();
		}

		const T& back()const
		{
			return _c.back();
		}

		T& front()
		{
			return _c.front();
		}

		const T& front()const
		{
			return _c.front();
		}

		size_t size()const
		{
			return _c.size();
		}

		bool empty()const
		{
			return _c.empty();
		}

	private:

		Con _c;
	};
}