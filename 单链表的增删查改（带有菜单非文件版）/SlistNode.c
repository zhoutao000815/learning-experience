#include"SlistNode.h"
void menu()
{
	printf("#############################################################\n");
	printf("###1：打印######2：尾插########3：头插#######################\n");
	printf("###4：尾删######5：头删########6：查找（返回地址）###########\n");
	printf("###7：任意位置插入###8：任意位置删除######9：销毁############\n");
	printf("###0:退出####################################################\n");
	printf("#################   please     select   #####################\n");
}

// 动态申请一个节点
static SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = NULL;
	newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode != NULL)
	{
		newNode->data = x;
		newNode->next = NULL;
	}
	return newNode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	if ( plist == NULL )//确定是不是空节点
	{
		printf("空节点！\n");
		return ;
	}
	else//不是空节点至少有一个数据，先打印，再往下链，所以用do while。
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
	SListNode *plist = *pplist;
	if (*pplist == NULL)           //空链表直接申请就好
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		while (plist->next != NULL)//非空链表先找尾巴，找到尾巴再插入。
		{
			plist = plist->next;
		}
									//循环结束找到尾巴，将插入的数据接到尾巴上即可
		plist->next= BuySListNode(x);
	}
	printf("操作成功!\n");
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode *plist=BuySListNode(x);//将新节点的地址记下来，
	plist->next = *pplist;           //将旧头的地址放入新节点的next
	*pplist = plist;                 //将新节点的地址给新的头
	printf("操作成功!\n");
}
// 单链表的尾删
//1、空链表
//2、只有一个数据
//3、>=两个数据。
void SListPopBack(SListNode** pplist)
{
	if (pplist == NULL)//空链表情况直接结束
	{
		printf("空链表！\n");
		return ;
	}
	SListNode*plist = *pplist;
	if (plist->next == NULL)//一个链表直接删除释放，然后结束。
	{
		free(*pplist);
		*pplist = NULL;
		return ;
	}
	while (plist->next != NULL)//  >=2个数据时，先找到尾巴前一个然后在删除尾巴
	{
		if (plist->next->next == NULL)//找到尾巴前一个，删掉尾巴，不能找到尾巴再删除，单链表无法找到上一个数据的地址。
		{	
			free(plist->next->next);
			plist->next = NULL;

			break;
		}
		else
		{
			plist = plist->next; //找尾巴。
		}
	}
	printf("操作成功!\n");
}
// 单链表头删
//1、空链表
//2、只有一个数据  ==  3、>=两个数据
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	if (pplist == NULL)
	{
		printf("空链表！\n");
		return ;
	}
	else
	{
		SListNode*plist = *pplist;  //将旧头地址保存起来方便释放。
		*pplist = plist->next;		//将旧头的下一个数据地址赋给新头
		free(plist);				
	}
	printf("操作成功!\n");
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
	printf("没找到！返回空地址！\n");
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？//单链表具有单向性，只有pos位置下个数据的地址，没有pos位置上个数据的地址。也可以之前插入，但是要再次遍历，创建临时变量保存上一个next。
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* NEXT = pos->next;		//创建临时变量保存pos的下一个数据的地址
	pos->next = BuySListNode(x);		//将新节点和pos的新下一个数据连起来
	pos->next->next = NEXT;				//将新节点和pos的旧下一个数据连起来
	printf("操作成功!\n");

	//SListNode* NEXT = BuySListNode(x);  //创建临时变量保存新节点的地址
	//NEXT->next = pos->next;			  //将新节点和pos的旧下一个数据连起来
	//pos->next = NEXT;					  //把新节点的地址给pos的下一个
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？//链接不到前面一个数据。
void SListEraseAfter(SListNode* pos)//删除的是pos的下一个位置的数据
{
	assert(pos);
	SListNode* EraseNode = pos->next;    //创建临时变量保存pos的下一个数据的地址
	pos->next = EraseNode->next;		 //将被删除位置的下一个数据的地址赋给pos的next
	free(EraseNode);					 
	EraseNode = NULL;
	printf("操作成功!\n");
}
// 单链表的销毁
//挨个头删就好
void SListDestory(SListNode** pplist)
{
	assert(pplist);
	if (*pplist != NULL)
	{
		while (*pplist != NULL)
		{

			SListNode* plist = *pplist;//将头节点的地址保存起来。
			*pplist = plist->next;//将下一个节点赋给头节点
			free(plist);//释放头节点。

			//想一想为什么传pplist？
			//SListPopFront(pplist);
		}
		printf("操作成功!\n");
	}
	else
	{
		printf("已经是空节点了！\n");
	}

}