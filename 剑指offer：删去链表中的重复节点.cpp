//此题较难理解：写了一篇博客，可以参考一下。链接：https://blog.csdn.net/Zhou000815/article/details/112087174
#include<Windows.h>
#include<stdio.h>
#include <assert.h>
#pragma warning (disable:4996)
//剑指offer，删除链表中的重复节点。
//题目描述
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//示例1
//输入
//复制
//{ 1, 2, 3, 3, 4, 4 }
//返回值
//复制
//{ 1, 2 }
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
	ListNode* deleteDuplication(ListNode* pHead)
	{
		//0个或者1个节点无重，直接返回即可。
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		//设置哨兵位头节点，并链接，将prev和cur和next指向对应位置。
		ListNode*pphead = (ListNode*)malloc(sizeof(ListNode));
		ListNode*prev = pphead;
		pphead->next = pHead;
		ListNode*cur = pHead;
		ListNode*next = pHead->next;
		//用next判断是否删重结束
		while (next)
		{
			//不相同，保留即可。
			if (cur->val != next->val)
			{
				prev->next = cur;
				prev = prev->next;
				cur = cur->next;
				next = next->next;
			}
			else
			{
				//相同了，释放cur后，一起移动。走到它俩不同或者next'到NULL时结束。
				while (next->val == cur->val)
				{
					ListNode*temp = cur;
					cur = next;
					next = next->next;
					free(temp);
					if (next == NULL)//链表到NULL结束，第二种情况。
					{
						break;
					}
				}
				//此时循环结束两种情况，
				//第一种，因为俩指针指向不相同退出，
				//第二种，链表结束，next到NULL。
				free(cur);//先释放cur，
				cur = next;//再将cur走到next，
				if (next == NULL)//第二种情况，cur已经释放，直接将prev-》next置NULL即可。
				{
					prev->next = cur;
				}
				else//第一种情况，next不为空，但是不相同了。cur已经释放并且已经移动，
				{
					next = next->next;//next继续移动
					if (next == NULL)//next为空了，说明最后一个数字了，此时cur指向它，保留下来即可。
					{
						prev->next = cur;
					}
				}
			}
		}
		ListNode* realhead = pphead->next;
		free(pphead);
		return realhead;
	}
	//测试代码
int main()
{
	ListNode*n6 = (ListNode*)malloc(sizeof(ListNode));
	if (n6)
	{
		n6->val = 53;
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
		n4->val = 666;
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
		n2->val = 133;
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
	ListNode* sortNode = deleteDuplication(head);
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