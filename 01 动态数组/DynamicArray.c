#include"DynamicArray.h"


// ��ʼ��
Dynamic_Array* Init_Array() {
	// �����ڴ�
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	// ��ʼ��
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAdder = (int*)malloc(sizeof(int) * myArray->capacity);

	return myArray;
}

// ����
void PushBack_Array(Dynamic_Array* array, int value) {
	if (array == NULL)
	{
		return;
	}

	// �жϿռ��Ƿ��㹻
	if (array->size == array->capacity)
	{
		// ��һ�� ��������ڴ�ռ� �¿ռ��Ǿɿռ������
		int* newSpace = (int*)malloc(sizeof(int) * array->capacity * 2);
		// �ڶ��� �������ݵ��µĿռ�
		memcpy(newSpace, array->pAdder, array->capacity * sizeof(int));
		// ������ �ͷžɿռ���ڴ�
		free(array->pAdder);
		// ��������
		array->capacity = array->capacity * 2;
		array->pAdder = newSpace;
	}

	// ������Ԫ��
	array->pAdder[array->size] = value;
	array->size++;
}

// ����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array* array, int pos) {
	if (array == NULL)
	{
		return;
	}

	// �ж�λ���Ƿ���Ч
	if (pos < 0 || pos >= array->size)
	{
		return;
	}

	// ɾ��Ԫ��
	for (int i = pos; i < array->size - 1; i++)
	{
		array->pAdder[i] = array->pAdder[i + 1];
	}
	array->size--;
}

// ����ֵɾ����һ�γ��ֵ�λ��
void RemoveByValue_Array(Dynamic_Array* array, int value) {
	if (array == NULL)
	{
		return;
	}
	int pos = Find_Array(array, value);
	RemoveByPos_Array(array, pos);
}

// ����
int Find_Array(Dynamic_Array* array, int value) {
	if (array == NULL)
	{
		return -1;
	}

	for (int i = 0; i < array->size; i++)
	{
		if (array->pAdder[i] == value)
		{
			return i;
		}
	}

	return -1;
}

// ��ӡ
void Print_Array(Dynamic_Array* array) {
	if (array == NULL)
	{
		return;
	}

	for (int i = 0; i < array->size; i++)
	{
		printf("%d ", array->pAdder[i]);
	}
	printf("\n");
}

// �ͷŶ�̬�����ڴ�
void FreeSpace_Array(Dynamic_Array* array) {
	if (array == NULL)
	{
		return;
	}

	if (array->pAdder != NULL)
	{
		free(array->pAdder);
	}
	free(array);
}

// �������
void Clear_Array(Dynamic_Array* array) {
	if (array == NULL)
	{
		return;
	}
	// pAdder -> �ռ�


	array->size = 0;
}

// ��ö�̬��������
int Capacity_Array(Dynamic_Array* array) {
	if (array == NULL)
	{
		return -1;
	}

	return array->capacity;

}

// ��ö�̬����Ԫ�ظ���
int Size_Array(Dynamic_Array* array) {

	if (array == NULL)
	{
		return -1;
	}

	return array->size;
}

// ����λ�û��Ԫ��
int At_Array(Dynamic_Array* array, int pos) {

	return array->pAdder[pos];
}