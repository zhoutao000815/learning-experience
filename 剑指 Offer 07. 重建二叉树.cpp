//剑指 Offer 07. 重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//
//
//例如，给出
//
//前序遍历 preorder = [3, 9, 20, 15, 7]
//中序遍历 inorder = [9, 3, 15, 20, 7]
//返回如下的二叉树：
//
//3
/// \
//9  20
/// \
//15   7
//
//
//限制：
//
//0 <= 节点个数 <= 5000
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void dfsbuild(vector<int>& preorder, vector<int>& inorder, int &psize, int left, int right, TreeNode*&root)
	{
		int mid = -1;
		for (size_t i = left; i <= right; i++)
		{
			if (preorder[psize] == inorder[i])
			{
				mid = i;
				psize++;
				break;
			}
		}
		if (mid == -1)
		{
			return;
		}
		root = new TreeNode(inorder[mid]);
		if (left<mid)
		{
			dfsbuild(preorder, inorder, psize, left, mid - 1, root->left);
		}
		if (mid<right)
		{
			dfsbuild(preorder, inorder, psize, mid + 1, right, root->right);
		}
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()){ return NULL; }
		int psize = 0;
		TreeNode* root = NULL;
		dfsbuild(preorder, inorder, psize, 0, preorder.size() - 1, root);
		return root;
	}
};