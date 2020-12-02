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
		printf("请输入添加的人的名字\n");
		scanf(" %s", person[size].name);
		printf("请输入要添加的人的性别\n");
		scanf(" %s", person[size].sex);
		printf("请输入要添加的人的年龄\n");
		scanf(" %d", person[size].age);
		printf("请输入要添加的人的电话号码\n");
		scanf(" %s", person[size].tel);
		printf("请输入要添加的人的住址\n");
		scanf(" %s", person[size].adress);
		size++;
	}
	else
	{
		printf("已满员！\n");
	}
	return ;
}
void Search()
{
	printf("按人名查找或按电话号码查找！\n");
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
			printf("该联系人或联系方式不存在！\n");
		}
	}	
}
void Del()
{
	Show();
	printf("请输入你要删除的人！\n");
	char key_name[20];
	scanf(" %s", &key_name);
	for (int i = 0; i < size; i++)
	{
		if (strstr(key_name, (const char*)person[i].name) != NULL)
		{
			memcpy(person[i].name, person[size - 1].name, sizeof(Person_s));
			size--;
			printf("删除成功！\n");
			break;
		}
		else
		{
			printf("该联系人或联系方式不存在！\n");
		}
	}
}
void Revise()
{
	Show();
	char key_name[20];
	printf("请输入你想要修改的人！\n");
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
			printf("请选择要修改的内容\n");
			printf("#1:name#####2:sex#####3:age#####4:tel#####5:adress#\n");
			int select = 0;
			scanf(" %d", &select);
			switch (select)
			{
			case 1:
				scanf(" %s", person[i].name);
				printf("修改成功！\n");
				break;
			case 2:
				scanf(" %s", person[i].sex);
				printf("修改成功！\n");
				break;
			case 3:
				scanf(" %d", person[i].age);
				printf("修改成功！\n");
				break;
			case 4:
				scanf(" %s", person[i].tel);
				printf("修改成功！\n");
				break;
			case 5:
				scanf(" %s", person[i].adress);
				printf("修改成功！\n");
				break;
			default:
				break;
			}
		}
		else
		{
			printf("该联系人或联系方式不存在！\n");
		}
	}

}
void Show()
{ 
	if (size == 0)
	{
		printf("无联系人!\n");
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
	printf("确认清空吗？\n");
	printf("1:确定。 0：不清空退出。\n");
	int sure;
	scanf(" %d", &sure);
	if (sure)
	{
		size = 0;
		printf("清空完成！\n");
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
