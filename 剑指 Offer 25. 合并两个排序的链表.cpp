//剑指 Offer 25. 合并两个排序的链表
//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
//
//示例1：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//限制：
//
//0 <= 链表长度 <= 1000
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//方法一:遍历两链表，构造一个新链表，各自取小的下来尾插到新链表，直到某个为空。
//方法二:在原链表上进行操作，改变指向。
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		//将l2插入到l1，cur1和head都要指向第一个值最小的那个
		if (cur1->val>cur2->val)
		{
			cur1 = l2;
			cur2 = l1;
		}
		ListNode* next1 = cur1->next;
		ListNode* next2 = cur2->next;
		ListNode* head = cur1;
		while (cur2 && cur1)
		{
			if (next1 == NULL)//说明l2此时的值，大于l1最后一个值，此时cur1指向l1末尾，
			{
				cur1->next = cur2;
				break;
			}
			if (cur2->val <= next1->val)
			{
				cur1->next = cur2;
				cur2->next = next1;
				next1 = cur1->next;

				cur2 = next2;  //注意当cur2指向最后一个时，
				if (next2 != NULL)   //next2指向了空，但是cur2还没插入，next2不为空则移动指针，为空了就不移动next2，插入cur2
					next2 = next2->next;
			}
			else
			{
				cur1 = next1;
				next1 = next1->next;
			}
		}
		return head;
	}
};