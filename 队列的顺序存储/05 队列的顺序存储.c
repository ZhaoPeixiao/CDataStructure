#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"
typedef struct PERSON
{
	char name[64];
	int age;
}Person;


int main(void)
{
	SeqQueue* queue = Init_SeqQueue();

	Person p1 = { "aaa", 20 };
	Person p2 = { "bbb", 30 };
	Person p3 = { "ccc", 40 };
	Person p4 = { "ddd", 50 };
	Person p5 = { "eee", 60 };

	Add_SeqQueue(queue, &p1);
	Add_SeqQueue(queue, &p2);
	Add_SeqQueue(queue, &p3);
	Add_SeqQueue(queue, &p4);
	Add_SeqQueue(queue, &p5);

	Person* back = (Person*)Back_SeqQueue(queue);
	printf("Ä©Î²ÔªËØ name: %s, age: %d\n", back->name, back->age);

	while (Size_SeqQueue(queue) > 0)
	{
		Person* person = (Person*)Pop_SeqQueue(queue);
		printf("name: %s, age: %d\n", person->name, person->age);
	}

	FreeSpace_SeqQueue(queue);
	system("pause");

	return 0;
}