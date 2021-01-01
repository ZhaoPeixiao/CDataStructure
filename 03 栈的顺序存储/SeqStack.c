#include"SeqStack.h"

#define STACK_TRUE 1
#define STACK_FALSE 0

// 初始化
SeqStack* Init_Stack()
{
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
// 入栈
void Push_Stack(SeqStack* stack, void* data)
{
	if (stack == NULL || stack->size == MAX_SIZE || data == NULL)
	{
		return;
	}

	stack->data[stack->size] = data;
	stack->size++;
}
// 返回栈顶元素
void* Top_Stack(SeqStack* stack)
{
	if (stack == NULL || stack->size == 0)
	{
		return NULL;
	}

	return stack->data[stack->size - 1];
}
// 出栈
void* Pop_Stack(SeqStack* stack)
{
	if (stack == NULL || stack->size == 0)
	{
		return;
	}
	void* data = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = NULL;
	stack->size--;
	return data;
}
// 是否为空
int IsEmpty(SeqStack* stack) {
	if (stack == NULL)
	{
		return -1;
	}
	if (stack->size == 0)
	{
		return STACK_TRUE;
	}

	return STACK_FALSE;
}
// 返回栈中元素个数
int Size_Stack(SeqStack* stack) {

	return stack->size;
}
// 清空
void Clear_Stack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	for (int i = 0; i < stack->size; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
}
// 销毁
void FreeSpace_Stack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}