#ifndef SEQSTACK_H
#define SEQSTACK_H


#include<stdlib.h>
#include<stdio.h>


// 用数组模拟栈的顺序存储
#define MAX_SIZE 1024

typedef struct SEQSTACK
{
	void* data[MAX_SIZE];
	int size;
}SeqStack;

// 初始化
SeqStack* Init_Stack();
// 入栈
void Push_Stack(SeqStack* stack, void* data);
// 返回栈顶元素
void* Top_Stack(SeqStack* stack);
// 出栈
void* Pop_Stack(SeqStack* stack);
// 是否为空
int IsEmpty(SeqStack* stack);
// 返回栈中元素个数
int Size_Stack(SeqStack* stack);
// 清空
void Clear_Stack(SeqStack* stack);
// 销毁
void FreeSpace_Stack(SeqStack* stack);

#endif // !SEQSTACK_H
