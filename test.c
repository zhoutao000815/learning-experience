#include"ListNode.h"
int main()//²âÊÔ´úÂë
{
	ListNode*plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPushFront(plist,0);
	ListPushFront(plist, -1);
	ListPushFront(plist, -2);
	ListPushFront(plist, -3);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListNode*pos=ListFind(plist,0);

	ListErase(pos);
	ListPrint(plist);

	ListInsert(plist->_next, -2);
	ListPrint(plist);

	ListDestory(&plist);
	ListPrint(plist);
	system("pause");
}