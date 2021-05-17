//剑指 Offer 68 - II.二叉树的最近公共祖先
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//例如，给定如下二叉树 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//
//
//
//
//
//			 示例 1:
//
//输入 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//输出 : 3
// 解释 : 节点 5 和节点 1 的最近公共祖先是节点 3。
//	  示例 2 :
//
//  输入 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
//   输出 : 5
//	解释 : 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//
//
//	 说明 :
//
//	 所有节点的值都是唯一的。
//		 p、q 为不同节点且均存在于给定的二叉树中。
//		 注意：本题与主站 236 题相同：https ://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
//
//
//
//		 来源：力扣（LeetCode）
//	 链接：https ://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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
	//方法一：
	//当前节点是否为pq是，那么当前根节点就是公共祖先。
	//在左右子树里找节点pq在不在，
	//如果qp都在左（或右）子树里，那就递归左（或右）子树里找。
	//直到p，q分别在左右子树里，那么这个根节点就是最近公共祖先。

	//时间复杂度:单边树情况下：寻找pq在不在子树就是一个o（N）的复杂度，如果pq的公共节点很深，再递归就是O(N²)
	//下面第二种方法给出优化
	// bool find(TreeNode* root, TreeNode* target)
	// {
	//     if(root==NULL)
	//     {
	//         return false;
	//     }
	//     if(root==target)
	//     {
	//         return true;
	//     }
	//     else
	//     {
	//         return find(root->left,target) || find(root->right,target);
	//     }
	// }

	// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	//     if(root==p || root==q)
	//     {
	//         return root;
	//     }

	//     bool p_in_left,p_in_right,q_in_left,q_in_right;
	//     p_in_left=find(root->left,p);
	//     p_in_right=!p_in_left;
	//     q_in_left=find(root->left,q);
	//     q_in_right=!q_in_left;

	//     if((p_in_left && q_in_right) || (p_in_right && q_in_left))
	//     {
	//         return root;
	//     }
	//     else if(p_in_left && q_in_left)
	//     {
	//         return lowestCommonAncestor(root->left, p, q);
	//     }
	//     else
	//     {
	//         return lowestCommonAncestor(root->right, p, q);
	//     }
	// }

	//方法二：
	//如果有指向parents的节点指针，我们可以直接通过pq向上寻找，此题就转换为，寻找两个相交链表的第一个公共节点。
	//但是没有parents指针，所以我们从根往下找pq，用栈记录路径。
	//由于节点值是不重复的，通过栈里的节点存的val，找到第一个值相同的节点，就是公共节点

	//时间复杂度:用空间换时间，栈记录路径，一次找到，O（N），遍历栈寻找公共节点O(N)，加起来O(2N)=O(N)。
	bool get_ways_of_child_node(stack<TreeNode*> & st, TreeNode* target)
	{
		if (st.top() == NULL)
		{
			return false;
		}
		if (st.top() == target)
		{
			return true;
		}

		st.push(st.top()->left);
		if (get_ways_of_child_node(st, target)) //左子树找到就返回
			return true;
		st.pop();                             //左子树没找到，出栈。
		st.push(st.top()->right);             //右子树入栈
		if (get_ways_of_child_node(st, target)) //右子树找到就返回
			return true;
		st.pop();                             //没找到，出栈。
		return false;                         //返回假。
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == p || root == q)
		{
			return root;
		}

		stack<TreeNode*> pstack;
		stack<TreeNode*> qstack;
		pstack.push(root);
		qstack.push(root);
		get_ways_of_child_node(pstack, p);
		get_ways_of_child_node(qstack, q);

		while (pstack.size() != qstack.size())
		{
			if (pstack.size()>qstack.size())
			{
				pstack.pop();
			}
			else
			{
				qstack.pop();
			}
		}

		while (pstack.top() != qstack.top()) //由于一定能找到公共节点，不必限制判空。如果改题不一定能找到，则判断为空就无。
		{
			pstack.pop();
			qstack.pop();
		}
		return qstack.top();
	}
};