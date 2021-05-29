//剑指 Offer 55 - II.平衡二叉树
//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
//
//
//示例 1:
//
//给定二叉树[3, 9, 20, null, null, 15, 7]
//
//3
/// \
//9  20
/// \
//15   7
//返回 true 。
//
//示例 2:
//
//给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]
//
//1
/// \
//2   2
/// \
//3   3
/// \
//4   4
//返回 false 。
//
//
//限制：
//
//0 <= 树的结点个数 <= 10000
//
//
//
//限制：
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//方法一:从上到下，求左子树深度，右子树深度，判断绝对差值。
// 每一次向下递归，都会重复求下面的深度。

//方法二：后序递归，顺便记录子树深度返回给上一层，用于比较。

// class Solution {
// public:
//     int tree_deepth(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
//         int left_deepth=tree_deepth(root->left);
//         int right_deepth=tree_deepth(root->right);
//         return max(left_deepth,right_deepth)+1;
//     }

//     bool isBalanced(TreeNode* root) {
//         if(root==NULL)
//         {
//             return true;
//         }
//         int left_deepth=tree_deepth(root->left);
//         int right_deepth=tree_deepth(root->right);
//         if(abs(left_deepth-right_deepth)>1)
//             return false;
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
// };

class Solution {
public:
	bool _is_balanced(TreeNode* root, int &high)
	{
		if (root == NULL)
		{
			return true;
		}
		int left_high = 0, right_high = 0;
		int left_tree = _is_balanced(root->left, left_high);
		int right_tree = _is_balanced(root->right, right_high);
		if (abs(left_high - right_high)>1)
			return false;
		high = max(left_high, right_high) + 1;
		return left_tree && right_tree;
	}

	bool isBalanced(TreeNode* root) {
		int high = 0;
		return _is_balanced(root, high);
	}
};