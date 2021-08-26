#include<iostream>
#include<mutex>
using namespace std;

//����ģʽ���ŵ㣺����򵥣����̻߳���������û����������Ч�ʸ�������ģʽ��
//ȱ�㣺�������ʱ����ʵ������һ�������п��ܲ���ʹ�ã����³��������������Ҷ����������ʱ��ʵ����˳��ȷ����
//class singleton{
//public:
//	static singleton*getInstance()
//	{
//		return &instance;
//	}
//	void test()
//	{
//		cout << "���������ɹ�" << endl;
//	}
//private:
//	singleton()
//	{}
//	singleton(const singleton &sin) = delete;
//	singleton& operator=(const singleton &sin) = delete;
//
//	static singleton instance;
//};
//singleton singleton::instance;        //�ڳ������ǰ������ʵ������

//����ģʽ���ŵ㣺��Ҫʱ�ٴ������󣬲�ͬ��������ʵ��˳��ɿأ����������ٶȿ졣
//ȱ�㣺�����Ը��ӣ����̰߳�ȫ���⣬������ʹ��Ч�ʱ�͡�
class singleton{
public:
	static singleton*getInstance()
	{
		if (instance == nullptr)
		{
			unique_lock<mutex> u_lock(lock);
			if (instance == nullptr)
			{
				instance = new singleton();
			}
		}
		return instance;
	}
	void test()
	{
		cout << "���������ɹ�" << endl;
	}
private:
	singleton()
	{}
	singleton(const singleton &sin) = delete;
	singleton& operator=(const singleton &sin) = delete;
	
	static singleton* instance;
	static mutex lock;
};
singleton* singleton::instance=nullptr;    
mutex singleton::lock;


int main()
{
	singleton* t1 = singleton::getInstance();
	t1->test();

	return 0;
}