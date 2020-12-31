#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CirlceLinkList.h"

typedef struct PERSON
{
	CircleLinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(CircleLinkNode* data)
{
	Person* p = (Person*)data;
	printf("name: %s, age: %d\n", p->name, p->age);

}

int MyCompare(CircleLinkNode* node1, CircleLinkNode* node2)
{
	Person* p1 = (Person*)node1;
	Person* p2 = (Person*)node2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return 1;
	}

	return 0;
}


int main(void)
{
	// 创建循环链表
	CircleLinkList* clist = Init_CircleLinkList();

	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;

	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p5);


	RemoveByPos_CircleLinkList(clist, 3);
	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&p1, MyCompare);

	Print_CircleLinkList(clist, MyPrint);
	printf("链表的元素个数为 %d\n", Size_CircleLinkList(clist));
	printf("链表是否为空 %d\n", isEmpty_CircleLinkList(clist));

	Free_CircleLinkList(clist);
	system("pause");

	return 0;
}
