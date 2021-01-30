#include"BinaryTree.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreePrevOrder((*root)->left);
	BinaryTreePrevOrder((*root)->right);
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1+BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}
	printf("%c\n", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	printf("%c\n", root->val);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c\n", root->val);
}
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);