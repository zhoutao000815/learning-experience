#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
//反转一个单链表。
//
//示例 :
//
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
// 进阶 :
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
struct ListNode {
	int val;
	struct ListNode *next;	
};
typedef struct ListNode ListNode;
//基本思路：
//双指针法，快指针指向头节点，慢指针置空，用头指针保存下一个逆置的地址，然后将快指针的指向变为慢指针。
//然后快慢指针再往后移动，直到快指针指向空，表明逆置结束。
//递归头插法：未实现。
struct ListNode* reverseList(struct ListNode* head){
	ListNode* prev = NULL;
	ListNode* cur = head;
	while (cur)
	{
		head = head->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}
	return prev;
}
int main()
{
	struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
 	head1->next = NULL;
	head1->val = 1; 

	system("pause");
}