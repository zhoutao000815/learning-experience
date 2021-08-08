//77. ���
//������������ n �� k�����ط�Χ[1, n] �����п��ܵ� k ��������ϡ�
//
//����԰� �κ�˳�� ���ش𰸡�
//
//
//
//ʾ�� 1��
//
//���룺n = 4, k = 2
//�����
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
//ʾ�� 2��
//
//���룺n = 1, k = 1
//�����[[1]]
//
//
//��ʾ��
//
//1 <= n <= 20
//1 <= k <= n
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/combinations
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//�������Ӽ���˼·�������Ӽ�Ԫ�ظ���==���Ԫ�ظ��� ���Ӽ����ǽ��֮һ
class Solution {
public:
	void dfs(vector<vector<int>> &res, vector<int> &tmp, int n, int k, int num)
	{
		if (tmp.size() == k || num>n)    //ע�⣺���������num����n����Ȼ��������ϡ�
		{
			if (tmp.size() == k)		//���ǲ���num��û�г���nֻҪtmp.size�����ﵽ��k���Ƿ����������Ӽ�֮һ��
			{
				res.push_back(tmp);
			}
			return;
		}

		tmp.push_back(num);         //���뵱ǰԪ��
		dfs(res, tmp, n, k, num + 1);

		tmp.pop_back();				//ȡ����ǰԪ��
		dfs(res, tmp, n, k, num + 1);
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> tmp;
		dfs(res, tmp, n, k, 1);
		return res;
	}
};