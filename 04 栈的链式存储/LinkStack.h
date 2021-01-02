#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdlib.h>
#include<stdio.h>

// ½Úµã
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

// Á´Ê½Õ»
typedef struct LINKSTACK
{
	LinkNode head;
	int size;
}LinkStack;


// Init
LinkStack* Init_LinkStack();
// Push
void Push_LinkStack(LinkStack* stack, LinkNode* data);
// Pop
void Pop_LinkStack(LinkStack* stack);
// Top
LinkNode* Top_LinkStack(LinkStack* stack);
// Size
int Size_LinkStack(LinkStack* stack);
// Clear
void Clear_LinkStack(LinkStack* stack);
// Free
void FreeSpace_LinkStack(LinkStack* stack);


#endif // !LINKSTACK_H
