#include"BinaryTree.h"
int main()
{
	char arr[] = { "ABD##E#H##CF##G##" };
	int begin = 0;
	BTNode *tree = BinaryTreeCreate(arr, sizeof(arr)-1, &begin);
	printf("�ڵ������%d\n", BinaryTreeSize(tree));
	
	printf("Ҷ�ӽڵ������%d\n", BinaryTreeLeafSize(tree));
	
	printf("������ڵ������%d\n", BinaryTreeLevelKSize(tree,3));
	
	printf("�����ȣ�%d\n", maxDepth(tree));
	
	BinaryTreeLevelOrder(tree);

	BinaryTreePostOrder(tree);

	BinaryTreeComplete(tree);
	system("pause");
}