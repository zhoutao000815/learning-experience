#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-two-sorted-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 struct ListNode {
	int val;
	struct ListNode *next;
 };
typedef struct ListNode ListNode;
//方法一：将l2依次取下来插入到l1里。
//设立哨兵位，设定指向l1的快慢指针（快：l1，慢：beforel1），用快指针依次对比l2.符合条件插入在beforel1的后面。
//l2->val小于等于l1->val,则插入。快指针l1不变，慢指针beforel1指向插入进来的新节点.
//否则快慢指针一起向后走，直到找到l2->val小于等于l1->val。
//直到有一方链表为空。分情况讨论
//l2最后为空：说明插入完毕，结束找realhead返回即可。
//l1最后为空：说明没有插入完毕，并且此时的l2的第一个数据大于l1的最大数据，那么直接把l2插入在l1的后面即可。
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = l1;
	ListNode* beforel1 = head;
	ListNode* temp = NULL;
	while (l1 && l2)
	{
		if (l2->val <= l1->val)
		{
			
			temp = l2->next;
			l2->next = l1;
			beforel1->next = l2;
			l2 = temp;
			beforel1 = beforel1->next;
		}
		else
		{
			beforel1 = l1;
			l1 = l1->next;
		}
	}
	if (l1 == NULL)
	{
		beforel1->next = l2;
	}
	ListNode* realhead = head->next;
	return realhead;
}
//方法二：对比两链表的头节点，取小的头节点下来尾插到哨兵位。
//设置一个哨兵位头节点，对比两个链表的头的val，小的那个取下来，在哨兵位节点往后尾插。依次取值往哨兵位的尾插入。
//取到任意一个链表为空时，停止。将剩下的那个非空链表插在合成的带哨兵位的链表的尾巴。
//抛弃哨兵位，取到真正的头节点的地址，返回。
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
		n6->val = 1000;
		n6->next = NULL;
	}
	ListNode*n5 = (ListNode*)malloc(sizeof(ListNode));
	if (n5)
	{
		n5->val = 777;
		n5->next = n6;
	}
	ListNode*l2 = (ListNode*)malloc(sizeof(ListNode));
	if (l2)
	{
		l2->val = 222;
		l2->next = n5;
	}
	ListNode*n = mergeTwoLists(l1,l2);
	while (n)
	{
	    printf("%4d->", n->val);
		n = n->next;
	}
	printf("NULL\n");
	system("pause");
}