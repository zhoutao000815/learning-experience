//990. 等式方程的可满足性
//给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
//
//只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。
//
//
//
//示例 1：
//
//输入：["a==b", "b!=a"]
//输出：false
//解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
//示例 2：
//
//输入：["b==a", "a==b"]
//输出：true
//解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
//示例 3：
//
//输入：["a==b", "b==c", "a==c"]
//输出：true
//示例 4：
//
//输入：["a==b", "b!=c", "c==a"]
//输出：false
//示例 5：
//
//输入：["c==c", "b==d", "x!=z"]
//输出：true
//
//
//提示：
//
//1 <= equations.length <= 500
//equations[i].length == 4
//equations[i][0] 和 equations[i][3] 是小写字母
//equations[i][1] 要么是 '='，要么是 '!'
//equations[i][2] 是 '='
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/satisfiability-of-equality-equations
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
	bool equationsPossible(vector<string>& equations) {
		UnionFindSet ufs(26);

		for (int i = 0; i<equations.size(); i++)
		{
			if (equations[i][1] == '=')                //相同的放在一个集合中
				ufs.Union(equations[i][0] - 'a', equations[i][3] - 'a');
		}

		for (int i = 0; i<equations.size(); i++)
		{
			if (equations[i][1] == '!' && (ufs.find_root(equations[i][0] - 'a') == ufs.find_root(equations[i][3] - 'a')))   //不相同，但是在一个集合中，不满足等式方程。
				return false;
		}
		return true;
	}
};