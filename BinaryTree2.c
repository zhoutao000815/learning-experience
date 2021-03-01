#include"BinaryTree.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//*pi��ʾһ����������ͷ�ڵ���ʼ
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' && *pi < n)
	{
		(*pi)++;
		return NULL;
	}
	else
	{
		BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
		cur->val = a[*pi];
		(*pi)++;
		cur->left = BinaryTreeCreate(a, n, pi);
		cur->right = BinaryTreeCreate(a, n, pi);
		return cur;
	}
}

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
//���÷����㷨����K�����������ĵ�һ�����µĵ�K�㣬�ǵڶ������µĵ�K-1�㣬�ǵ��������µĵ�K-2�㣬�������ƣ�ֱ��K==1ʱ��Ϊ�շ���0����Ϊ���򷵻�1��
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	BTNode *find = BinaryTreeFind(root->left, x);
	if (find != NULL)
	{
		return  find;
	}
	find = BinaryTreeFind(root->right, x);
	if (find != NULL)
	{
		return  find;
	}
	printf("�����в�����%c",x);
	return NULL;
}
//���������������
int maxDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		//���ú������÷���ֵ���ܱ����ٴ�����������ȣ���Լջ��������ֹջ�����
		int maxleft = maxDepth(root->left);
		int maxright = maxDepth(root->right);
		int max = (maxleft > maxright ? maxleft : maxright) + 1;
		return max;
		//������������ַ�ʽ���ʺŵó����ֵ��û�б���ֵ���ٸ�ֵ��ʱ����ظ�����������ȡ�
		//return max=(maxDepth(root->left)>maxDepth(root->right)?maxDepth(root->left):maxDepth(root->right))+1;
	}
}
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
//���ö����Ƚ��ȳ������ԣ�
//��һ�����ڵ������֮��ʼ����һ���ڵ㣬��������ķǿ��ӽڵ㣬ֱ������Ϊ�գ�
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue Qtree;
	QueueInit(&Qtree);
	if (root == NULL)
	{
		return;
	}
	QueuePush(&Qtree, root);
	while (!QueueEmpty(&Qtree))
	{
		BTNode *front = QueueFront(&Qtree);
		QueuePop(&Qtree);
		printf(" %c ", front->val);
		if (front->left != NULL)
		{
			QueuePush(&Qtree, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&Qtree, front->right);
		}
	}
	QueueDestroy(&Qtree);
	printf("\n");
}
// �ж϶������Ƿ�����ȫ������
//���ڲ�������������ӽڵ�Ҳ����У�����һ�����ӽڵ����ʱ��������ʼ������ʣ�µĽڵ㣬���ȫ�ǿ�˵������ȫ����������֮����
int BinaryTreeComplete(BTNode* root)
{
	Queue TreeCompleteQueue;
	QueueInit(&TreeCompleteQueue);
	if (root == NULL)
	{
		printf("��ȫ������(����)\n");
		return 0;
	}
	QueuePush(&TreeCompleteQueue, root);
	while (!QueueEmpty(&TreeCompleteQueue))
	{
		BTNode *front = QueueFront(&TreeCompleteQueue);
		QueuePop(&TreeCompleteQueue);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&TreeCompleteQueue, front->left);
		QueuePush(&TreeCompleteQueue, front->right);
	}
	while (!QueueEmpty(&TreeCompleteQueue))
	{
		BTNode *front = QueueFront(&TreeCompleteQueue);
		QueuePop(&TreeCompleteQueue);
		if (front != NULL)
		{
			printf("����ȫ������\n");
			return 0;
		}
	}
	QueueDestroy(&TreeCompleteQueue);
	printf("��ȫ������\n");
	return 1;
}