#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"


typedef struct MYNUM
{
	LinkNode node;
	int val;
}MyNum;

MyNum* createMyNum(char* p)
{
	MyNum* myNum = (MyNum*)malloc(sizeof(MyNum));
	myNum->val = *p - '0';
	return myNum;
}


int isNum(char c)
{
	return c >= '0' && c <= '9';
}
void NumOperator(char* c, LinkStack* stack)
{
	Push_LinkStack(stack, (LinkNode*)createMyNum(c));
}



int isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
void operatorOperator(char* c, LinkStack* stack)
{
	MyNum* rightNum = (MyNum*)Top_LinkStack(stack);
	int right = rightNum->val;
	Pop_LinkStack(stack);
	MyNum* leftNum = (MyNum*)Top_LinkStack(stack);
	int left = leftNum->val;
	Pop_LinkStack(stack);
	int res = 0;
	switch (*c)
	{
	case '+':
		res = left + right;
		break;
	case '-':
		res = left - right;
		break;
	case '*':
		res = left * right;
		break;
	case '/':
		if (right == 0)
		{
			right = 1;
		}
		res = left / right;
		break;
	default:
		break;
	}
	//printf("left: %d, right: %d, operator: %c, res: %d\n", left, right, *c, res);
	MyNum* myNum = (MyNum*)malloc(sizeof(MyNum));
	myNum->val = res;
	Push_LinkStack(stack, (LinkNode*)myNum);
	free(rightNum);
	free(leftNum);
}

int main(void)
{
	LinkStack* stack = Init_LinkStack();
	char* str = "831-5*+";
	char* p = str;

	while (*p != '\0')
	{
		if (isNum(*p))
		{
			NumOperator(p, stack);
		}

		if (isOperator(*p))
		{
			operatorOperator(p, stack);
		}
		p++;
	}

	MyNum* res = (MyNum*)Top_LinkStack(stack);
	printf("%d", res->val);
	printf("\n");
	system("pause");

	return 0;
}