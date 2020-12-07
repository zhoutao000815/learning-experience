#include"seqlist.h"
void menu()
{
	printf("##################################################\n");
	printf("####1:��ʼ��######2:����##########3:��ӡ##########\n");
	printf("####4��pushback###5��popback######6��pushfront####\n");
	printf("####7��popfront###8��find#########9��insert#######\n");
	printf("####10��Earse ################### 0��exit ########\n");
	printf("####            select please!!           !#######\n");
}
//˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity)
{
	printf("��ʼ��ing��\n");
	assert(psl != NULL);
	if (psl != NULL)
	{
		psl->capicity = 1;
		psl->size = 1;
	}
	psl->array = (SLDataType*)malloc((psl->capicity) * sizeof(SLDataType));////ע�⿪�ٿռ��С���ֽ�Ϊ��λ���������ݸ�������������������
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
	printf("��ʼ���ɹ���\n");
}
// ˳�������
void SeqListDestory(SeqList* psl) 
{
	assert(psl != NULL);
	psl->size = 0;
	printf("���ٳɹ���\n");
}
// ˳����ӡ
void SeqListPrint(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->size == 0)
	{
		printf("�����ݣ�\n");
	}
	else
	{
		for (size_t i = 0; i < psl->size; i++)
		{
			printf("λ�ã�%3d  ���ݣ�%5d",i, psl->array[i]);
			printf("\n");
		}
	}
}
// ���ռ䣬������ˣ���������
static void CheckCapacity(SeqList* psl)
{
	while (psl->size == psl->capicity)
	{
		printf("�����������������ݣ�\n");
		SLDataType *p = NULL;
		p = (SLDataType*)realloc(psl->array, (psl->capicity) * sizeof(SLDataType)* 2);//ע�⿪�ٿռ��С���ֽ�Ϊ��λ���������ݸ�������������������
		if (p != NULL)
		{
			psl->array = p;
			psl->capicity = (psl->capicity) * 2;
			Sleep(3000);
			printf("���ݳɹ���\n");
		}
		else
		{
			return;
		}
	}

}
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	(psl->size)++;
	//��������
	//SeqListInsert(psl, size, x4);
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl != NULL);
	psl->size--;
	//��������
	//SeqListErase(psl,size);
}
// ˳���ͷ��
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
	//������:
	//SeqListInsert(psl,0, x4);
}
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl != NULL);
	for (size_t i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
	//��������
	//SeqListErase(psl, 0);
}
// ˳�����ң����������±�
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl != NULL);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (x == psl->array[i])
		{
			return i;//���������±ꡣ
		}
	}
	return NotFound;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl != NULL);
	if (pos<0 || pos>psl->size)
	{
		printf("��λ�ò����ڣ�\n");
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

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl != NULL);
	for (size_t i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}