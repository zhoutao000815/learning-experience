#include"seqlist.h"
void menu()
{
	printf("##################################################\n");
	printf("####1:初始化######2:销毁##########3:打印##########\n");
	printf("####4：pushback###5：popback######6：pushfront####\n");
	printf("####7：popfront###8：find#########9：insert#######\n");
	printf("####10：Earse ################### 0：exit ########\n");
	printf("####            select please!!           !#######\n");
}
//顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity)
{
	printf("初始化ing！\n");
	assert(psl != NULL);
	if (psl != NULL)
	{
		psl->capicity = 1;
		psl->size = 1;
	}
	psl->array = (SLDataType*)malloc((psl->capicity) * sizeof(SLDataType));////注意开辟空间大小是字节为单位，不是数据个数！！！笨蛋！！！
	if (psl->array != NULL)
	{	
		for (size_t i = 0; i < psl->size; i++)
		{
			psl->array[i] = 0;
		}
	}
	else
	{
		return;
	}
	printf("初始化成功！\n");
}
// 顺序表销毁
void SeqListDestory(SeqList* psl) 
{
	assert(psl != NULL);
	psl->size = 0;
	printf("销毁成功！\n");
}
// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->size == 0)
	{
		printf("无内容！\n");
	}
	else
	{
		for (size_t i = 0; i < psl->size; i++)
		{
			printf("位置：%3d  内容：%5d",i, psl->array[i]);
			printf("\n");
		}
	}
}
// 检查空间，如果满了，进行增容
static void CheckCapacity(SeqList* psl)
{
	while (psl->size == psl->capicity)
	{
		printf("容量已满，正在增容！\n");
		SLDataType *p = NULL;
		p = (SLDataType*)realloc(psl->array, (psl->capicity) * sizeof(SLDataType)* 2);//注意开辟空间大小是字节为单位，不是数据个数！！！笨蛋！！！
		if (p != NULL)
		{
			psl->array = p;
			psl->capicity = (psl->capicity) * 2;
			Sleep(3000);
			printf("增容成功！\n");
		}
		else
		{
			return;
		}
	}

}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	(psl->size)++;
	//方法二：
	//SeqListInsert(psl, size, x4);
}
// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl != NULL);
	psl->size--;
	//方法二：
	//SeqListErase(psl,size);
}
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl != NULL);
	CheckCapacity(psl);
	for (size_t i = psl->size; i > 0; i--)
	{
		psl->array[i] = psl->array[i-1];
	}
	(psl->size)++;
	psl->array[0] = x;
	//方法二:
	//SeqListInsert(psl,0, x4);
}
// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	assert(psl != NULL);
	for (size_t i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
	//方法二：
	//SeqListErase(psl, 0);
}
// 顺序表查找，返回数组下标
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl != NULL);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (x == psl->array[i])
		{
			return i;//返回数组下标。
		}
	}
	return NotFound;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl != NULL);
	if (pos<0 || pos>psl->size)
	{
		printf("该位置不存在！\n");
	}
	else
	{
		CheckCapacity(psl);
		for (size_t i = psl->size; i > pos;i--)
		{
			psl->array[i] = psl->array[i - 1];
		}
		psl->array[pos] = x;
		psl->size++;
	}
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl != NULL);
	for (size_t i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}