#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

typedef struct PERSON
{
	char name[64];
	int age;
}Person;

int main(void)
{
	SeqStack* stack = Init_Stack();

	Person p1 = { "aaa", 20 };
	Person p2 = { "bbb", 30 };
	Person p3 = { "ccc", 40 };
	Person p4 = { "ddd", 50 };
	Person p5 = { "eee", 60 };

	Push_Stack(stack, &p1);
	Push_Stack(stack, &p2);
	Push_Stack(stack, &p3);
	Push_Stack(stack, &p4);
	Push_Stack(stack, &p5);

	while (Size_Stack(stack) > 0)
	{
		Person* person = (Person*)Pop_Stack(stack);
		printf("name: %s, age: %d\n", person->name, person->age);
	}


	FreeSpace_Stack(stack);
	system("pause");

	return 0;
}


