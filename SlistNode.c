#include"SlistNode.h"

// 动态申请一个节点
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
// 单链表打印
void SListPrint(SListNode* plist)
{
	if ( plist == NULL )
	{
		printf("空节点！\n");
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
// 单链表尾插
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
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode *plist=BuySListNode(x);//将新节点的地址记下来，
	plist->next = *pplist;//将旧头的地址放入新节点的next
	*pplist = plist;//将新节点的地址给新的头
}
// 单链表的尾删
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
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode*plist = *pplist;
	*pplist = plist->next;
	free(plist);
}
// 单链表查找
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
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？//单链表具有单向性，只有pos位置下个数据的地址，没有pos位置上个数据的地址。也可以之前插入，但是要再次遍历，创建临时变量保存上一个next。
void SListInsertAfter(SListNode* pos, SLTDateType x)
{

}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？//链接不到前面一个数据。
void SListEraseAfter(SListNode* pos)
{

}
// 单链表的销毁
//挨个头删就好
void SListDestory(SListNode* plist)
{
	assert(plist);
	//if (plist != NULL)
	//{
	//	while (plist != NULL)
	//	{
	//		SListNode* plistcopy = plist->next;//将下一个节点的地址保存起来。
	//		free(plist);//释放头节点。
	//		plist = plistcopy;//将下一个节点给头节点
	//		printf("%p\n",plist);
	//	}
	//}
	//else
	//{
	//	printf("已经是空节点了！\n");
	//}
	//plist = NULL;
	SListPopFront(&plist);
}