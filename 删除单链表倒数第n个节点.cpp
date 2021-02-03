//19. 删除链表的倒数第 N 个结点

//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
//进阶：你能尝试使用一趟扫描实现吗？
//
//
//
//示例 1：
//
//
//输入：head = [1, 2, 3, 4, 5], n = 2
//输出：[1, 2, 3, 5]
//示例 2：
//
//输入：head = [1], n = 1
//输出：[]
//示例 3：
//
//输入：head = [1, 2], n = 1
//输出：[1]
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	int flag = 0;
	struct ListNode* last = head;
	struct ListNode* cur = head;  //cur指向要删除节点之前一个。
	while (n + 1>flag)  //+1是为了让cur指在要删除的节点之前一个位置，方便删除。
	{
		//先让last走n+1步，有可能要删除第一个，last就会越界。（因为cur是从head开始的，）
		if (last == NULL)
		{
			head = head->next;
			return head;
		}
		last = last->next;
		++flag;
	}
	while (last != NULL)  //直到last==NULL，cur此时就是倒数第n+1个。
	{
		last = last->next;
		cur = cur->next;
	}
	struct ListNode* Popcopy = cur->next;
	// if(cur!=NULL && cur->next!=NULL)
	// {  
	cur->next = cur->next->next;
	// }

	free(Popcopy);
	return head;
}