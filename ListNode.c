#include "ListNode.h"
// 创建返回链表的头结点.(初始化头节点)。方法2：返回空的函数，传二级指针，改变指针的内容。
ListNode* ListCreate()
{
	ListNode*plist = (ListNode*)malloc(sizeof(ListNode));
	if (plist)
	{
		plist->_next = plist;
		plist->_prev = plist;
		return plist;
	}
	else
	{
		printf("申请失败，请检查内存！\n");
		return NULL;
	}
}
// 双向链表销毁
ListNode* ListDestory(ListNode** plist)
{
	assert(plist);
	ListNode*phead = (*plist)->_next;
	while (phead != (*plist))
	{
		ListNode*temp = phead->_next;
		free(phead);
		phead = temp;
		phead->_prev = *plist;
		(*plist)->_next = phead;
	}
	free(*plist);
	*plist = NULL;
	Sleep(3000);
	printf("销毁成功！\n");
	return *plist;
}
// 双向链表打印
void ListPrint(ListNode* plist)
{
	if (plist == NULL)
	{
		printf("空链表！\n");
		return;
	}
	assert(plist);
	ListNode* phead = plist->_next;
	while (plist != phead)
	{
		printf("%3d->", phead->_data);
		phead = phead->_next;
	}
	printf("NULL");
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode*tail = plist->_prev;
	ListNode*newtail = (ListNode*)malloc(sizeof(ListNode));
	if (newtail)
	{
		newtail->_data = x;
		newtail->_prev = tail;
		newtail->_next = plist;
		plist->_prev = newtail;
		tail->_next = newtail;
	}

}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	assert(plist);
	ListNode*tail = plist->_prev;
	ListNode*tailprev = tail->_prev;
	free(tail);
	tailprev->_next = plist;
	plist->_prev = tailprev;
	tail = NULL;
	tailprev = NULL;
}
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode*phead = plist->_next;
	ListNode*newphead = (ListNode*)malloc(sizeof(ListNode));
	if (newphead)
	{
		newphead->_data = x;
		newphead->_next = phead;
		newphead->_prev = plist;
		plist->_next = newphead;
		phead->_prev = newphead;
	}
	phead = NULL;
	newphead = NULL;
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	assert(plist);
	ListNode*phead = plist->_next;
	ListNode*newphead = phead->_next;
	free(phead);
	phead = NULL;
	plist->_next = newphead;
	newphead->_prev = plist;
	newphead = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode*phead = plist->_next;
	int i = 1;
	while (phead != plist)
	{
		if (phead->_data == x)
		{
			printf("宁要寻找的值在第%d个节点！\n",i);
			return phead;
		}
		else
		{
			phead = phead->_next;
			i++;
		}
	}
	printf("未找到！\n");
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode*InsertNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode*posprev = pos->_prev;
	if (InsertNode)
	{
		InsertNode->_data = x;
		InsertNode->_next = pos;
		InsertNode->_prev = posprev;
		pos->_prev = InsertNode;
		posprev->_next = InsertNode;
	}
	posprev = NULL;
	pos = NULL;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posprev = pos->_prev;
	ListNode* posnext = pos->_next;
	posprev->_next = posnext;
	posnext->_prev = posprev;
	free(pos);
	pos = NULL;
}