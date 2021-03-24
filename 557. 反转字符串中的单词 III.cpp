//557. ��ת�ַ����еĵ��� III
//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//
//
//
//ʾ����
//
//���룺"Let's take LeetCode contest"
//�����"s'teL ekat edoCteeL tsetnoc"
//
//
//
//��ʾ��
//
//���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/reverse-words-in-a-string-iii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	string reverseWords(string s) {
		string::iterator begin = s.begin();
		string::iterator end = s.end();
		size_t pos = 0;
		while (begin != end)
		{
			begin = s.begin() + pos;
			pos = s.find(' ', pos);
			if (pos == string::npos)
			{
				std::reverse(begin, s.end());
				break;
			}
			std::reverse(begin, s.begin() + pos);
			pos++;
		}
		return s;
	}
};