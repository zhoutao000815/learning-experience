//======================Stack的测试代码=====================
//#include"Stack.h"
//int main()
//{
//	Stack*ps = NULL;
//	ps = StackInit(ps);
//
//	StackEmpty(ps);
//	StackPush(ps, 1);
//	StackTop(ps);
//
//	StackPush(ps, 2);
//	StackTop(ps);
//
//	StackPush(ps, 3);
//	StackTop(ps);
//
//	StackPop(ps);
//	StackTop(ps);
//
//	StackSize(ps);
//	StackEmpty(ps);
//	StackDestroy(ps);
//	StackEmpty(ps);
//	system("pause");
//}
//======================Qlist的测试代码======================
#include"QList.h"
int main()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, 0);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);

	QueueFront(q);
	QueueBack(q);

	QueuePop(q);

	QueueFront(q);
	QueueBack(q);
	QueueSize(q);

	QueueEmpty(q);

	QueueDestroy(q);

	QueueSize(q);

	QueueEmpty(q);
	system("pause");
}