#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CirlceLinkList.h"


#define M 8
#define N 3

typedef struct MYNUM
{
	CircleLinkNode node;
	int val;
}MyNum;


void MyPrint(CircleLinkNode* data)
{
	MyNum* num = (MyNum*)data;
	printf("%d ", num->val);
}

int MyCompare(CircleLinkNode* node1, CircleLinkNode* node2)
{
	MyNum* p1 = (MyNum*)node1;
	MyNum* p2 = (MyNum*)node2;

	if (p1->val == p2->val)
	{
		return 1;
	}

	return 0;
}

int main(void)
{
	// 创建循环链表
	CircleLinkList* clist = Init_CircleLinkList();
	// 链表插入数据
	MyNum num[M];
	for (int i = 0; i < 8; i++)
	{
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
	}

	int index = 1;
	// 辅助指针
	CircleLinkNode* pCurrent = clist->head.next;
	while (Size_CircleLinkList(clist) > 1)
	{
		//MyNum* nCurrent = (MyNum*)pCurrent;
		//printf("现在在 %d\n", nCurrent->val);
		if (index == N)
		{
			MyNum* tmpNum = (MyNum*)pCurrent;
			printf("删除 %d \n", tmpNum->val);
			// 缓存待删除节点的下一个节点
			CircleLinkNode* pNext = pCurrent->next;
			RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
			pCurrent = pNext;
			if (pCurrent == &(clist->head))
			{
				pCurrent = pCurrent->next;
			}
			index = 1;
		}
		pCurrent = pCurrent->next;
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		index++;
	}

	if (Size_CircleLinkList(clist) == 1)
	{
		MyNum* res = (MyNum*)Front_CircleLinkList(clist);
		printf("最终剩余节点 %d \n", res->val);
	}
	else {
		printf("出错了!\n");
	}

	// 打印
	//Print_CircleLinkList(clist, MyPrint);

	// 释放
	Free_CircleLinkList(clist);


	printf("\n");
	system("pause");

	return 0;
}