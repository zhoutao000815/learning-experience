//77. 组合
//给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//
//你可以按 任何顺序 返回答案。
//
//
//
//示例 1：
//
//输入：n = 4, k = 2
//输出：
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
//示例 2：
//
//输入：n = 1, k = 1
//输出：[[1]]
//
//
//提示：
//
//1 <= n <= 20
//1 <= k <= n
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/combinations
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//可以用子集的思路来做，子集元素个数==组合元素个数 的子集就是结果之一
class Solution {
public:
	void dfs(vector<vector<int>> &res, vector<int> &tmp, int n, int k, int num)
	{
		if (tmp.size() == k || num>n)    //注意：当组合数字num超过n，必然不会有组合。
		{
			if (tmp.size() == k)		//但是不论num有没有超过n只要tmp.size（）达到了k就是符合条件的子集之一。
			{
				res.push_back(tmp);
			}
			return;
		}

		tmp.push_back(num);         //插入当前元素
		dfs(res, tmp, n, k, num + 1);

		tmp.pop_back();				//取出当前元素
		dfs(res, tmp, n, k, num + 1);
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> tmp;
		dfs(res, tmp, n, k, 1);
		return res;
	}
};