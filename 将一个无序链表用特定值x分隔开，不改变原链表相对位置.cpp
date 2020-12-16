#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//题目描述
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
//解题思路：
//直接将原链表分组形成新的两组链表，
//一组是小于x的放在head1，一组是大于等于的放在head2，
//最后将（head1的尾巴）和（head2的头部的下一个）连接起来。将head2的尾巴置NULL，
//找到realhead，并返回。
ListNode* partition(ListNode* pHead, int x) {
		ListNode *head1 = (ListNode *)malloc(sizeof(ListNode));
		if (head1)
		{
			head1->next = NULL;
		}
		ListNode *head2 = (ListNode *)malloc(sizeof(ListNode));
		if (head2)
		{
			head2->next = NULL;
		}
		ListNode *tail1 = head1;
		ListNode *tail2 = head2;
		while (pHead)
		{
			if (pHead->val >= x)
			{
				tail2->next = pHead;
				tail2 = tail2->next;
				pHead = pHead->next;
			}
			else
			{
				tail1->next = pHead;
				tail1 = tail1->next;
				pHead = pHead->next;
			}
		}
		tail2->next = NULL;
		tail1->next = head2->next;
		ListNode *realhead = head1->next;
		free(head1);
		free(head2);
		return realhead;
	};
	int main()
	{
		ListNode*n6 = (ListNode*)malloc(sizeof(ListNode));
		if (n6)
		{
			n6->val = 555;
			n6->next = NULL;
		}
		ListNode*n5 = (ListNode*)malloc(sizeof(ListNode));
		if (n5)
		{
			n5->val = 666;
			n5->next = n6;
		}
		ListNode*n4 = (ListNode*)malloc(sizeof(ListNode));
		if (n4)
		{
			n4->val = 777;
			n4->next = n5;
		}
		ListNode*n3 = (ListNode*)malloc(sizeof(ListNode));
		if (n3)
		{
			n3->val = 222;
			n3->next = n4;
		}
		ListNode*n2 = (ListNode*)malloc(sizeof(ListNode));
		if (n2)
		{
			n2->val = 333;
			n2->next = n3;
		}
		ListNode*pHead = (ListNode*)malloc(sizeof(ListNode));
		if (pHead)
		{
			pHead->val = 444;
			pHead->next = n2;
		}
		int x = 555;
		ListNode*n = partition(pHead, x);
		while (n)
		{
			printf("%4d->", n->val);
			n = n->next;
		}
		printf("NULL\n");
		system("pause");
	}