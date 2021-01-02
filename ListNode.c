#include "ListNode.h"
// �������������ͷ���.(��ʼ��ͷ�ڵ�)������2�����ؿյĺ�����������ָ�룬�ı�ָ������ݡ�
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
		printf("����ʧ�ܣ������ڴ棡\n");
		return NULL;
	}
}
// ˫����������
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
	printf("���ٳɹ���\n");
	return *plist;
}
// ˫�������ӡ
void ListPrint(ListNode* plist)
{
	if (plist == NULL)
	{
		printf("������\n");
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
// ˫������β��
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
// ˫������βɾ
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
// ˫������ͷ��
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
// ˫������ͷɾ
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
// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode*phead = plist->_next;
	int i = 1;
	while (phead != plist)
	{
		if (phead->_data == x)
		{
			printf("��ҪѰ�ҵ�ֵ�ڵ�%d���ڵ㣡\n",i);
			return phead;
		}
		else
		{
			phead = phead->_next;
			i++;
		}
	}
	printf("δ�ҵ���\n");
	return NULL;
}
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
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