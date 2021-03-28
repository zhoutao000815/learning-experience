#pragma once
#pragma warning (disable:4996)
#include<assert.h>
#include<iostream>
namespace zt
{
	class string {
	public:
		//构建空字符串的写法
		/*string()
		:_str(new char [1])
		{
		_str[0]='\0';
		}*/

		//以下两种为错误的：全缺省参数的默认构造函数
		//string(const char* str="\0")
		//string(const char* str=nullptr)
		string(const char* str = "")
			: _str(new char[strlen(str) + 1])
		{
			if (nullptr == str)
			{
				str = "";
				//assert(false);
				//return;
			}
			size_t size = strlen(str);
			this->_size = size;
			this->_capacity = size;
			strcpy(_str, str);   //因为strcpy会把结尾标识符'\0'一起拷贝过去，所以不用对额外开辟的+1空间特别处理。
			//*dst++ = *src++; *和++的优先级相同，由结合性表示最终的运算顺序。
		}

		//拷贝构造
		//传统写法
		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			size_t size = strlen(s._str);
			this->_size = size;
			this->_capacity = size;
			strcpy(_str, s._str);
		}*/

		//现代写法
		string(const string&s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string temp(s._str);

			//std::swap(_str, temp._str);  //只交换了字符串，没有交换资源信息

			//this->swap(temp);    //自己实现的string类swap函数，交换资源信息
			swap(temp);
		}

		//=赋值运算符重载
		//传统写法
		/*string& operator =(const string& s)
		{
			if (this != &s)
			{
				delete[]_str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}*/

		//新型写法
		//写法一:
		//这种交换方式在赋值语句中，有利于预防内存泄漏，因为交换完成的临时对象，一旦生存作用域结束，就会自动调用其析构函数，释放对应的资源
		/*string& operator =(string s)
		{
			if(this!=&s)
			{
				//std::swap(_str, s._str);  //简单交换字符串

				//this->swap(temp);    //交换所有信息
				swap(temp);
			}
			return *this;
		}*/

		//写法二:
		string& operator =(string s)
		{
			//std::swap(_str, s._str);//简单交换字符串

			//this->swap(temp);    //交换所有
			swap(s);

			return *this;
		}

		~string()
		{
			if (nullptr != _str)
			{
				delete[] _str;
			}
			this->_size = 0;
			this->_capacity = 0;
			_str = nullptr;
		}

	public:
		typedef char* iterator;
		//////////////////////////////////////////////////////////////

		// iterator

		iterator begin()
		{
			return &_str[0];
		}

		iterator end()
		{
			return &_str[_size];
		}

		iterator begin()const
		{
			return &_str[0];
		}

		iterator end()const
		{
			return &_str[_size];
		}
		//	/////////////////////////////////////////////////////////////

		//	// modify

		void PushBack(char c)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';
		}

		string& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}

		void Append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcat(_str, str);
			_size = len + _size;
		}

		string& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		void swap(string &s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		const char* c_str()const
		{
			return _str;
		}

		///////////////////////////////////////////////////////////////

		//// capacity

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			if (0 == _size)
			{
				return true;
			}
			return  false;
		}

		void resize(size_t newSize, char c = '\0')
		{
						
			if (newSize < _size)
			{
				_size = newSize;
				_str[_size] = '\0';
			}
			else 
			{
				if (newSize>_capacity)
				{
					reserve(newSize);
				}

				for (size_t i = _size; i < newSize; i++)
				{
					_str[i] = c;
				}
				_size = newSize;
				_str[_size] = '\0';
			}

		}

		//这个接口只针对大于当前容量的新容量标准，小于则无作用。
		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char *temp = new char[newCapacity + 1];
				strcpy(temp, _str);
				delete[]_str;
				_str = temp;
				_capacity = newCapacity;
			}
		}

		///////////////////////////////////////////////////////////////

		//// access

		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			return _str[index];
		}

		///////////////////////////////////////////////////////////////

		////relational operators

		//bool operator<(const string& s);

		//bool operator<=(const string& s);

		//bool operator>(const string& s);

		//bool operator>=(const string& s);

		//bool operator==(const string& s);

		//bool operator!=(const string& s);



		//// 返回c在string中第一次出现的位置

		//size_t find(char c, size_t pos = 0) const;

		//// 返回子串s在string中第一次出现的位置

		//size_t find(const char* s, size_t pos = 0) const;

		//// 在pos位置上插入字符c/字符串str，并返回该字符的位置

		//string& insert(size_t pos, char c);

		//string& insert(size_t pos, const char* str);



		//// 删除pos位置上的元素，并返回该元素的下一个位置

		//string& erase(size_t pos, size_t len);

	private:
		char* _str;
		unsigned _size;
		unsigned _capacity;
	};
}