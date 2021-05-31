//剑指 Offer 33. 二叉搜索树的后序遍历序列
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
//
//
//
//参考以下这颗二叉搜索树：
//
//5
/// \
//2   6
/// \
//1   3
//示例 1：
//
//输入 : [1, 6, 3, 2, 5]
// 输出 : false
//	  示例 2：
//
//  输入 : [1, 3, 2, 6, 5]
//   输出 : true
//
//
//		来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//思路：二叉搜索树的后序序列中，倒数第一个数据一定是根节点，根据根节点大小和二叉搜索树特性，分出左右子树。
//判断子树是否满足二叉搜索树的特性，
class Solution {
public:
	bool _verifyPostorder(vector<int>& postorder, int begin, int end)
	{
		if (begin == end)
		{
			return true;
		}
		int i;
		for (i = end; i >= begin; i--)
		{
			if (postorder[i]<postorder[end]) //找到第一个比树根小的节点，就是左子树根，左子树：[begin,i] 右子树：[i+1,end-1] 
			{
				break;
			}
		}

		int lbegin = begin;
		int lend = i;
		int rbegin = i + 1;
		int rend = end - 1;
		if (i<begin)  //左子树可能为空，左树为空时，为了简化代码，都赋于begin，下次递归直接返回。
			lbegin = lend = begin;
		if (rbegin == end) //右子树可能为空，右树为空时，也赋给相同的值
			rend = end;

		//lend是第一个比根小的，右树已经判断过了，来确认左子树
		//如果左子树内存在比根还大的，说明不是二叉搜索树。
		for (int j = lbegin; j<lend; j++)
		{
			if (postorder[j]>postorder[end])
			{
				return false;
			}
		}

		return _verifyPostorder(postorder, lbegin, lend) && _verifyPostorder(postorder, rbegin, rend);
	}

	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() <= 1)
		{
			return true;
		}
		return _verifyPostorder(postorder, 0, postorder.size() - 1);
	}
};