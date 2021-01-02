#include"LinkStack.h"

// Init
LinkStack* Init_LinkStack()
{
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
// Push
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == NULL || data == NULL)
	{
		return;
	}

	data->next = stack->head.next;
	stack->head.next = data;

	stack->size++;
}
// Pop
void Pop_LinkStack(LinkStack* stack) {

	if (stack == NULL || stack->size == 0)
	{
		return;
	}

	LinkNode* pDel = stack->head.next;
	stack->head.next = pDel->next;

	stack->size--;
}
// Top
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == NULL || stack->size == 0)
	{
		return NULL;
	}

	return stack->head.next;
}
// Size
int Size_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return 0;
	}
	return stack->size;
}
// Clear
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	stack->head.next = NULL;
	stack->size = 0;
}
// Free
void FreeSpace_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
}