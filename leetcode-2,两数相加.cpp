//2. 两数相加
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//
//
//示例 1：
//
//
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 0, 8]
//解释：342 + 465 = 807.
//示例 2：
//
//输入：l1 = [0], l2 = [0]
//输出：[0]
//示例 3：
//
//输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//输出：[8, 9, 9, 9, 0, 0, 0, 1]
//
//
//提示：
//
//每个链表中的节点数在范围[1, 100] 内
//0 <= Node.val <= 9
//题目数据保证列表表示的数字不含前导零

//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-two-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
    struct ListNode *next;
 };


typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	//由于提示两链表不会为空，所以不做检查了
	Node *head = NULL, *tail = NULL;      //头指针用来返回，尾指针用来尾插
	int carry = 0;   //进位
	while (l1 || l2)
	{
		int num1 = l1 ? l1->val : 0;     //存在取值，不存在取0
		int num2 = l2 ? l2->val : 0;
		Node *rel = (Node *)malloc(sizeof(Node));
		rel->val = (num1 + num2 + carry) % 10;    //当前节点取余数
		carry = (num1 + num2 + carry) / 10;       //进位取结果
		if (head == NULL)   //头节点为空，表明第一位，特殊处理
		{
			head = rel;
			tail = rel;
			l1 = l1->next ? l1->next : NULL;
			l2 = l2->next ? l2->next : NULL;
			continue;
		}
		tail->next = rel;
		tail = tail->next;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	if (carry != 0)   //如果有进位时也要增加一个节点，
	{
		Node *rel = (Node *)malloc(sizeof(Node));
		rel->val = carry;
		tail->next = rel;
		tail = tail->next;
	}
	tail->next = NULL;
	return head;
}