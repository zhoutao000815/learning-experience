//1382. 将二叉搜索树变平衡
//给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。
//
//如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
//
//如果有多种构造方法，请你返回任意一种。
//
//
//
//示例：
//
//
//
//输入：root = [1, null, 2, null, 3, null, 4, null, null]
//输出：[2, 1, 3, null, null, null, 4]
//解释：这不是唯一的正确答案，[3, 1, 4, null, 2, null, null] 也是一个可行的构造方案。
//
//
//提示：
//
//树节点的数目在 1 到 10 ^ 4 之间。
//树节点的值互不相同，且在 1 到 10 ^ 5 之间。

//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/balance-a-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//中序遍历（升序），再根据二叉平衡搜索树的特性（根节点是中位数），进行前序构造
class Solution {
public:
	void get_inorder(TreeNode* root, vector<int> &v)
	{
		if (root == NULL)
			return;
		get_inorder(root->left, v);
		v.push_back(root->val);
		get_inorder(root->right, v);
	}

	void build(TreeNode* &root, vector<int> &v, int left, int right)
	{
		if (left>right)
			return;
		int mid = (left + right) >> 1;
		root = new TreeNode(v[mid]);

		build(root->left, v, left, mid - 1);
		build(root->right, v, mid + 1, right);
	}

	TreeNode* balanceBST(TreeNode* root) {
		vector<int> v;
		get_inorder(root, v);
		build(root, v, 0, v.size() - 1);
		return root;
	}
};