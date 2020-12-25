#include<stdio.h>
#include<Windows.h>
#include <assert.h>
#pragma warning (disable:4996)
//给定一个链表，判断链表中是否有环。
//
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//
//如果链表中存在环，则返回 true 。 否则，返回 false 。
//进阶：
//你能用 O(1)（即，常量）内存解决此问题吗？
//
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/linked-list-cycle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 struct ListNode {
     int val;
     struct ListNode *next;
};
typedef struct ListNode ListNode;
//解法：快慢指针法，慢指针一次走一步，快指针一次走两步，快指针先进环，慢指针后进环，当环很小，而链子很长的时候，快指针会在环里一直跑圈。
//当慢指针进入环的时候，快指针可能在环上任意一点，这时，开始追击问题，此时快指针和慢指针相差X步，每次走位，X-1。
//当快指针追上慢指针的时候，慢指针走了X步。（问：快指针可以一次走两步，三步吗？）
//所以假设链表链子长度为L，环长度为C，在环上取任意一个相遇点，相遇点距离进入环的第一个节点的距离为X。
//那么慢指针走的距离为L+X，快指针走的距离为L+X+nC。快指针走的距离是慢指针的2倍，
//还不明白的话，请看2020-12-24的题目解析的图。
bool hasCycle(struct ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	system("pause");
}