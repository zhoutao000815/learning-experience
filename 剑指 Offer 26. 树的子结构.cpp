//剑指 Offer 26. 树的子结构
//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//
//B是A的子结构， 即 A中有出现和B相同的结构和节点值。
//
//例如 :
//给定的树 A :
//
//3
/// \
//4   5
/// \
//1   2
//给定的树 B：
//
//4
///
//1
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
//
//示例 1：
//
//输入：A = [1, 2, 3], B = [3, 1]
//输出：false
//示例 2：
//
//输入：A = [3, 4, 5, 1, 2], B = [4, 1]
//输出：true
//限制：
//
//0 <= 节点个数 <= 10000
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//判断B是不是A的子树，只要判断A的每一个子树，是不是与B具有相同值并且结构相同。

//注意：输入为层序遍历
// [10,12,6,8,3,11]
// [10,12,6,8]
//这个测试用例，虽然对应节点的值是相同的 && B是A的子结构，但是B并不是A的子树。所以不能用B是不是A的子树逻辑来判断，类似其他结构也是。
class Solution {
public:
	//子函数1：
	bool iscontain(TreeNode* A, TreeNode* B)
	{
		if (A == NULL && B != NULL)
			return false;
		if ((A == NULL && B == NULL) || (A != NULL && B == NULL))  //第二个括号里的条件为特例处理。
			return true;
		if (A->val != B->val)
			return false;

		//走到这一步代表(A->val==B->val)   再判断A和B的子结构。
		return iscontain(A->left, B->left) && iscontain(A->right, B->right);
	}

	//写的更简单一点看下面这个：子函数2
	// bool iscontain(TreeNode* A, TreeNode* B)
	// {
	//     if(B == NULL)
	//         return true;
	//     if(A == NULL || A->val != B->val)
	//         return false;
	//     return iscontain(A->left, B->left) && iscontain(A->right, B->right);
	// }

	//父函数
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;
		return iscontain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};