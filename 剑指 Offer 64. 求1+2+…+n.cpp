//��ָ Offer 64. ��1 + 2 + �� + n
//�� 1 + 2 + ... + n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
//
//
//
//ʾ�� 1��
//
//���� : n = 3
// ��� : 6
//	  ʾ�� 2��
//
//  ���� : n = 9
//   ��� : 45
//
//https ://leetcode-cn.com/problems/qiu-12n-lcof/

// class add {
//     friend class Solution;
// public:
//     add()
//     {
//         rel+=_n;
//         _n++;
//     }
//     static int getrel()
//     {
//         return rel;
//     }
//     static void Init()
//     {
//         rel=0;
//         _n=1;
//     }
// private:
//     static int rel;
//     static int _n;
// };
// int add:: rel=0;
// int add:: _n=1;

// class Solution {
// public:
//     int Sum_Solution(int n) {
//         //���ڲ������������Ų��ԣ������г�ʼ�����ۼ���һ��������

//         //����һ:������Ԫ���þ�̬��Ա����ȥ��ʼ����
//         //add::Init();  
//         //==========================
//         //������������Ԫ��ȥ��ʼ��
//         add::rel=0;
//         add::_n=1;
//         //===========
//         //���������ڲ��࣬�ȱ�֤�˷�װ���ֿ��Է���add�ࡣ
//         add sums[n];
//         return add::getrel();
//     }
// };
//���������ڲ���
class Solution{
public:
	int sumNums(int n) {
		rel = 0;
		_n = 1;
		add sums[n];
		return rel;
	}
	class add{
	public:
		add()
		{
			rel += _n;
			_n++;
		}

	};
private:
	static int rel;
	static int _n;
};
int Solution::rel = 0;
int Solution::_n = 1;