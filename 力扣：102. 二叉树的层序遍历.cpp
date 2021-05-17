//102. 二叉树的层序遍历
//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
//
//
//
//示例：
//二叉树：[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//返回其层序遍历结果：
//
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]
//
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-level-order-traversal
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

//此题要求从顶到底，如果要求从底到顶，直接逆置一下数组rel即可。
class Solution {
public:
	//方法一：用一个leversize去记录每层节点个数，一层一层出。    
	//直到一层出完再下一层出的时候也按levelsize出，即，直到levelsize为0.
	//出节点的同时，将该节点的左右孩子入队列，
	//当一层出完，队列里的节点个数，就是下一层的节点个数，更新，然后出下一层。
	//直到队列为空结束。
	 vector<vector<int>> levelOrder(TreeNode* root) {
	     vector<vector<int>> rel;
	     if(root==nullptr)
	     {
	         return rel;
	     }
	     queue<TreeNode*> q;
	     q.push(root);
	     int levelsize=1;
	     while(!q.empty())
	     {
	         vector<int> tmp;
	         while(levelsize)
	         {
	             TreeNode* node=q.front();
	             q.pop();
	             levelsize--;

	             if(node==nullptr)
	             {
	                 continue;
	             }
	             q.push(node->left);
	             q.push(node->right);
	             tmp.push_back(node->val);
	         }
	         if(!tmp.empty())
	             rel.push_back(tmp);
	         levelsize=q.size();   //此时队列里的节点个数，就是下一层的节点个数
	     }
	     return rel;
	 }


	//方法二：用两个队列，一个存储节点，一个存储节点对应的层数，（1，，2，2，，3，3，3，3）
	//节点层数++了，就开一个新vector<int>存下一层。
	// vector<vector<int>> levelOrder(TreeNode* root) {
	//     vector<vector<int>> rel;
	//     if(root==nullptr)
	//     {
	//         return rel;
	//     }
	//     queue<TreeNode*> qnode;
	//     queue<int> qlevel;
	//     qnode.push(root);
	//     qlevel.push(1);

	//     vector<int> tmp;
	//     while(!qnode.empty())
	//     {
	//         TreeNode* node=qnode.front();
	//         int level=qlevel.front();
	//         qlevel.pop();
	//         qnode.pop();

	//         if(node->left)           //根节点此时一定不为nullptr，保证孩子不是，qnode里就没有空节点
	//         {
	//             qnode.push(node->left);
	//             qlevel.push(level+1);
	//         }

	//         if(node->right)
	//         {
	//             qnode.push(node->right);
	//             qlevel.push(level+1);
	//         }

	//         tmp.push_back(node->val);
	//         if(level<qlevel.front() || qlevel.empty())  //节点层数增加了 || 最后一层没有增加了，处理层数数组 tmp
	//         {
	//             rel.push_back(tmp);
	//             tmp.clear();
	//         }
	//     }
	//     return rel;
	// }

	//方法三:用两个vector<TreeNode*>，cur层，next层去模拟一层一层出。
	//cur层的孩子入next层，直到cur层完，交换cur层和next层。
	//直到cur层为空
	//vector<vector<int>> levelOrder(TreeNode* root) {
	//	vector<vector<int>> rel;
	//	if (root == nullptr)
	//	{
	//		return rel;
	//	}

	//	vector<TreeNode*> cur(1, root);
	//	vector<TreeNode*> next;

	//	while (!cur.empty())
	//	{
	//		vector<int> tmp;
	//		for (size_t i = 0; i<cur.size(); i++)
	//		{
	//			tmp.push_back(cur[i]->val);
	//			if (cur[i]->left)
	//			{
	//				next.push_back(cur[i]->left);
	//			}
	//			if (cur[i]->right)
	//			{
	//				next.push_back(cur[i]->right);
	//			}
	//		}
	//		rel.push_back(tmp);

	//		//cur=next;      //赋值运算符重载，深拷贝，浪费效率，C++11解决了这个问题
	//		//next.clear();

	//		cur.swap(next);  //交换指针指向。
	//		next.clear();
	//	}
	//	return rel;
	//}
};