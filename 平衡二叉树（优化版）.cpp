//博客链接：
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//110. 平衡二叉树
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//
//
//示例 1：
//
//
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//示例 2：
//
//
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false
//示例 3：
//
//输入：root = []
//输出：true
//
//
//提示：
//
//树中的节点数在范围[0, 5000] 内
//- 104 <= Node.val <= 104
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/balanced-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int TreeDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	int Depth = leftDepth>rightDepth ? leftDepth : rightDepth;
	return Depth + 1;
}
bool My_isBalanced(struct TreeNode* root, int *Depth){

	if (root == NULL)
	{
		*Depth = 0;
		return true;
	}
	else
	{
		int leftDepth = 0;
		if (My_isBalanced(root->left, &leftDepth) == false)
		{
			return false;
		}
		int rightDepth = 0;
		if (My_isBalanced(root->right, &rightDepth) == false)
		{
			return false;
		}
		if (abs(leftDepth - rightDepth)>1)
		{
			return false;
		}
		*Depth = leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
}

bool isBalanced(struct TreeNode* root){
	//方法一：前序遍历求子树高度相比较。时间复杂度区间【O（N），O（N²）】
	//求子树的高度的时候，会重复计算高度。
	/*if(root==NULL)
	{
	return true;
	}
	int leftDepth=TreeDepth(root->left);
	int rightDepth=TreeDepth(root->right);
	if(leftDepth-rightDepth>1 || leftDepth-rightDepth<-1)
	{
	return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);*/

	//方法二：后序遍历 优化了时间复杂度
	//用一个int指针存储深度，从叶子节点开始计算高度，返回子树高度+1计算高度。
	int Depth = 0;
	return My_isBalanced(root, &Depth);
}


