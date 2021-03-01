#include"BinaryTree.h"
int main()
{
	char arr[] = { "ABD##E#H##CF##G##" };
	int begin = 0;
	BTNode *tree = BinaryTreeCreate(arr, sizeof(arr)-1, &begin);
	printf("节点个数：%d\n", BinaryTreeSize(tree));
	
	printf("叶子节点个数：%d\n", BinaryTreeLeafSize(tree));
	
	printf("第三层节点个数：%d\n", BinaryTreeLevelKSize(tree,3));
	
	printf("最大深度：%d\n", maxDepth(tree));
	
	BinaryTreeLevelOrder(tree);

	BinaryTreePostOrder(tree);

	BinaryTreeComplete(tree);
	system("pause");
}