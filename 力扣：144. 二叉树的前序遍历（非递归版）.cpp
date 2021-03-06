﻿//144. 二叉树的前序遍历
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//
//
//示例 1：
//
//
//输入：root = [1, null, 2, 3]
//输出：[1, 2, 3]
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
//输出：[1, 2]
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
//进阶：递归算法很简单，你可以通过迭代算法完成吗？
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-preorder-traversal
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
	vector<int> preorderTraversal(TreeNode* root) {
		//递归也是在操作系统的栈空间上完成的，我们用栈模拟一下即可。
		//不过注意要得到序列的数组，所以用数组保存

		//前序  根 左子树 右子树
		//我们把所有的左子树节点放进栈，同时val入数组，当左子树走不下去，出栈顶，再走栈顶的右子树。
		//如此循环。
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty())  //根节点还未入栈，所以加一个cur不为空的判断条件 。
		{
			while (cur)  //将左路节点全部入栈，
			{
				st.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			}
			TreeNode* top = st.top();
			st.pop();
			cur = top->right; //左路走完了，再走右子树，
		}
		return v;
	}
};