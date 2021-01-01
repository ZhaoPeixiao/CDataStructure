#include"CirlceLinkList.h"


// 初始化
CircleLinkList* Init_CircleLinkList()
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->size = 0;
	clist->head.next = &(clist->head);
	return clist;
}
// 插入
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > clist->size)
	{
		pos = clist->size;
	}

	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}
// 获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}
// 删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= clist->size)
	{
		return;
	}

	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	CircleLinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	//free(pDel);

	clist->size--;
}
// 根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	// 循环链表
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = pPrev->next;
	for (int pos = 0; pos < clist->size; pos++)
	{
		if (compare(pCurrent, data) == 1)
		{
			pPrev->next = pCurrent->next;
			clist->size--;
			return;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}

	return;
}
// 获得链表长度
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}
// 判断是否为空
int isEmpty_CircleLinkList(CircleLinkList* clist)
{
	if (clist->size == 0)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
// 查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	CircleLinkNode* pCurrent = clist->head.next;
	for (int pos = 0; pos < clist->size; pos++)
	{
		if (compare(pCurrent, data) == 1)
		{
			return pos;
		}
		pCurrent = pCurrent->next;
	}

	return -1;
}
// 打印
void Print_CircleLinkList(CircleLinkList* clist, PRINTLNODE print)
{
	if (clist == NULL)
	{
		return;
	}
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		//if (pCurrent == &(clist->head))
		//{
		//	pCurrent = pCurrent->next;
		//}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
// 释放内存
void Free_CircleLinkList(CircleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}

	free(clist);

}