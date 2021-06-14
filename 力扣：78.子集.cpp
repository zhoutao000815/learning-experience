//78. 子集
//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 3]
//输出：[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//示例 2：
//
//输入：nums = [0]
//输出：[[], [0]]
//
//
//提示：
//
//1 <= nums.length <= 10
//- 10 <= nums[i] <= 10
//nums 中的所有元素 互不相同
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/subsets
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归回溯
class Solution {
public:
	vector<int> tmp;
	void dfs(vector<vector<int>> &res, vector<int>& nums, int begin)
	{
		if (begin == nums.size())
		{
			//记录
			res.push_back(tmp);
			return;
		}

		tmp.push_back(nums[begin]);
		dfs(res, nums, begin + 1);          //加入当前位置

		tmp.pop_back();
		dfs(res, nums, begin + 1);          //不加入当前位置            
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		dfs(res, nums, 0);
		return res;
	}
};

//迭代位运算
class Solution {
public:
	vector<int> t;
	vector<vector<int>> ans;

	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		for (int mask = 0; mask < (1 << n); ++mask) {
			t.clear();
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					t.push_back(nums[i]);
				}
			}
			ans.push_back(t);
		}
		return ans;
	}
};
