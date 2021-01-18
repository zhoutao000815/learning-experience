//博客链接：
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//572. 另一个树的子树
//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//
//示例 1:
//给定的树 s :
//
//3
/// \
//4   5
/// \
//1   2
//给定的树 t：
//
//4
/// \
//1   2
//返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
//示例 2:
//给定的树 s：
//
//3
/// \
//4   5
/// \
//1   2
///
//0
//给定的树 t：
//
//4
/// \
//1   2
//返回 false。

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/subtree-of-another-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL && q != NULL)
	{
		return false;
	}
	if (p != NULL && q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL && t == NULL)
	{
		return true;
	}
	if (s == NULL && t != NULL)
	{
		return false;
	}
	if (s != NULL && t == NULL)
	{
		return false;
	}
	if (isSameTree(s, t))
	{
		return true;
	}

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}