#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"DynamicArray.h"

void test01() {
	// ��ʼ����̬����
	Dynamic_Array* myArray = Init_Array();
	// ����
	printf("��������:%d\n", Capacity_Array(myArray));
	printf("�����С:%d\n", Size_Array(myArray));
	// ����Ԫ��
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(myArray, i);
	}
	// ��ӡ
	Print_Array(myArray);
	// ����
	//printf("��������:%d\n", Capacity_Array(myArray));
	//printf("�����С:%d\n", Size_Array(myArray));
	// ɾ��
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	Print_Array(myArray);
	// ����
	int pos = Find_Array(myArray, 5);
	printf("λ��:%d, ֵ:%d\n", pos, At_Array(myArray, pos));

	// �ͷ�
	FreeSpace_Array(myArray);
}


int main(void)
{

	test01();

	system("pause");
	return 0;
}


