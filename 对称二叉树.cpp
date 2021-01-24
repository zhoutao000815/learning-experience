//101. 对称二叉树
//给定一个二叉树，检查它是否是镜像对称的。
//
//
//
//例如，二叉树[1, 2, 2, 3, 4, 4, 3] 是对称的。
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//
//
//但是下面这个[1, 2, 2, null, 3, null, 3] 则不是镜像对称的:
//
//1
/// \
//2   2
//\   \
//3    3
//
//
//进阶：
//
//你可以运用递归和迭代两种方法解决这个问题吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/symmetric-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isleft_right(struct TreeNode* lefttree, struct TreeNode* righttree)
{
	if (lefttree == NULL && righttree == NULL)
	{
		return true;
	}
	if ((lefttree == NULL && righttree != NULL) || (righttree == NULL && lefttree != NULL) || (lefttree->val != righttree->val))
	{
		return false;
	}

	return isleft_right(lefttree->left, righttree->right) && isleft_right(righttree->left, lefttree->right);
}
bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}
	return isleft_right(root->left, root->right);
}