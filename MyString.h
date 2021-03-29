#pragma once
#pragma warning (disable:4996)
#include<assert.h>
#include<iostream>
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
			strcpy(_str, str);   //��Ϊstrcpy��ѽ�β��ʶ��'\0'һ�𿽱���ȥ�����Բ��öԶ��⿪�ٵ�+1�ռ��ر���
			//*dst++ = *src++; *��++�����ȼ���ͬ���ɽ���Ա�ʾ���յ�����˳��
		}

		//��������
		//��ͳд��
		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			size_t size = strlen(s._str);
			this->_size = size;
			this->_capacity = size;
			strcpy(_str, s._str);
		}*/

		//�ִ�д��
		string(const string&s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string temp(s._str);

			//std::swap(_str, temp._str);  //ֻ�������ַ�����û�н�����Դ��Ϣ

			//this->swap(temp);    //�Լ�ʵ�ֵ�string��swap������������Դ��Ϣ
			swap(temp);
		}

		//=��ֵ���������
		//��ͳд��
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
		//д��һ:
		//���ֽ�����ʽ�ڸ�ֵ����У�������Ԥ���ڴ�й©����Ϊ������ɵ���ʱ����һ������������������ͻ��Զ������������������ͷŶ�Ӧ����Դ
		/*string& operator =(string s)
		{
			if(this!=&s)
			{
				//std::swap(_str, s._str);  //�򵥽����ַ���

				//this->swap(temp);    //����������Ϣ
				swap(temp);
			}
			return *this;
		}*/

		//д����:
		string& operator =(string s)
		{
			//std::swap(_str, s._str);//�򵥽����ַ���

			//this->swap(temp);    //��������
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

		//����ӿ�ֻ��Դ��ڵ�ǰ��������������׼��С���������á�
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

		bool operator<(const string& s)
		{
			return !(*this>=s);
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			size_t i1 = 0, i2 = 0;
			size_t size1 = this->size(), size2 = s.size();
			while (i1 < size1 && i2 <size2)
			{
				if ((*this)[i1]>s[i2])
				{
					return true;
				}
				else
				{
					if ((*this)[i1] < s[i2])
					{
						return false;
					}
					else  //���
					{
						i1++;
						i2++;
					}
				}
			}

			if (i1 < size1)
			{
				return true;
			}
			return false;
		}

		bool operator>=(const string& s)
		{
			return *this > s || *this == s;
		}

		bool operator==(const string& s)
		{
			size_t i1 = 0, i2 = 0;
			size_t size1 = this->size(), size2 = s.size();
			while (i1 < size1 && i2 <size2)
			{
				if ((*this)[i1]>s[i2])
				{
					return false;
				}
				else
				{
					if ((*this)[i1] < s[i2])
					{
						return false;
					}
					else  //���
					{
						i1++;
						i2++;
					}
				}
			}

			if (i1 == size1 && i2==size2)
			{
				return true;
			}
			return false;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}



		//// ����c��string�е�һ�γ��ֵ�λ��

		size_t find(char c, size_t pos = 0) const
		{
			size_t  ret = pos;
			while (ret < _size)
			{
				if (c == _str[ret])
				{
					return ret;
				}
				ret++;
			}
			return npos;
		}

		//// �����Ӵ�s��string�е�һ�γ��ֵ�λ��

		size_t find(const char* s, size_t pos = 0) const
		{
			const char* ret = strstr(_str+pos, s);
			if (ret == nullptr)
			{
				return npos;
			}
			else
			{
				return ret - _str;
			}
		}

		//// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

		string& insert(size_t pos, char c)
		{
			assert(_size >= pos);
			if (_size == _capacity)
			{
				reserve(_size * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = c;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(_size >= pos);
			size_t len = strlen(str);
			if (_size+len > _capacity)
			{
				reserve(_size + strlen(str));
			}
			size_t end = _size+len;
			while (end >= pos + len)          //ע����������ƶ����ݵ�ѭ������
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}



		//// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (npos == len || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
				return *this;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
				return *this;
			}
		}

	private:
		char* _str;
		unsigned _size;
		unsigned _capacity;
		public:
			static const size_t npos;
	};
	const size_t string::npos = -1;

	// << >>��һ��Ҫ����Ϊ��Ԫ��ֻ����Ҫֱ�ӷ���privat��Աʱ�����б�Ҫ������Ԫ����ӷ���ʱ������Ϊȫ�ֺ���Ҳ�ǿ��Եġ�
	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	std::istream& operator>>(std::istream& in, string& s)
	{
		s.resize(0);
		char ch;
		while (1)
		{
			//in>>ch;
			in.get(ch);
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}

		return in;
	}
}