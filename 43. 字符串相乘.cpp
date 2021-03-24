//43. �ַ������
//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
//
//ʾ�� 1:
//
//���� : num1 = "2", num2 = "3"
//��� : "6"
//	 ʾ�� 2 :
//
// ���� : num1 = "123", num2 = "456"
//  ��� : "56088"
//
//		��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode-cn.com/problems/multiply-strings
//	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		//����һ��������ˣ����Կ�����num1��num2��ӣ�����ʱ�临�ӶȺͿռ临�Ӷȶ��Ƚϸ�,���ܻᳬʱ��

		string zero = "0";
		if (zero == num1 || zero == num2)
		{
			return zero;
		}
		//��������ģ��ʵ����ʽ�˷�
		//��num2�ĵ�λ���ߺ�num1��˵õ�num2.size�������ַ�������������ӡ�
		size_t size1 = num1.size();
		size_t size2 = num2.size();
		string* retarry = new string[size2];
		size_t sum1 = 0;
		size_t sum2 = 0;
		size_t next = 0;      //��λ
		int retarrysize = 0;
		for (int i = size2 - 1; i >= 0; i--)
		{
			next = 0;
			sum2 = num2[i] - '0';
			for (int j = size1 - 1; j >= 0; j--)
			{

				sum1 = num1[j] - '0';
				retarry[retarrysize] += (sum1*sum2 + next) % 10 + '0';  //�ǵ����Ƚ�λ�����������������������ٽ�λ
				next = (sum1*sum2 + next) / 10;             //ͬ��һ��
			}
			if (next != 0)
			{
				retarry[retarrysize] += next + '0';
			}
			reverse(retarry[retarrysize].begin(), retarry[retarrysize].end());   //������
			retarry[retarrysize].append(retarrysize, '0');         //�ڼӶ�Ӧλ�θ�����0
			retarrysize++;
		}
		string retstr = "";
		while (retarrysize >= 0)
		{
			retstr = addStrings(retstr, retarry[retarrysize--]);
		}
		return retstr;
	}

	string addStrings(string num1, string num2) {
		string sret;
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int next = 0;
		int sum1;
		int sum2;
		while (end1 >= 0 || end2 >= 0)
		{
			sum1 = end1 >= 0 ? num1[end1] - '0' : 0;
			sum2 = end2 >= 0 ? num2[end2] - '0' : 0;
			int add = sum1 + sum2 + next;
			if (add >= 10)
			{
				add %= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			//sret.insert(sret.begin(), add+'0');  //ͷ��ҪŲ�����ݣ�Ч�ʵ��£���β�壬������á�
			sret += ('0' + add);
			--end1;
			--end2;
		}
		if (1 == next)
		{
			sret += '1';
		}
		reverse(sret.begin(), sret.end());
		return sret;
	}
};
int main()
{
	Solution s1;
	string result=s1.multiply("123456789","987654321");
	cout << result << endl;
	return 0;
}