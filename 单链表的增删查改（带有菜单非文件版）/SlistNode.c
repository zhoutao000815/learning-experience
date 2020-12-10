#include"SlistNode.h"
void menu()
{
	printf("#############################################################\n");
	printf("###1����ӡ######2��β��########3��ͷ��#######################\n");
	printf("###4��βɾ######5��ͷɾ########6�����ң����ص�ַ��###########\n");
	printf("###7������λ�ò���###8������λ��ɾ��######9������############\n");
	printf("###0:�˳�####################################################\n");
	printf("#################   please     select   #####################\n");
}

// ��̬����һ���ڵ�
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
// �������ӡ
void SListPrint(SListNode* plist)
{
	if ( plist == NULL )//ȷ���ǲ��ǿսڵ�
	{
		printf("�սڵ㣡\n");
		return ;
	}
	else//���ǿսڵ�������һ�����ݣ��ȴ�ӡ������������������do while��
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
	SListNode *plist = *pplist;
	if (*pplist == NULL)           //������ֱ������ͺ�
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		while (plist->next != NULL)//�ǿ���������β�ͣ��ҵ�β���ٲ��롣
		{
			plist = plist->next;
		}
									//ѭ�������ҵ�β�ͣ�����������ݽӵ�β���ϼ���
		plist->next= BuySListNode(x);
	}
	printf("�����ɹ�!\n");
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode *plist=BuySListNode(x);//���½ڵ�ĵ�ַ��������
	plist->next = *pplist;           //����ͷ�ĵ�ַ�����½ڵ��next
	*pplist = plist;                 //���½ڵ�ĵ�ַ���µ�ͷ
	printf("�����ɹ�!\n");
}
// �������βɾ
//1��������
//2��ֻ��һ������
//3��>=�������ݡ�
void SListPopBack(SListNode** pplist)
{
	if (pplist == NULL)//���������ֱ�ӽ���
	{
		printf("������\n");
		return ;
	}
	SListNode*plist = *pplist;
	if (plist->next == NULL)//һ������ֱ��ɾ���ͷţ�Ȼ�������
	{
		free(*pplist);
		*pplist = NULL;
		return ;
	}
	while (plist->next != NULL)//  >=2������ʱ�����ҵ�β��ǰһ��Ȼ����ɾ��β��
	{
		if (plist->next->next == NULL)//�ҵ�β��ǰһ����ɾ��β�ͣ������ҵ�β����ɾ�����������޷��ҵ���һ�����ݵĵ�ַ��
		{	
			free(plist->next->next);
			plist->next = NULL;

			break;
		}
		else
		{
			plist = plist->next; //��β�͡�
		}
	}
	printf("�����ɹ�!\n");
}
// ������ͷɾ
//1��������
//2��ֻ��һ������  ==  3��>=��������
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	if (pplist == NULL)
	{
		printf("������\n");
		return ;
	}
	else
	{
		SListNode*plist = *pplist;  //����ͷ��ַ�������������ͷš�
		*pplist = plist->next;		//����ͷ����һ�����ݵ�ַ������ͷ
		free(plist);				
	}
	printf("�����ɹ�!\n");
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
	printf("û�ҵ������ؿյ�ַ��\n");
	return NULL;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿//��������е����ԣ�ֻ��posλ���¸����ݵĵ�ַ��û��posλ���ϸ����ݵĵ�ַ��Ҳ����֮ǰ���룬����Ҫ�ٴα�����������ʱ����������һ��next��
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* NEXT = pos->next;		//������ʱ��������pos����һ�����ݵĵ�ַ
	pos->next = BuySListNode(x);		//���½ڵ��pos������һ������������
	pos->next->next = NEXT;				//���½ڵ��pos�ľ���һ������������
	printf("�����ɹ�!\n");

	//SListNode* NEXT = BuySListNode(x);  //������ʱ���������½ڵ�ĵ�ַ
	//NEXT->next = pos->next;			  //���½ڵ��pos�ľ���һ������������
	//pos->next = NEXT;					  //���½ڵ�ĵ�ַ��pos����һ��
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�//���Ӳ���ǰ��һ�����ݡ�
void SListEraseAfter(SListNode* pos)//ɾ������pos����һ��λ�õ�����
{
	assert(pos);
	SListNode* EraseNode = pos->next;    //������ʱ��������pos����һ�����ݵĵ�ַ
	pos->next = EraseNode->next;		 //����ɾ��λ�õ���һ�����ݵĵ�ַ����pos��next
	free(EraseNode);					 
	EraseNode = NULL;
	printf("�����ɹ�!\n");
}
// �����������
//����ͷɾ�ͺ�
void SListDestory(SListNode** pplist)
{
	assert(pplist);
	if (*pplist != NULL)
	{
		while (*pplist != NULL)
		{

			SListNode* plist = *pplist;//��ͷ�ڵ�ĵ�ַ����������
			*pplist = plist->next;//����һ���ڵ㸳��ͷ�ڵ�
			free(plist);//�ͷ�ͷ�ڵ㡣

			//��һ��Ϊʲô��pplist��
			//SListPopFront(pplist);
		}
		printf("�����ɹ�!\n");
	}
	else
	{
		printf("�Ѿ��ǿսڵ��ˣ�\n");
	}

}