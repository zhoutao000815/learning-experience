//14. �����ǰ׺
//��дһ�������������ַ��������е������ǰ׺��
//
//��������ڹ���ǰ׺�����ؿ��ַ��� ""��
//
//
//
//ʾ�� 1��
//
//���룺strs = ["flower", "flow", "flight"]
//�����"fl"
//ʾ�� 2��
//
//���룺strs = ["dog", "racecar", "car"]
//�����""
//���ͣ����벻���ڹ���ǰ׺��
//
//
//��ʾ��
//
//0 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] ����СдӢ����ĸ���
//
//���ͣ����벻���ڹ���ǰ׺��
//
//
//��ʾ��
//
//0 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] ����СдӢ����ĸ���
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/longest-common-prefix
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret;
		if (strs.size() == 0)
		{
			return ret;
		}
		size_t minlen = strs[0].size();  //��Ȼ���ǰ׺�������Ҳ����������ַ����ĳ��ȡ�
		for (int i = 0; i<strs.size(); i++)
		{
			if (strs[i].size()<minlen)
			{
				minlen = strs[i].size();
			}
		}
		for (int i = 0; i<minlen; i++)
		{
			int j = 1;
			for (; j<strs.size(); j++)
			{
				if (strs[j][i] != strs[j - 1][i])
				{
					return ret;
				}
			}
			ret += strs[0][i];
		}
		return ret;
	}
};