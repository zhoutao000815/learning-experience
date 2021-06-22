//547. 省份数量
//有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
//
//省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//
//给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
//
//返回矩阵中 省份 的数量。
//
//
//
//示例 1：
//
//
//输入：isConnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
//输出：2
//示例 2：
//
//
//输入：isConnected = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
//输出：3
//
//
//提示：
//
//1 <= n <= 200
//n == isConnected.length
//n == isConnected[i].length
//isConnected[i][j] 为 1 或 0
//isConnected[i][i] == 1
//isConnected[i][j] == isConnected[j][i]

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-provinces
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//并查集
class UnionFindSet{
public:
	UnionFindSet(size_t ufs_size)
		:_ufs(ufs_size, -1){}

	int find_root(int index)    //index是索引下标 
	{
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}
		return index;
	}

	bool Union(int x1, int x2)   //有关系建立集合
	{
		int index1 = find_root(x1);
		int index2 = find_root(x2);

		if (index1 == index2)
		{
			return false;
		}
		_ufs[index1] += _ufs[index2];
		_ufs[index2] = index1;
		return true;
	}

	size_t count() const       //返回集合数
	{
		size_t Count = 0;
		for (size_t i = 0; i<_ufs.size(); i++)
		{
			if (_ufs[i]<0)
				Count++;
		}
		return Count;
	}
private:
	vector<int> _ufs;
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		size_t nsize = isConnected.size();
		UnionFindSet ufs(nsize);
		for (size_t i = 0; i<nsize; i++)
		{
			for (int j = 0; j<nsize && i != j; j++)
			{
				if (isConnected[i][j] == 1)
				{
					ufs.Union(i, j);
				}
			}
		}
		return ufs.count();
	}
};