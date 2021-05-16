//94. 二叉树的中序遍历
//给定一个二叉树的根节点 root ，返回它的 中序 遍历。
//
//
//
//示例 1：
//
//
//输入：root = [1, null, 2, 3]
//输出：[1, 3, 2]
//示例 2：
//
//输入：root = []
//输出：[]
//示例 3：
//
//输入：root = [1]
//输出：[1]
//示例 4：
//
//
//输入：root = [1, 2]
//输出：[2, 1]
//示例 5：
//
//
//输入：root = [1, null, 2]
//输出：[1, 2]
//
//
//提示：
//
//树中节点数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//
//
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//
//
//来源：力扣（LeetCode）
// 链接：https ://leetcode-cn.com/problems/binary-tree-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		//用私有栈，去模拟操作系统栈递归的走法。
		//注意应该在哪里保存节点的val

		//中序: 左子树 根 右子树
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			TreeNode* top = st.top();
			st.pop();
			v.push_back(top->val);   //在这里保存节点val，

			cur = top->right;
		}
		return v;
	}
};