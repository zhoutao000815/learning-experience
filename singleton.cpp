#include<iostream>
#include<mutex>
using namespace std;

//饿汉模式：优点：编码简单，多线程环境下由于没有锁竞争，效率高于懒汉模式；
//缺点：程序编译时进行实例化出一个对象，有可能并不使用，导致程序启动慢。而且多个单例对象时，实例化顺序不确定。
//class singleton{
//public:
//	static singleton*getInstance()
//	{
//		return &instance;
//	}
//	void test()
//	{
//		cout << "单例饿汉成功" << endl;
//	}
//private:
//	singleton()
//	{}
//	singleton(const singleton &sin) = delete;
//	singleton& operator=(const singleton &sin) = delete;
//
//	static singleton instance;
//};
//singleton singleton::instance;        //在程序入口前完成类的实例化。

//懒汉模式：优点：需要时再创建对象，不同单例对象实例顺序可控，程序启动速度快。
//缺点：编码稍复杂，有线程安全问题，上锁会使得效率变低。
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
		cout << "单例懒汉成功" << endl;
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