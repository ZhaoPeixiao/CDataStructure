#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"


typedef struct MYCHAR
{
	LinkNode node;
	char* pAddress;
	int index;
}MyChar;

int isLeft(char c)
{
	return c == '(';
}

int isRight(char c)
{
	return c == ')';
}

MyChar* createMyChar(char* p)
{
	MyChar* myChar = (MyChar*)malloc(sizeof(MyChar));
	myChar->pAddress = p;

	return myChar;
}


int main(void)
{
	LinkStack* stack = Init_LinkStack();
	// #include <stdio.h> int main() {int a[4][4]; int (*p)[4]; p = a[0]; return 0;}
	char* str = "1+2+6(dfsd)asdkhj;((sad))";
	char* p = str;
	int flag = 1;
	while (*p != '\0')
	{
		// ◊Û¿®∫≈Ω¯’ª
		if (isLeft(*p))
		{
			Push_LinkStack(stack, (LinkNode*)createMyChar(p));
		}
		// ”“¿®∫≈≥ˆ’ª ≈–∂œ «∑ÒŒ™◊Û¿®∫≈
		if (isRight(*p))
		{
			if (Size_LinkStack(stack) > 0)
			{
				MyChar* myChar = (MyChar*)Top_LinkStack(stack);
				if (isLeft(*(myChar->pAddress)))
				{
					Pop_LinkStack(stack);
				}
				else {
					flag = 0;
					break;
				}
			}
			else {
				flag = 0;
				break;
			}
		}
		p++;
	}

	if (flag == 0)
	{
		printf("≤ª∆•≈‰£°\n");
	}
	else {
		if (Size_LinkStack(stack) != 0)
		{
			printf("≤ª∆•≈‰£°\n");
		}
		printf("∆•≈‰≥…π¶£°\n");
	}

	system("pause");

	return 0;
}