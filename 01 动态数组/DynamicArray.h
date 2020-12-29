#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��̬�����ڴ� ���� ��������ݵ��ڴ�ŵ�����
// �����ڴ� -> �������� -> �ͷ��ڴ� ��Ч
// capacity �������ռ� Ȼ���������������ռ�
// size ��¼��ǰ��������Ԫ�ظ���


typedef struct DYNAMICARRAY {

	int* pAdder;		// ������ݵĵ�ַ
	int size;			// ��ǰԪ�ظ���
	int capacity;		// ����

}Dynamic_Array;

// һϵ����ضԽṹ������ĺ���
// ��ʼ��
Dynamic_Array* Init_Array();
// ����
void PushBack_Array(Dynamic_Array* array, int value);
// ����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array* array, int pos);
// ����ֵɾ��
void RemoveByValue_Array(Dynamic_Array* array, int value);
// ����
int Find_Array(Dynamic_Array* array, int value);
// ��ӡ
void Print_Array(Dynamic_Array* array);
// �ͷŶ�̬�����ڴ�
void FreeSpace_Array(Dynamic_Array* array);
// �������
void Clear_Array(Dynamic_Array* array);
// ��ö�̬��������
int Capacity_Array(Dynamic_Array* array);
// ��ö�̬����Ԫ�ظ���
int Size_Array(Dynamic_Array* array);
// ����λ�û��Ԫ��
int At_Array(Dynamic_Array* array, int pos);

#endif
