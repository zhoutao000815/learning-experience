#include"Contact.h"
int size = 0;
Person_s person[1000];
void menu()
{
	printf("*****************************************\n");
	printf("***1:Add*******2:del**********3:search***\n");
	printf("***4:revise****5:show*********6:clear****\n");
	printf("***7:qsort*****0:exit *******************\n");
	printf("*****************************************\n");
	printf("----------please select--------------\n");
}
void Add()
{
	if (size < 1000)
	{
		printf("��������ӵ��˵�����\n");
		scanf(" %s", person[size].name);
		printf("������Ҫ��ӵ��˵��Ա�\n");
		scanf(" %s", person[size].sex);
		printf("������Ҫ��ӵ��˵�����\n");
		scanf(" %d", person[size].age);
		printf("������Ҫ��ӵ��˵ĵ绰����\n");
		scanf(" %s", person[size].tel);
		printf("������Ҫ��ӵ��˵�סַ\n");
		scanf(" %s", person[size].adress);
		size++;
	}
	else
	{
		printf("����Ա��\n");
	}
	return ;
}
void Search()
{
	printf("���������һ򰴵绰������ң�\n");
	char key_name[20];
	char key_tel[20];
	scanf(" %s", &key_name);
	scanf(" %s", &key_tel);
	for (int i = 0; i < size; i++)
	{
		if (strstr(key_name, (const char*)person[i].name) != NULL || strstr(key_tel, (const char*)person[i].tel) != NULL)
		{
			printf("%s", person[i].name);
			printf("%s", person[i].tel);
			break;
		}
		else
		{
			printf("����ϵ�˻���ϵ��ʽ�����ڣ�\n");
		}
	}	
}
void Del()
{
	Show();
	printf("��������Ҫɾ�����ˣ�\n");
	char key_name[20];
	scanf(" %s", &key_name);
	for (int i = 0; i < size; i++)
	{
		if (strstr(key_name, (const char*)person[i].name) != NULL)
		{
			memcpy(person[i].name, person[size - 1].name, sizeof(Person_s));
			size--;
			printf("ɾ���ɹ���\n");
			break;
		}
		else
		{
			printf("����ϵ�˻���ϵ��ʽ�����ڣ�\n");
		}
	}
}
void Revise()
{
	Show();
	char key_name[20];
	printf("����������Ҫ�޸ĵ��ˣ�\n");
	scanf(" %s", &key_name);
	for (int i = 0; i < size; i++)
	{
		if (strstr(key_name, (const char*)person[i].name) != NULL )
		{
			printf("%10s", person[i].name);
			printf("%5s", person[i].sex);
			printf("%10d", person[i].age);
			printf("%10s", person[i].tel);
			printf("%10s", person[i].adress);
			printf("\n");
			printf("��ѡ��Ҫ�޸ĵ�����\n");
			printf("#1:name#####2:sex#####3:age#####4:tel#####5:adress#\n");
			int select = 0;
			scanf(" %d", &select);
			switch (select)
			{
			case 1:
				scanf(" %s", person[i].name);
				printf("�޸ĳɹ���\n");
				break;
			case 2:
				scanf(" %s", person[i].sex);
				printf("�޸ĳɹ���\n");
				break;
			case 3:
				scanf(" %d", person[i].age);
				printf("�޸ĳɹ���\n");
				break;
			case 4:
				scanf(" %s", person[i].tel);
				printf("�޸ĳɹ���\n");
				break;
			case 5:
				scanf(" %s", person[i].adress);
				printf("�޸ĳɹ���\n");
				break;
			default:
				break;
			}
		}
		else
		{
			printf("����ϵ�˻���ϵ��ʽ�����ڣ�\n");
		}
	}

}
void Show()
{ 
	if (size == 0)
	{
		printf("����ϵ��!\n");
	}
	for (int i = 0; i < size; i++)
	{
		printf("%s %s %s %s %s", person[i].name, person[i].sex, person[i].age, person[i].tel,person[i].adress);
		printf("\n");
	}
}
void Clear()
{
	Show();
	printf("ȷ�������\n");
	printf("1:ȷ���� 0��������˳���\n");
	int sure;
	scanf(" %d", &sure);
	if (sure)
	{
		size = 0;
		printf("�����ɣ�\n");
	}
	else
	{
		return;
	}
}
int MY_strcmp(const void*p1,const void*p2)
{
	return 0;
}
void Qsort()
{
	qsort(person, size, sizeof(person[0].name),MY_strcmp);
}
