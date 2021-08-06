//1116. ��ӡ������ż��
//��������ôһ���ࣺ
//
//class ZeroEvenOdd {
//	public ZeroEvenOdd(int n) { ... }      // ���캯��
//	public void zero(printNumber) { ... }  // ����ӡ�� 0
//	public void even(printNumber) { ... }  // ����ӡ�� ż��
//	public void odd(printNumber) { ... }   // ����ӡ�� ����
//}
//��ͬ��һ�� ZeroEvenOdd ��ʵ�����ᴫ�ݸ�������ͬ���̣߳�
//
//�߳� A ������ zero()����ֻ��� 0 ��
//�߳� B ������ even()����ֻ���ż����
//�߳� C ������ odd()����ֻ���������
//ÿ���̶߳���һ�� printNumber ���������һ�����������޸ĸ����Ĵ���������������� 010203040506...���������еĳ��ȱ���Ϊ 2n��
//
//
//
//ʾ�� 1��
//
//���룺n = 2
//�����"0102"
//˵���������߳��첽ִ�У�����һ������ zero()����һ���̵߳��� even()�����һ���̵߳���odd()����ȷ�����Ϊ "0102"��
//ʾ�� 2��
//
//���룺n = 5
//�����"0102030405"
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/print-zero-even-odd
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//˼·����C++11�Դ��̡߳�������������ȥ���ƴ�ӡ˳��
//������Ŀ˼·��ÿ�δ�ӡ�����ֺ�Ҫ�ص�0ֵ��������Ҫһ����׼λ is_zero˵���ô�ӡ0�ˡ�
//�����ӡ���ֵ��߳�Ҳ���Ⱥ�˳�򣬻��ǽ����ӡ��������Ҫ����һ����־λ��0����ô���������ż����
//oֵ�߳���is_zero���Ƽ��ɣ�����ż���̱߳����0���꣬�����ֵ��Լ�ʱ�Ŵ�ӡ�������߼�������ע��
class ZeroEvenOdd {
private:
	int n;
	bool is_zero = true;
	bool flag = true;
	condition_variable cv;
	mutex mtx;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		int i = 0;
		while (i<n)          //һ��Ҫ��i��0.
		{
			unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [&]()->bool{return is_zero; });     //is_zeroΪ�����ӡ0ֵ��
			printNumber(0);
			i++;
			is_zero = false;
			flag = !flag;                     //���߼�ȡ����������һ���ô�ӡ��������ż����
			cv.notify_all();
		}

	}

	void even(function<void(int)> printNumber) {
		int i = 2;
		while (i <= n)
		{
			unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [&]()->bool{return !is_zero && flag; });
			printNumber(i);
			i += 2;
			is_zero = true;                   //�����ûص���ӡ0ֵ�߳�
			cv.notify_all();
		}

	}

	void odd(function<void(int)> printNumber) {
		int i = 1;
		while (i <= n)
		{
			unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [&]()->bool{return !is_zero && !flag; });    //�����߳��ȴ�ӡ��flag��ʼΪtrue
			printNumber(i);
			i += 2;
			is_zero = true;                  //�����ûص���ӡ0ֵ�߳�
			cv.notify_all();
		}

	}
};