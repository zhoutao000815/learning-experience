#include"SlistNode.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* Node = NULL;
	Node = (SListNode*)malloc(sizeof(SListNode));
	if (Node != NULL)
	{
		Node->data = x;
		Node->next = NULL;
	}
	return Node;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	if ( plist == NULL )
	{
		printf("�սڵ㣡\n");
	}
	else
	{
		do
		{
			printf("%d->", plist->data);
			plist = plist->next;
		} while (plist != NULL);
	}
	printf("NULL\n");
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode *plist = *pplist;
	while (plist->next != NULL)
	{
		plist = plist->next;
	}
	plist->next= BuySListNode(x);
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode *plist=BuySListNode(x);//���½ڵ�ĵ�ַ��������
	plist->next = *pplist;//����ͷ�ĵ�ַ�����½ڵ��next
	*pplist = plist;//���½ڵ�ĵ�ַ���µ�ͷ
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	SListNode*plist = *pplist;
	while (plist->next != NULL)
	{
		if (plist->next->next == NULL)
		{	
			free(plist->next->next);
			plist->next = NULL;

			break;
		}
		else
		{
			plist = plist->next;
		}
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode*plist = *pplist;
	*pplist = plist->next;
	free(plist);
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	while (plist != NULL)
	{
		if (plist->data == x)
		{
			return plist;
		}
		else
		{
			plist = plist->next;
		}
	}
	return NULL;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿//��������е����ԣ�ֻ��posλ���¸����ݵĵ�ַ��û��posλ���ϸ����ݵĵ�ַ��Ҳ����֮ǰ���룬����Ҫ�ٴα�����������ʱ����������һ��next��
void SListInsertAfter(SListNode* pos, SLTDateType x)
{

}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�//���Ӳ���ǰ��һ�����ݡ�
void SListEraseAfter(SListNode* pos)
{

}
// �����������
//����ͷɾ�ͺ�
void SListDestory(SListNode* plist)
{
	assert(plist);
	//if (plist != NULL)
	//{
	//	while (plist != NULL)
	//	{
	//		SListNode* plistcopy = plist->next;//����һ���ڵ�ĵ�ַ����������
	//		free(plist);//�ͷ�ͷ�ڵ㡣
	//		plist = plistcopy;//����һ���ڵ��ͷ�ڵ�
	//		printf("%p\n",plist);
	//	}
	//}
	//else
	//{
	//	printf("�Ѿ��ǿսڵ��ˣ�\n");
	//}
	//plist = NULL;
	SListPopFront(&plist);
}