//199. 二叉树的右视图
//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//
//示例 :
//
//输入 : [1, 2, 3, null, 5, null, 4]
//输出 : [1, 3, 4]
// 解释 :
//
//	1            <-- -
//	/ \
//	2     3         <-- -
//	\     \
//	5     4       <-- -
//
//	/ \
//	2     3         <-- -
//	\     \
//	5     4       <-- -
//
//
//	来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-right-side-view
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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

//将二叉树层序遍历的每层最后一个节点的值保存入vector。
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> rel;
		if (root == nullptr)
			return rel;

		int levelsize = 1;
		queue<TreeNode*> qtreenode;
		qtreenode.push(root);
		while (!qtreenode.empty())
		{
			while (levelsize>0)
			{
				TreeNode* curnode = qtreenode.front();
				qtreenode.pop();
				if (levelsize == 1)
					rel.push_back(curnode->val);
				levelsize--;
				if (curnode->left)
					qtreenode.push(curnode->left);
				if (curnode->right)
					qtreenode.push(curnode->right);
			}
			levelsize = qtreenode.size();
		}
		return rel;
	}
};