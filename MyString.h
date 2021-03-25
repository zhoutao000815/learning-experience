#pragma once
#pragma warning (disable:4996)
#include<iostream>
#include<assert.h>
namespace zt
{
	class string {
	public:
		//�������ַ�����д��
		/*string()
		:_str(new char [1])
		{
		_str[0]='\0';
		}*/

		//��������Ϊ����ģ�ȫȱʡ������Ĭ�Ϲ��캯��
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
			strcpy(_str, str);   //��Ϊstrcpy��ѽ�β��ʶ��'\0'һ�𿽱���ȥ�����Բ��öԶ��⿪�ٵ�+1�ռ��ر���
			//*dst++ = *src++; *��++�����ȼ���ͬ���ɽ���Ա�ʾ���յ�����˳��
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

		//����д��
		//���ֽ�����ʽ�ڸ�ֵ����У�������Ԥ���ڴ�й©����Ϊ������ɵ���ʱ����һ������������������ͻ��Զ������������������ͷŶ�Ӧ����Դ
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