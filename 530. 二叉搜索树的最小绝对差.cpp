//530. ��������������С���Բ�
//����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ�����������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��
//
//
//
//ʾ����
//
//���룺
//
//1
//\
//3
///
//2
//
//�����
//1
//
//���ͣ�
//��С���Բ�Ϊ 1������ 2 �� 1 �Ĳ�ľ���ֵΪ 1������ 2 �� 3����
//
//
//��ʾ��
//
//���������� 2 ���ڵ㡣
//������ 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ ��ͬ
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
//����һ�������������Ƚⷨ�������Ƚ�˼�룬дһ����������ÿ�����ڵ����������������ڵ���бȽϣ�
//�ٽ�ԭ�������������ĸ��ڵ㴫��ȥ��������������� 
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
//         if(root!=prev)       //�����Լ����Լ��Ƚϡ�
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

//�ⷨ�������ö��������������ʣ������������ģ��Ƚ���������У�����С�����ֵ�����ڵıȽϼ��ɡ�
class Solution {
public:
	void dfs(TreeNode* root, int& prev, int& res)
	{
		if (root == nullptr)
		{
			return;
		}
		dfs(root->left, prev, res);
		if (prev == -1)                  //�ߵ�����˵���ߵ��������
		{
			prev = root->val;
		}
		else
		{
			res = min(res, root->val - prev);
			prev = root->val;           //����prev
		}
		dfs(root->right, prev, res);
	}

	int getMinimumDifference(TreeNode* root)
	{
		int res = INT_MAX, prev = -1;    //��Ϊ����Ϊ�Ǹ���������Ҫ���ߵ�����ߣ����Ա������߽ڵ�ֵΪ-1��
		dfs(root, prev, res);
		return res;
	}
};

