#include"SlistNode.h"
int main()
{
	int quit = 0;
	SListNode* plist = NULL;
	int len = 0;
	while (!quit)
	{
		menu();
		int select = 0;
		scanf(" %d", &select);

		switch (select)
		{
			case 1:
				SListPrint(plist);
				printf("��������%d������\n", len);
				break;
			case 2:
				printf("��������Ҫ�����ֵ��\n");
				int x1 = 0;
				scanf(" %d", &x1);
				SListPushBack(&plist, x1);
				len++;
				break;
			case 3:
				printf("��������Ҫ�����ֵ��\n");
				int x2 = 0;
				scanf(" %d", &x2);
				SListPushFront(&plist, x2);
				len++;
				break;
			case 4:
				SListPopBack(&plist);
				len--;
				break;
			case 5:
				SListPopFront(&plist);
				len--;
				break;
			case 6:
				printf("��������Ҫ���ҵ�ֵ��\n");
				int x3 = 0;
				scanf(" %d", &x3);
				printf("%p\n", SListFind(plist, x3));
				break;
			case 7:
				printf("��������Ҫ�����ֵ��\n");
				int x4 = 0;
				scanf(" %d", &x4);
				printf("��������Ҫ�����λ�ã�\n");
				int x5 = 0;
				scanf(" %d", &x5);
				if (x5<1 || x5>len)
				{
					printf("��λ�ò����ڣ�");
					break;
				}
				//----------------------------------------
				//��Ϊ����λ��pos�����Ķ��Ǻ�һ��������������ͷ����һ��NULL��NULL�����0������������û�ʹ��
				SListNode* pos1 = NULL;
				SListNode* posnext1 = plist;
				for (int i = 1; i <= x5; i++)
				{
					pos1 = posnext1;
					posnext1 = plist->next;
				}
				SListInsertAfter(pos1, x4);
				len++;
				break;
			case 8:
				printf("��������Ҫɾ����λ�ã�\n");
				int x6 = 0;
				scanf(" %d", &x6);
				//��Ϊ����λ��pos�����Ķ��Ǻ�һ��������������ͷ����һ��NULL��NULL�����0������������û�ʹ��
				SListNode* pos2 = NULL;
				SListNode* posnext2 = plist;
				if (x6 == 1)
			    	{
						SListPopFront(&plist);
						len--;
						break;
					}
				else
					{
						for (int i = 2; i <= x6; i++)
						{
							pos2 = posnext2;
							posnext2 = plist->next;
						}
						SListEraseAfter(pos2);
						len--;
						break;
					}
			case 9:
				SListDestory(&plist);
				len = 0;
				break;
			case 0:
				printf("ByeBye!\n");
				quit = 1;
				break;
			default:
				printf("enter error��\n");
				break;
		}
			
	}
	//----------------���Դ���--------------------

	//SListNode* plist = NULL;
	//SListPrint(plist);

	//plist=BuySListNode(0);
	//SListPrint(plist);

	//SListPushBack(&plist, 1);
	//SListPushBack(&plist, 2);
	//SListPushBack(&plist, 3);
	//SListPrint(plist);

	//SListPushFront(&plist, -1);
	//SListPushFront(&plist, -2);
	//SListPushFront(&plist, -3);
	//SListPrint(plist);

	//SListPopBack(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);

	//printf("%p\n", SListFind(plist, 0));
	//printf("%p\n", SListFind(plist, 6));

	//SListInsertAfter(plist->next, 666);
	//SListPrint(plist);

	//SListEraseAfter(plist->next->next);
	//SListPrint(plist);

	//SListDestory(&plist);
	//SListPrint(plist);

	system("pause");
}