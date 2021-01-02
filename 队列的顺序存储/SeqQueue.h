#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include<stdlib.h>
#include<stdio.h>

#define MAX_SIZE 1024

typedef struct SEQQUEUE
{
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//Init
SeqQueue* Init_SeqQueue();
// Add
void Add_SeqQueue(SeqQueue* queue, void* data);
// Front
void* Front_SeqQueue(SeqQueue* queue);
// Back
void* Back_SeqQueue(SeqQueue* queue);
// Pop
void* Pop_SeqQueue(SeqQueue* queue);
// Size
int Size_SeqQueue(SeqQueue* queue);
// Clear
void Clear_SeqQueue(SeqQueue* queue);
// Free
void FreeSpace_SeqQueue(SeqQueue* queue);



#endif // !SEQQUEUE_H
