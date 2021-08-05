//1114. �����ӡ
//�����ṩ��һ���ࣺ
//
//public class Foo {
//	public void first() { print("first"); }
//	public void second() { print("second"); }
//	public void third() { print("third"); }
//}
//������ͬ���߳� A��B��C ���Ṳ��һ�� Foo ʵ����
//
//һ��������� first() ����
//һ��������� second() ����
//����һ��������� third() ����
//������޸ĳ�����ȷ�� second() ������ first() ����֮��ִ�У�third() ������ second() ����֮��ִ�С�
//
//
//
//ʾ�� 1:
//
//���� : [1, 2, 3]
//��� : "firstsecondthird"
// ���� :
//	�������̻߳ᱻ�첽������
//	����[1, 2, 3] ��ʾ�߳� A ������� first() �������߳� B ������� second() �������߳� C ������� third() ������
//	��ȷ������� "firstsecondthird"��
//	ʾ�� 2 :
//
//���� : [1, 3, 2]
// ��� : "firstsecondthird"
//  ���� :
//	 ����[1, 3, 2] ��ʾ�߳� A ������� first() �������߳� B ������� third() �������߳� C ������� second() ������
//	 ��ȷ������� "firstsecondthird"��
//
//
//	 ��ʾ��
//
//	 ���������е������ƺ���ʾ��˳�򣬵������ǲ�����֤�߳��ڲ���ϵͳ�еĵ���˳��
//	 �㿴���������ʽ��Ҫ��Ϊ��ȷ�����Ե�ȫ���ԡ�

//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/print-in-order
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Foo {
private:
	mutex mtx;
	condition_variable cv;
	bool first_cond = false;
	bool second_cond = false;
public:
	Foo() {

	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		first_cond = true;
		cv.notify_all();								    //�������̶߳���cv�µȣ�����һ���Ļ����ܱ�֤���ѵ���second��
	}

	void second(function<void()> printSecond) {
		unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&]()->bool{return first_cond; });
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		second_cond = true;
		cv.notify_one();									//ֻʣ��һ���߳���cv�µ��ˡ�
	}

	void third(function<void()> printThird) {
		unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&]()->bool{return second_cond; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
		//second_cond=false;
	}
};