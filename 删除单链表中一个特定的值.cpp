#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)	
struct ListNode {
	int val;
	struct ListNode *next;	
};
struct ListNode* removeElements(struct ListNode* head, int val){
	//方法一
	//-------------------------------
	//基本思路：
	//双指针：因为单向链表不能找到上一个的数据地址，所以一个指针肯定不行，两个指针指向同一个地址也不行。
	//故而快指针指向头，慢指针指向空，用快指针检测是否要删除，快指针指向空，则检测完毕。
	//是删除位置，则判断是不是头节点，当头节点是要删除的位置时，比较特殊，需要进行头删，更换头节点。
	//快指针再指向新的头。     
	//不是头节点，则正常删除快慢指针一起往后走。
	//不是删除位置，则快慢指针一起往后走。
	//
	//-------------------------------
	/*struct ListNode* fast=head;
	struct ListNode* slow=NULL;
	while(fast)
	{
	if(fast->val==val)
	{
	if(head==fast)
	{
	head=fast->next;
	free(fast);
	fast=head;
	}
	else
	{
	slow->next=fast->next;
	free(fast);
	fast=slow->next;
	}

	}
	else
	{
	slow=fast;
	fast=fast->next;
	}
	}
	return head;*/

	//方法二
	//-------------------------------
	//基本思路：
	//比较搓的思路，先确保传进来的不是空结点，
	//然后再判断头节点是不是要删除的值，是则头删，不是则开始下一个位置。确保头指针不是删除的数据
	//然后快指针指向第二个数据，慢指针指向第一个，快指针依次检测直到指向空
	//-------------------------------
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* newhead = head;
	while (head->val == val)
	{
		newhead = head->next;
		free(head);
		head = newhead;
		if (newhead == NULL)
		{
			return NULL;
		}
	}
	struct ListNode* fast = newhead->next;
	struct ListNode* slow = newhead;
	while (fast)
	{
		if (fast->val == val)
		{
			slow->next = fast->next;
			free(fast);
			fast = slow->next;
		}
		else
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return newhead;
}
int main()
{
	struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
 	head1->next = NULL;
	head1->val = 1; 
	printf("%p\n", removeElements(head1, 1));



	system("pause");
}