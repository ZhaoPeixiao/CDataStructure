#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

// 链表节点
typedef struct LINKNODE
{
	void* data;		// 指向任何类型的数据
	struct LINKNODE* next;
}LinkNode;

// 链表结构体
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
	// 不需要容量
}LinkList;

// 打印函数指针
typedef void(*PRINTLINKNODE)(void*);


// 初始化链表
LinkList* Init_LinkList();
// 指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* data);
// 删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos);
// 查找
int Find_LinkList(LinkList* list, void* data);
// 获得链表长度
int Size_LinkList(LinkList* list);
// 返回第一个节点
void* Front_LinkList(LinkList* list);
// 打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
// 释放链表内存
void FreeSpace_LinkList(LinkList* list);

#endif // !LINKLIST_H
