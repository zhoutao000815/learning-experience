//此题较难理解：写了一篇博客，可以参考一下。链接：https://blog.csdn.net/Zhou000815/article/details/111871392
#include<stdio.h>
#include<Windows.h>
#include <assert.h>
#pragma warning (disable:4996)
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
//
//说明：不允许修改给定的链表。
//
//进阶：
//
//你是否可以使用 O(1) 空间解决此题？
//
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/linked-list-cycle-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 struct ListNode {
     int val;
     struct ListNode *next;
};
typedef struct ListNode ListNode;
//解法1
//先用快慢指针判断有没有环，当快慢指针指向同一节点说明有环。如果指向空说明无环。（具体细节参考问题：寻找两个相交链表的第一个共同节点。）
//将快慢指针指向的同一环节点断开，分裂成两个链表，寻找链表的第一个相交节点即可。
//最后将环断开点连接回去。
struct ListNode *detectCycle(struct ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	ListNode*head1 = fast->next;
	ListNode*head2 = head;
	ListNode*list1 = head1;
	ListNode*list2 = head2;
	ListNode*temp = head1;
	fast->next = NULL;
	while (head1 != head2)
	{
		head2 = ((head2 == NULL) ? list1 : head2->next);
		head1 = ((head1 == NULL) ? list2 : head1->next);
	}
	fast->next = temp;
	return head2;
}
//解法2
//先用快慢指针判断有没有环，当快慢指针指向同一节点说明有环。如果指向空说明无环。（具体细节参考问题：寻找两个相交链表的第一个共同节点。）

struct ListNode *detectCycle2(struct ListNode *head) 
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	while (head != slow)
	{
		head = head->next;
		slow = slow->next;
	}
	return slow;
}
int main()
{
	ListNode*n6 = (ListNode*)malloc(sizeof(ListNode));
	if (n6)
	{
		n6->val = 66;
		n6->next =NULL;
	}
	ListNode*n5 = (ListNode*)malloc(sizeof(ListNode));
	if (n5)
	{
		n5->val = 55;
		n5->next = n6;
	}
	ListNode*n4 = (ListNode*)malloc(sizeof(ListNode));
	if (n4)
	{
		n4->val = 44;
		n4->next = n5;
	}
	ListNode*n3 = (ListNode*)malloc(sizeof(ListNode));
	if (n3)
	{
		n3->val = 33;
		n3->next = n4;
	}
	ListNode*n2 = (ListNode*)malloc(sizeof(ListNode));
	if (n2)
	{
		n2->val = 22;
		n2->next = n3;
	}
	ListNode*head = (ListNode*)malloc(sizeof(ListNode));
	if (head)
	{
		head->val = 11;
		head->next = n2;
	}
	n6->next = n2;
	ListNode* detectListNode =detectCycle2(head);
	printf("%p\n", detectListNode);
	printf("%d\n", detectListNode->val);
	system("pause");
}