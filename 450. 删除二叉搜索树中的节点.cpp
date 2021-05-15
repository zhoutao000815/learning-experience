//450. 删除二叉搜索树中的节点
//给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//
//一般来说，删除节点可分为两个步骤：
//
//首先找到需要删除的节点；
//如果找到了，删除它。
//说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
//
//示例 :
//
//root = [5, 3, 6, 2, 4, null, 7]
//key = 3
//
// 5
/// \
//3   6
/// \   \
//2   4   7
//
//给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
//
//一个正确的答案是[5, 4, 6, 2, null, null, 7], 如下图所示。
//
// 5
/// \
//4   6
///     \
//2       7
//
//另一个正确答案是[5, 2, 6, null, 4, null, 7]。
//
//  5
///  \
//2   6
//\    \
// 4     7
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/delete-node-in-a-bst
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
typedef TreeNode node;
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		//1.叶子节点
		//2.左为空、或右为空。
		//3.左右都不为空
		node* parents = nullptr;
		node*cur = root;
		while (cur)
		{
			if (cur->val < key)
			{
				parents = cur;
				cur = cur->right;
			}
			else if (cur->val>key)
			{
				parents = cur;
				cur = cur->left;
			}
			else
			{
				//叶子节点可以看作其中一方为空，
				if (cur->left == nullptr)
				{
					if (cur == root)
					{
						root = cur->right;
					}
					else
					{
						if (cur == parents->left)
						{
							parents->left = cur->right;
						}
						else
						{
							parents->right = cur->right;
						}
					}
					delete cur;
					return root;
				}
				else if (cur->right == nullptr)
				{
					if (cur == root)
					{
						root = cur->left;
					}
					else
					{
						if (cur == parents->left)
						{
							parents->left = cur->left;
						}
						else
						{
							parents->right = cur->left;
						}
					}
					delete cur;
					return root;
				}
				else  //左右都有孩子
				{
					//替代法删除:直接删会破坏搜索树的结构
					//用左子树的最大节点，或者，右子树的最小节点，去替代删除。
					//其次：删除节点可能是左或右子树的根。要判断

					//用左子树的最大节点替代
					node* smparents = cur;
					node* left_sub_max = cur->left;
					while (left_sub_max->right)
					{
						smparents = left_sub_max;
						left_sub_max = left_sub_max->right;
					}

					if (left_sub_max == smparents->left)
					{
						smparents->left = left_sub_max->left;
					}
					else
					{
						smparents->right = left_sub_max->left;
					}
					cur->val = left_sub_max->val;
					delete left_sub_max;
					return root;
				}
			}
		}
		return root;
	}
};