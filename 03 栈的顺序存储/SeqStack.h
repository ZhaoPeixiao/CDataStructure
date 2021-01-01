#ifndef SEQSTACK_H
#define SEQSTACK_H


#include<stdlib.h>
#include<stdio.h>


// ������ģ��ջ��˳��洢
#define MAX_SIZE 1024

typedef struct SEQSTACK
{
	void* data[MAX_SIZE];
	int size;
}SeqStack;

// ��ʼ��
SeqStack* Init_Stack();
// ��ջ
void Push_Stack(SeqStack* stack, void* data);
// ����ջ��Ԫ��
void* Top_Stack(SeqStack* stack);
// ��ջ
void* Pop_Stack(SeqStack* stack);
// �Ƿ�Ϊ��
int IsEmpty(SeqStack* stack);
// ����ջ��Ԫ�ظ���
int Size_Stack(SeqStack* stack);
// ���
void Clear_Stack(SeqStack* stack);
// ����
void FreeSpace_Stack(SeqStack* stack);

#endif // !SEQSTACK_H
