#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

typedef struct MYCHAR
{
	LinkNode node;
	char* p;
}MyChar;

MyChar* createMyChar(char* p)
{
	MyChar* myChar = (MyChar*)malloc(sizeof(MyChar));
	myChar->p = p;
	return myChar;
}

int isNum(char c)
{
	return c >= '0' && c <= '9';
}
void NumOperator(char* c)
{
	printf("%c", *c);
}

int isLeft(char c)
{
	return c == '(';
}
void leftOperator(char* c, LinkStack* stack)
{
	Push_LinkStack(stack, (LinkNode*)createMyChar(c));
}


int isRight(char c)
{
	return c == ')';
}
void rightOperator(LinkStack* stack)
{
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* myChar = (MyChar*)Top_LinkStack(stack);
		if (isLeft(*(myChar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		printf("%c", *(myChar->p));
		Pop_LinkStack(stack);
		free(myChar);
	}
}

int isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
int getPriority(char c)
{
	if (c == '*' || c == '/')
	{
		return 2;
	}
	if (c == '+' || c == '-')
	{
		return 1;
	}
	return 0;
}
void operatorOperator(char* c, LinkStack* stack)
{
	MyChar* topChar = (MyChar*)Top_LinkStack(stack);
	if (topChar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)createMyChar(c));
		return;
	}
	int topPriority = getPriority(*(topChar->p));
	int priority = getPriority(*c);
	if (topPriority < priority)
	{
		Push_LinkStack(stack, (LinkNode*)createMyChar(c));
		return;
	}
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			MyChar* topChar2 = (MyChar*)Top_LinkStack(stack);
			if (getPriority(*(topChar2->p)) < getPriority(*c))
			{
				Push_LinkStack(stack, (LinkNode*)createMyChar(c));
				break;
			}
			printf("%c", *(topChar2->p));
			Pop_LinkStack(stack);
			free(topChar2);
		}
		return;
	}
}



int main(void)
{
	LinkStack* stack = Init_LinkStack();
	char* str = "8 + (3 - 1) * 5";
	char* p = str;

	while (*p != '\0')
	{
		if (isNum(*p))
		{
			NumOperator(p);
		}
		if (isLeft(*p))
		{
			leftOperator(p, stack);
		}


		if (isRight(*p))
		{
			rightOperator(stack);
		}

		if(isOperator(*p))
		{
			operatorOperator(p, stack);
		}

		p++;
	}

	while(Size_LinkStack(stack) > 0)
	{
		MyChar* myChar = (MyChar*)Top_LinkStack(stack);
		printf("%c", *(myChar->p));
		Pop_LinkStack(stack);
		free(myChar);
	}

	printf("\n");
	system("pause");

	return 0;
}
