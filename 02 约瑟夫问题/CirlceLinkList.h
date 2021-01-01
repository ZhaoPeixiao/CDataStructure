#ifndef CIRCLELINKLIST
#define CIRCLELINKLIST


#include<stdlib.h>
#include<stdio.h>

// 链表节点
typedef struct CIRCLELINKNODE
{
	struct CIRCLELINKNODE* next;
}CircleLinkNode;

// 链表结构
typedef struct CIRCLELINKLIST
{
	CircleLinkNode head;
	int size;
}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

// 比较函数
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
// 打印函数
typedef void(*PRINTLNODE)(CircleLinkList*);

// API函数
// 初始化
CircleLinkList* Init_CircleLinkList();
// 插入
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);
// 获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);
// 删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);
// 根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);
// 获得链表长度
int Size_CircleLinkList(CircleLinkList* clist);
// 判断是否为空
int isEmpty_CircleLinkList(CircleLinkList* clist);
// 查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);
// 打印
void Print_CircleLinkList(CircleLinkList* clist, PRINTLNODE print);
// 释放内存
void Free_CircleLinkList(CircleLinkList* clist);

#endif // !CIRCLELINKLIST
