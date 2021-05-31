//145. 二叉树的后序遍历
//给定一个二叉树，返回它的 后序 遍历。
//
//示例 :
//
//输入 : [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//输出:[3, 2, 1]
//进阶 : 递归算法很简单，你可以通过迭代算法完成吗？

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* prev = nullptr;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			TreeNode* top = st.top();

			if (top->right == nullptr || top->right == prev)    //如果右为空，或者右已经被访问过，那就可以访问中间节点。否则访问右节点。
			{
				prev = top;
				v.push_back(top->val);
				st.pop();
			}
			else
			{
				cur = top->right;
			}
		}
		return v;
	}
};