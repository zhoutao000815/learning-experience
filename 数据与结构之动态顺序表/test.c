#include"seqlist.h"
//�������Ӵ���2019��1120����Ϊ�ұ��ļ���׺û��ͳһ��һ����.cpp��һ����.c��ͳһΪC��������
int main()
{
	SeqList *psl = NULL;
	psl = (SeqList*)malloc(sizeof(SeqList));//�ṹ��ָ�룬
	if (psl != NULL)
	{
		psl->capicity = 1;
		psl->size =1;
	}
	else
	{
		return;
	}
	int quit = 0;
	while (quit != 1)
	{
		menu();
		int select = 0;
		scanf("%d", &select);
		switch (select)
		{
			case 0:
				quit = 1;
				free(psl->array);
				free(psl);
				printf("byebye!\n");
				break;
			case 1:
				SeqListInit(psl,psl->capicity);
				break;
			case 2:
				SeqListDestory(psl);
				break;
			case 3:
				SeqListPrint(psl);
				break;
			case 4:
				printf("������Ҫ��������֣�\n");
				SLDataType x1 = 0;
				scanf(" %d", &x1);
				SeqListPushBack(psl,x1);
				break;
			case 5:
				SeqListPopBack(psl);
				break;
			case 6:
				printf("������Ҫ��������֣�\n");
				SLDataType x2 = 0;
				scanf(" %d", &x2);
				SeqListPushFront(psl, x2);
				break;
			case 7:
				SeqListPopFront(psl);
				break;
			case 8:
				printf("������Ҫ���ҵ����֣�\n");
				SLDataType x3 = 0;
				scanf(" %d", &x3);
				printf("λ�ã�%3d\n", SeqListFind(psl, x3));
				break;
			case 9:
				printf("������Ҫ�����λ�ã�\n");
				SLDataType pos = 0;
				scanf(" %d", &pos);
				printf("������Ҫ��������֣�\n");
				SLDataType x4 = 0;
				scanf(" %d", &x4);
				SeqListInsert(psl, pos, x4);
				break;
			case 10:
				printf("������Ҫɾ����λ�ã�\n");
				SLDataType pos2 = 0;
				scanf(" %d", &pos2);
				SeqListErase(psl, pos2);
				break;
			default:
				printf("error enter!\n");
				break;
		}
	}
	//���Դ���
	//SeqListInit(psl, 4);
	//SeqListPrint(psl);

	//SeqListPushBack(psl, 5);
	//SeqListPushBack(psl, 6);
	//SeqListPrint(psl);

	//SeqListPopBack(psl);
	//SeqListPrint(psl);

	//SeqListPushFront(psl, 0);
	//SeqListPushFront(psl, -1);
	//SeqListPrint(psl);

	//SeqListPopFront(psl);
	//SeqListPrint(psl);

	//SeqListInsert(psl, 3, 666);
	//SeqListInsert(psl, 3, 666);
	//SeqListInsert(psl, 3, 666);
	//SeqListPrint(psl);
	//SeqListErase(psl, 3);
	//SeqListPrint(psl);
	system("pause");
}