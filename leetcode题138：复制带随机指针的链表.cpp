//此题较难理解：写了一篇博客，可以参考一下。链接：
#include<Windows.h>
#include<stdio.h>
#include <assert.h>
#pragma warning (disable:4996)
//138. 复制带随机指针的链表
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//
//要求返回这个链表的 深拷贝。
//
//我们用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。每个节点用一个[val, random_index] 表示：
//
//val：一个表示 Node.val 的整数。
//random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为  null 。
//
//
//示例 1：
//输入：head = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]--------后面的数字代表从0开始的下标
//输出：[[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//力扣链接:https://leetcode-cn.com/problems/copy-list-with-random-pointer/
struct Node {
	int val;
	struct Node *next;
	struct Node *random;
};
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
	{
		return NULL;
	}
	//1.将复制的每一个节点接在原节点之后，想想为什么这么做?
	//由于复制的节点是malloc出来的，地址是不同于原链表的，random也要是复制链表的随机节点。
	//如果没有random，是可以用带头节点直接复制的。
	//由于随机地址是无法确定的，只能通过val来寻找，val存在相等的可能，复制random时会出错，
	//即使没有相同的val，每次复制fandom时，在复制的链表上查找val，时间复杂度变为O（n²）。
	//所以采用这种先复制拼接，然后断开重新链接的方法。
	Node* cur = head;
	Node* next = head->next;
	while (cur)
	{
		Node*copyNode = (Node*)malloc(sizeof(Node));
		if (copyNode != NULL)
		{
			copyNode->val = cur->val;
			copyNode->random = NULL;
			copyNode->next = NULL;
		}
		if (next != NULL)
		{
			copyNode->next = next;
			cur->next = copyNode;
			cur = next;
			next = next->next;
		}
		else
		{
			copyNode->next = next;
			cur->next = copyNode;
			cur = next;
		}
	}
	//2.完成复制节点的random，复制节点的random就是原结点的random的下一个。
	cur = head;
	next = head->next;
	while (cur)
	{
		if (cur->random != NULL)
		{
			next->random = cur->random->next;
		}
		else
		{
			next->random = NULL;
		}
		cur = next->next;
		if (cur != NULL)
		{
			next = cur->next;
		}

	}
	//3.断开重新分配，还原原链表和复制链表。
	cur = head;
	next = head->next;
	Node*copyhead = next;
	while (cur)
	{
		cur->next = next->next;
		cur = cur->next;
		if (cur != NULL)
		{
			next->next = cur->next;
			next = cur->next;
		}
		else
		{
			next->next = cur;
		}

	}
	return copyhead;
}
int main()
{
	Node*n6 = (Node*)malloc(sizeof(Node));
	if (n6)
	{
		n6->val = 66;
		n6->next =NULL;		
	}
	Node*n5 = (Node*)malloc(sizeof(Node));
	if (n5)
	{
		n5->val = 55;
		n5->next = n6;

	}
	Node*n4 = (Node*)malloc(sizeof(Node));
	if (n4)
	{
		n4->val = 44;
		n4->next = n5;
	
	}
	Node*n3 = (Node*)malloc(sizeof(Node));
	if (n3)
	{
		n3->val = 33;
		n3->next = n4;

	}
	Node*n2 = (Node*)malloc(sizeof(Node));
	if (n2)
	{
		n2->val = 22;
		n2->next = n3;

	}
	Node*head = (Node*)malloc(sizeof(Node));
	if (head)
	{
		head->val = 11;
		head->next = n2;
	
	}
	n6->random = n3;
	n5->random = n2;
	n4->random = n4;
	n2->random = n6;
	n3->random = NULL;
	head->random = n3; 
	Node* list = head;
	while (head)
	{
		printf("%10d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
	head = list;
	while (head)
	{
		printf("%10p->", head);
		head = head->next;
	}
	printf("NULL\n");
	head = list;
	while (head)
	{
		printf("%10p--", head->random);
		head = head->next;
	}
	printf("NULL\n");
	head = list;
	Node* cpyNode = copyRandomList(head);
	Node* cpylist = cpyNode;
	while (cpyNode)
	{
		printf("%10d->", cpyNode->val);
		cpyNode = cpyNode->next;
	}
	printf("NULL\n");
	cpyNode = cpylist;
	while (cpyNode)
	{
		printf("%10p->", cpyNode);
		cpyNode = cpyNode->next;
	}
	printf("NULL\n");
	cpyNode = cpylist;
	while (cpyNode)
	{
		printf("%10p--", cpyNode->random);
		cpyNode = cpyNode->next;
	}
	printf("NULL\n");
	system("pause");
}