#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。
//
//
//
//示例 1：
//
//输入：[1, 2, 3, 4, 5]
//输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
//返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
//示例 2：
//
//输入：[1, 2, 3, 4, 5, 6]
//输出：此列表中的结点 4 (序列化形式：[4, 5, 6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/middle-of-the-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

struct ListNode {
	int val;
	struct ListNode *next;	
};
typedef struct ListNode ListNode;
//基本思路
//快慢指针：快慢指针都指向头节点：
//快指针一次走两步，慢指针一次走一步，
//假如快指针走到最后一个或者走到最后一个的下一个NULL则停下来。慢指针就是中间节点
//如果要求返回上节点呢?
//
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast  && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
int main()
{
	struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
 	head1->next = NULL;
	head1->val = 1; 

	system("pause");
}