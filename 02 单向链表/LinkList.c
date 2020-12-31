#include"LinkList.h"




// ��ʼ������
LinkList* Init_LinkList() 
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	// ͷ��㲻��������
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;

	return list;
}
// ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}
	// �ѺõĴ��� posԽ��򳬳�size Ĭ�ϲ��뵽β��
	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}

	// �����µĽڵ�
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	// �½ڵ�������
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	list->size++;
}
// ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	// ����ɾ���ڵ��ǰһ���ڵ�
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	// ����ɾ���Ľڵ�
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	// �ͷ�ɾ���ڵ���ڴ�
	free(pDel);

	list->size--;

}
// ����
int Find_LinkList(LinkList* list, void* data)
{
	if (list == NULL)
	{
		return -1;
	}

	if (data == NULL)
	{
		return -1;
	}

	// ��������
	LinkNode* pCurrent = list->head->next;
	int i = 0;
	while (pCurrent != NULL)
	{
		if (pCurrent->data == data)
		{
			return i;
		}
		i++;
		pCurrent = pCurrent->next;
	}

	return -1;
}
// ���������
int Size_LinkList(LinkList* list)
{
	return list->size;
}
// ���ص�һ���ڵ�
void* Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}
// ��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	// ����ָ�����
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
// �ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}

	// ����ָ�����
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		// ������һ���ڵ���ɾ����ǰ�ڵ�
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	// �ͷ������ڴ�
	list->size = 0;
	free(list);
}