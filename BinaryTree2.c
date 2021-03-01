#include"BinaryTree.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//*pi表示一个二叉树的头节点起始
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

// 二叉树销毁
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
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1+BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
// 二叉树叶子节点个数
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
// 二叉树第k层节点个数
//采用分治算法，第K层是整个树的第一层往下的第K层，是第二层往下的第K-1层，是第三层往下的第K-2层，依次类推，直到K==1时，为空返回0，不为空则返回1，
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
// 二叉树查找值为x的节点
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
	printf("该树中不存在%c",x);
	return NULL;
}
//求二叉树的最大深度
int maxDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		//采用后序、利用返回值、能避免再次求子树的深度，节约栈开销，防止栈溢出。
		int maxleft = maxDepth(root->left);
		int maxright = maxDepth(root->right);
		int max = (maxleft > maxright ? maxleft : maxright) + 1;
		return max;
		//如果用下面这种方式，问号得出真假值后，没有保存值，再赋值的时候会重复求子树的深度。
		//return max=(maxDepth(root->left)>maxDepth(root->right)?maxDepth(root->left):maxDepth(root->right))+1;
	}
}
// 二叉树前序遍历 
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
// 二叉树中序遍历
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
// 二叉树后序遍历
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
// 层序遍历
//利用队列先进先出的特性，
//第一个父节点进队列之后开始：出一个节点，入队列他的非空子节点，直到队列为空，
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
// 判断二叉树是否是完全二叉树
//基于层序遍历，将空子节点也入队列，当第一个空子节点出现时跳出，开始检测队列剩下的节点，如果全是空说明是完全二叉树。反之不是
int BinaryTreeComplete(BTNode* root)
{
	Queue TreeCompleteQueue;
	QueueInit(&TreeCompleteQueue);
	if (root == NULL)
	{
		printf("完全二叉树(空树)\n");
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
			printf("非完全二叉树\n");
			return 0;
		}
	}
	QueueDestroy(&TreeCompleteQueue);
	printf("完全二叉树\n");
	return 1;
}