#pragma once
#pragma warning (disable:4996)
#include<iostream>
#include<assert.h>
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
			:_str(new char[strlen(str) + 1])
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

		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			size_t size = strlen(s._str);
			this->_size = size;
			this->_capacity = size;
			strcpy(_str, s._str);
		}

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
		//这种交换方式在赋值语句中，有利于预防内存泄漏，因为交换完成的临时对象，一旦生存作用域结束，就会自动调用其析构函数，释放对应的资源
		string& operator =(string s)
		{
			std::swap(_str, s._str);
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

		char& operator [](unsigned int t)
		{
			return _str[t];
		}

		const char* c_str()
		{
			return _str;
		}
	private:
		char* _str;
		unsigned  _size;
		unsigned _capacity;
	};
}