//博客链接：https://blog.csdn.net/Zhou000815/article/details/112727017
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//144. 二叉树的前序遍历
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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
//提示：
//
//树中节点数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//
//
//进阶：递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。、

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void preorder(struct TreeNode* root, int* returnSize, int *returnarr)
{
	if (root == NULL)
	{
		return;
	}
	returnarr[(*returnSize)++] = root->val;
	preorder(root->left, returnSize, returnarr);
	preorder(root->right, returnSize, returnarr);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	if (root == NULL)
	{
		return NULL;
	}
	int *returnarr = (int *)malloc(sizeof(int)* 100);
	preorder(root, returnSize, returnarr);
	return returnarr;
}

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
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//	来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
void inorder(struct TreeNode* root, int* returnSize, int *returnarr)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left, returnSize, returnarr);
	returnarr[(*returnSize)++] = root->val;
	inorder(root->right, returnSize, returnarr);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	if (root == NULL)
	{
		return NULL;
	}
	int *returnarr = (int *)malloc(sizeof(int)* 100);
	inorder(root, returnSize, returnarr);
	return returnarr;
}
//145. 二叉树的后序遍历
//给定一个二叉树，返回它的 后序 遍历。
//
//示例 :
//
//输入:[1, null, 2, 3]
//   1
//   \
//   2
//   /
//   3
//
//输出:[3, 2, 1]
//进阶 : 递归算法很简单，你可以通过迭代算法完成吗？
//
//	 来源：力扣（LeetCode）
// 链接：https ://leetcode-cn.com/problems/binary-tree-postorder-traversal
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
void postorder(struct TreeNode* root, int* returnSize, int *returnarr)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left, returnSize, returnarr);
	postorder(root->right, returnSize, returnarr);
	returnarr[(*returnSize)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	if (root == NULL)
	{
		return NULL;
	}
	int *returnarr = (int *)malloc(sizeof(int)* 100);
	postorder(root, returnSize, returnarr);
	return returnarr;
}