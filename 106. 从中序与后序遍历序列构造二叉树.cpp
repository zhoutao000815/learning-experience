//106. 从中序与后序遍历序列构造二叉树
//根据一棵树的中序遍历与后序遍历构造二叉树。
//
//注意 :
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//中序遍历 inorder = [9, 3, 15, 20, 7]
//后序遍历 postorder = [9, 15, 7, 20, 3]
//返回如下的二叉树：
//
//3
/// \
//9  20
/// \
//15   7


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
	void build(vector<int>& inorder, vector<int>& postorder, int &post, int left, int right, TreeNode* &root)
	{
		int flag = -1;
		for (int i = right; right >= left; i--)
		{
			if (postorder[post] == inorder[i])
			{
				flag = i;
				post--;
				break;
			}
		}
		if (flag == -1)
		{
			return;
		}
		root = new TreeNode(inorder[flag]);
		if (flag<right)
		{
			build(inorder, postorder, post, flag + 1, right, root->right);
		}
		if (left<flag)
		{
			build(inorder, postorder, post, left, flag - 1, root->left);
		}
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int post = postorder.size() - 1;
		TreeNode* root = nullptr;
		build(inorder, postorder, post, 0, post, root);
		return root;
	}
};