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
	// ����ѭ������
	CircleLinkList* clist = Init_CircleLinkList();
	// �����������
	MyNum num[M];
	for (int i = 0; i < 8; i++)
	{
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
	}

	int index = 1;
	// ����ָ��
	CircleLinkNode* pCurrent = clist->head.next;
	while (Size_CircleLinkList(clist) > 1)
	{
		//MyNum* nCurrent = (MyNum*)pCurrent;
		//printf("������ %d\n", nCurrent->val);
		if (index == N)
		{
			MyNum* tmpNum = (MyNum*)pCurrent;
			printf("ɾ�� %d \n", tmpNum->val);
			// �����ɾ���ڵ����һ���ڵ�
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
		printf("����ʣ��ڵ� %d \n", res->val);
	}
	else {
		printf("������!\n");
	}

	// ��ӡ
	//Print_CircleLinkList(clist, MyPrint);

	// �ͷ�
	Free_CircleLinkList(clist);


	printf("\n");
	system("pause");

	return 0;
}