#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//编写一个程序，找到两个单链表相交的起始节点。
//示例 1：
//输入：intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3
//输出：Reference of the node with value = 8
//输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为[4, 1, 8, 4, 5]，链表 B 为[5, 0, 1, 8, 4, 5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/intersection-of-two-linked-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//注意：因为是找相交的共同节点，所以比对的是地址，而不是val，存在值相等而不是同一个节点的情况。
	//方法一
	//思路：
	//相交结尾必定相同，先让他们都走到尾，不相同直接返回NULL。
	//相同说明必相交，分别记录俩个的链表长度，进行尾对齐（长链表走两个链表长度差值的步数）。
	//再从短链表的头节点开始，和尾对齐后的长链表进行对比，相同则记录结束，
	//
	//if (headA == NULL || headB == NULL)
	//{
	//	return NULL;
	//}
	//ListNode *Atail = headA;
	//ListNode *Btail = headB;
	//ListNode *Ahead = headA;
	//ListNode *Bhead = headB;
	//int Alen = 0;
	//int Blen = 0;
	//while (Atail)
	//{
	//	if (Atail->next == NULL)
	//	{
	//		break;
	//	}
	//	Atail = Atail->next;
	//	Alen++;
	//}
	//while (Btail)
	//{
	//	if (Btail->next == NULL)
	//	{
	//		break;
	//	}
	//	Btail = Btail->next;
	//	Blen++;
	//}
	//int lenAB = 0;
	//if (Atail == Btail)
	//{
	//	if (Alen>Blen)
	//	{
	//		lenAB = Alen - Blen;
	//		while (lenAB--)
	//		{
	//			Ahead = Ahead->next;
	//		}
	//		while (Ahead != Bhead)
	//		{
	//			Ahead = Ahead->next;
	//			Bhead = Bhead->next;
	//		}
	//		return Ahead;
	//	}
	//	else
	//	{
	//		lenAB = Blen - Alen;
	//		while (lenAB--)
	//		{
	//			Bhead = Bhead->next;
	//		}
	//	}
	//	while (Ahead != Bhead)
	//	{
	//		Ahead = Ahead->next;
	//		Bhead = Bhead->next;
	//	}
	//	return Ahead;
	//}
	//else
	//{
	//	return NULL;
	//}
	//评论区看到的双指针做法，
	//方法二
	//思路：
	//两链表存在长度差，双指针把两个链表都走一遍，这样路长度差就被消除了。
	//当走到相同步幅的节点时，判断是否相等，相等则返回，不相等则继续。
	//如果链表中不存在相交点，则双指针一起走i到空。
	ListNode *L1,*L2;
	L1=headA;
	L2=headB;

	while(L1!=L2)
	{
	L1=((L1==NULL)?headB:L1->next);
	L2=((L2==NULL)?headA:L2->next);
	}
	return L2;
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
	ListNode*l1 = (ListNode*)malloc(sizeof(ListNode));
	if (l1)
	{
		l1->val = 111;
		l1->next = n2;
	}
	ListNode*n6 = (ListNode*)malloc(sizeof(ListNode));
	if (n6)
	{
		n6->val = 999;
		n6->next = n2;
	}
	ListNode*n5 = (ListNode*)malloc(sizeof(ListNode));
	if (n5)
	{
		n5->val = 666;
		n5->next = n6;
	}
	ListNode*l2 = (ListNode*)malloc(sizeof(ListNode));
	if (l2)
	{
		l2->val = 222;
		l2->next = n5;
	}
	ListNode*n = getIntersectionNode(l1, l2);
	while (n)
	{
		printf("%4d->", n->val);
		n = n->next;
	}
	printf("NULL\n");
	system("pause");
}