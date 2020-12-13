#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//输入一个链表，输出该链表中倒数第k个结点。
//示例1
//输入
//1, { 1, 2, 3, 4, 5 }
//返回值
//{ 5 }

//快慢双指针法，都指向头节点。
//然后快指针走k步，记录长度len++，如果len不等于k，说明k>链表长度，返回空。
//len=k，则快慢指针再一次一步一步走，当快指针走到尾NULL。慢指针指向的就是倒数第k个。
 struct ListNode {
	int val;
	struct ListNode *next;
 };

typedef struct ListNode ListNode;
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	int len = 0;
	int Kcopy = k;
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;
	while (fast)
	{
		if (Kcopy--)
		{
			fast = fast->next;
			len++;
		}
		else
		{
			break;
		}
	}
	if (len != k)
	{
		return NULL;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
int main()
{
	ListNode*n3 = (ListNode*)malloc(sizeof(ListNode));
	if (n3)
	{
		n3->val = 999;
		n3->next = NULL;
	}
	ListNode*n2 = (ListNode*)malloc(sizeof(ListNode));
	if (n2)
	{
		n2->val = 666;
		n2->next = n3;
	}
	ListNode*pListHead = (ListNode*)malloc(sizeof(ListNode));
	if (pListHead)
	{
		pListHead->val = 111;
		pListHead->next = n2;
	}
	int k = 1;
	ListNode*n = FindKthToTail(pListHead, k);
	printf("%d\n", n->val);
	system("pause");
}