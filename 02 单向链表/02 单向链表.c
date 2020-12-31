#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkList.h"

// �Զ�����������
typedef struct PERSON
{
	char name[64];
	int age;
	int score;

}Person;

// ��ӡ����
void MyPrint(void* data)
{
	Person* p = (Person*)data;
	printf("name: %s, age: %d, score:%d\n", p->name, p->age, p->score);
}


int main(void)
{
	LinkList* list = Init_LinkList();

	Person p1 = { "aaa", 18, 100};
	Person p2 = { "bbb", 19, 90};
	Person p3 = { "ccc", 20, 80};
	Person p4 = { "ddd", 21, 70};
	Person p5 = { "eee", 22, 60};

	// ���ݲ�������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	// ��ӡ
	Print_LinkList(list, MyPrint);

	// ɾ��
	RemoveByPos_LinkList(list, 3);
	printf("ɾ��\n");
	// ��ӡ
	Print_LinkList(list, MyPrint);

	Person* ret = (Person*)Front_LinkList(list);
	printf("���ҽ��");
	printf("name: %s, age: %d, score:%d\n", ret->name, ret->age, ret->score);

	// ����
	FreeSpace_LinkList(list);

	printf("\n");
	system("pause");

	return 0;
}