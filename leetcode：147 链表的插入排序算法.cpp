//此题较难理解：写了一篇博客，可以参考一下。链接：https://blog.csdn.net/Zhou000815/article/details/112039839
#include<Windows.h>
#include<stdio.h>
#include <assert.h>
#pragma warning (disable:4996)
//147. 对链表进行插入排序
//对链表进行插入排序。
//
//
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
//
//插入排序算法：
//
//插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//重复直到所有输入数据插入完为止。
//
//
//示例 1：
//
//输入 : 4->2->1->3
//输出 : 1->2->3->4
//链接：https ://leetcode-cn.com/problems/insertion-sort-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
struct ListNode {
   int val;
   struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* cur = head;
	ListNode*curprev = NULL;
	ListNode* next = head->next;
	cur->next = NULL;
	ListNode* realhead = head;
	ListNode* tail = head;
	while (next)
	{
		//头插
		if (next->val <= realhead->val)
		{
			ListNode*temp = next->next;
			next->next = realhead;
			realhead = next;
			next = temp;
			curprev = realhead;
			cur = curprev->next;
		}
		//尾插
		else if (next->val>tail->val)
		{
			tail->next = next;
			tail = next;
			ListNode*temp = next->next;
			next->next = NULL;
			next = temp;
		}
		else
			//中间插
		{
			while (next->val > cur->val)
			{
				curprev = cur;
				cur = cur->next;
			}
			if (next->val <= cur->val)
			{
				ListNode*temp = next->next;
				next->next = cur;
				curprev->next = next;
				next = temp;
				cur = realhead->next;
				curprev = realhead;
			}
		}
	}
	return realhead;
}
int main()
{
	ListNode*n6 = (ListNode*)malloc(sizeof(ListNode));
	if (n6)
	{
		n6->val = 35;
		n6->next =NULL;		
	}
	ListNode*n5 = (ListNode*)malloc(sizeof(ListNode));
	if (n5)
	{
		n5->val = 53;
		n5->next = n6;

	}
	ListNode*n4 = (ListNode*)malloc(sizeof(ListNode));
	if (n4)
	{
		n4->val = -24;
		n4->next = n5;
	
	}
	ListNode*n3 = (ListNode*)malloc(sizeof(ListNode));
	if (n3)
	{
		n3->val = 133;
		n3->next = n4;

	}
	ListNode*n2 = (ListNode*)malloc(sizeof(ListNode));
	if (n2)
	{
		n2->val = 220;
		n2->next = n3;

	}
	ListNode*head = (ListNode*)malloc(sizeof(ListNode));
	if (head)
	{
		head->val = 999;
		head->next = n2;
	
	}
	ListNode* list = head;
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
	ListNode* sortNode = insertionSortList(head);
	ListNode* cpylist = sortNode;
	while (sortNode)
	{
		printf("%10d->", sortNode->val);
		sortNode = sortNode->next;
	}
	printf("NULL\n");
	sortNode = cpylist;
	while (sortNode)
	{
		printf("%10p->", sortNode);
		sortNode = sortNode->next;
	}
	printf("NULL\n");
	system("pause");
}