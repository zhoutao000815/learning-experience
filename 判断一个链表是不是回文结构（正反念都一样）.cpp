#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
struct ListNode {
	int val;
	struct ListNode *next;
}; 
typedef struct ListNode ListNode;
//解题思路
//方法一
//先算出链表长度，然后找到链表的下中间节点。（这里可以用快慢指针一个走一步，一个走两步找出中间节点）
//保存下中间节点，并且从下中间节点开始逆置，逆置结束后的尾tail==NULL，beforetail是真正的头。
//用这个头挨个和原链表开始对比val，直到head=NULL;比对结束。返回真。
//方法二
//空间复杂度为O（n），直接写一个循环将原有链表memmove，将复制的链表逆置，然后比对。
	bool chkPalindrome(ListNode* A) {
	/*	int Asize = 0;
		ListNode* asize = A;
		while (asize)
		{
			asize = asize->next;
			Asize++;
		}
		int mid = Asize / 2 + Asize % 2;
		ListNode* tail = A;
		for (int i = 0; i<mid; i++)
		{
			tail = tail->next;
		}*/
		ListNode *fast = A;
		ListNode *slow = A;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* tail = slow;
		ListNode* beforetail = NULL;
		ListNode* temp = NULL;
		while (tail)
		{
			temp = tail->next;
			tail->next = beforetail;
			beforetail = tail;
			tail = temp;
		}
		ListNode* head = beforetail;
		while (head)
		{
			if (A->val == head->val)
			{
				A = A->next;
				head = head->next;
				continue;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
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
			n3->val = 777;
			n3->next = n4;
		}
		ListNode*n2 = (ListNode*)malloc(sizeof(ListNode));
		if (n2)
		{
			n2->val = 666;
			n2->next = n3;
		}
		ListNode*pHead = (ListNode*)malloc(sizeof(ListNode));
		if (pHead)
		{
			pHead->val = 555;
			pHead->next = n2;
		}
		int x = 555;
		bool n = chkPalindrome(pHead);
		//while (n)
		//{
		//	printf("%4d->", n->val);
		//	n = n->next;
		//}
		//printf("NULL\n");
		printf("%d\n",n);
		system("pause");
	}