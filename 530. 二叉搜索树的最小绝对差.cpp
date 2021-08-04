//530. 二叉搜索树的最小绝对差
//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
//
//示例：
//
//输入：
//
//1
//\
//3
///
//2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
//
//
//提示：
//
//树中至少有 2 个节点。
//本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
//


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
//方法一：暴力法：笨比解法，挨个比较思想，写一个函数，将每个根节点与他的所有子树节点进行比较；
//再将原树的所有子树的根节点传进去，调用这个函数。 
// class Solution {
// private:
//     int res=INT_MAX;
// public:
//     void get_min(TreeNode* root,TreeNode* prev)
//     {
//         if(prev==nullptr)
//         {
//             return ;
//         }
//         if(root!=prev)       //不能自己和自己比较。
//         {
//             int tmp=abs(prev->val-root->val);
//             if(tmp<res)
//             {
//                 res = tmp;
//             }
//         }
//         get_min(root,prev->left);
//         get_min(root,prev->right);
//     }

//     int getMinimumDifference(TreeNode* root) {
//         if(root==nullptr)
//         {
//             return res;
//         }
//         get_min(root,root);
//         getMinimumDifference(root->left);
//         getMinimumDifference(root->right);
//         return res;
//     }
// };

//解法二：利用二叉搜索树的性质，中序就是有序的，比较有序的数列，求最小差绝对值，相邻的比较即可。
class Solution {
public:
	void dfs(TreeNode* root, int& prev, int& res)
	{
		if (root == nullptr)
		{
			return;
		}
		dfs(root->left, prev, res);
		if (prev == -1)                  //走到这里说明走到了最左边
		{
			prev = root->val;
		}
		else
		{
			res = min(res, root->val - prev);
			prev = root->val;           //更新prev
		}
		dfs(root->right, prev, res);
	}

	int getMinimumDifference(TreeNode* root)
	{
		int res = INT_MAX, prev = -1;    //因为数字为非负数，并且要先走到最左边，所以标记最左边节点值为-1，
		dfs(root, prev, res);
		return res;
	}
};

