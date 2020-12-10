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
				printf("此链表有%d个数据\n", len);
				break;
			case 2:
				printf("请输入你要插入的值！\n");
				int x1 = 0;
				scanf(" %d", &x1);
				SListPushBack(&plist, x1);
				len++;
				break;
			case 3:
				printf("请输入你要插入的值！\n");
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
				printf("请输入你要查找的值！\n");
				int x3 = 0;
				scanf(" %d", &x3);
				printf("%p\n", SListFind(plist, x3));
				break;
			case 7:
				printf("请输入你要插入的值！\n");
				int x4 = 0;
				scanf(" %d", &x4);
				printf("请输入你要插入的位置！\n");
				int x5 = 0;
				scanf(" %d", &x5);
				if (x5<1 || x5>len)
				{
					printf("该位置不存在！");
					break;
				}
				//----------------------------------------
				//因为任意位置pos操作的都是后一个。所以在链表头部加一个NULL（NULL代表第0个），方便给用户使用
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
				printf("请输入你要删除的位置！\n");
				int x6 = 0;
				scanf(" %d", &x6);
				//因为任意位置pos操作的都是后一个。所以在链表头部加一个NULL（NULL代表第0个），方便给用户使用
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
				printf("enter error！\n");
				break;
		}
			
	}
	//----------------测试代码--------------------

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