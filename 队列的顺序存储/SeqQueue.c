#include"SeqQueue.h"

//Init
SeqQueue* Init_SeqQueue()
{
	SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;
	return queue;
}
// Add
void Add_SeqQueue(SeqQueue* queue, void* data)
{
	if (queue == NULL || queue->size == MAX_SIZE || data == NULL)
	{
		return;
	}

	queue->data[queue->size] = data;
	queue->size++;

}
// Front
void* Front_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL || queue->size == 0)
	{
		return NULL;
	}
	return queue->data[0];
}
// Back
void* Back_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL || queue->size == 0)
	{
		return NULL;
	}
	return queue->data[queue->size - 1];;
}
// Pop
void* Pop_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL || queue->size == 0)
	{
		return NULL;
	}
	void* data = queue->data[0];
	for (int i = 0; i < queue->size - 1; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
	return data;
}
// Size
int Size_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->size;
}
// Clear
void Clear_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;
}
// Free
void FreeSpace_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
}