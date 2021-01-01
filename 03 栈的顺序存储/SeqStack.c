#include"SeqStack.h"

#define STACK_TRUE 1
#define STACK_FALSE 0

// ��ʼ��
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
// ��ջ
void Push_Stack(SeqStack* stack, void* data)
{
	if (stack == NULL || stack->size == MAX_SIZE || data == NULL)
	{
		return;
	}

	stack->data[stack->size] = data;
	stack->size++;
}
// ����ջ��Ԫ��
void* Top_Stack(SeqStack* stack)
{
	if (stack == NULL || stack->size == 0)
	{
		return NULL;
	}

	return stack->data[stack->size - 1];
}
// ��ջ
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
// �Ƿ�Ϊ��
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
// ����ջ��Ԫ�ظ���
int Size_Stack(SeqStack* stack) {

	return stack->size;
}
// ���
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
// ����
void FreeSpace_Stack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}