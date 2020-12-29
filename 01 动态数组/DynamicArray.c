#include"DynamicArray.h"


// 初始化
Dynamic_Array* Init_Array() {
	// 申请内存
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	// 初始化
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAdder = (int*)malloc(sizeof(int) * myArray->capacity);

	return myArray;
}

// 插入
void PushBack_Array(Dynamic_Array* array, int value) {
	if (array == NULL)
	{
		return;
	}

	// 判断空间是否足够
	if (array->size == array->capacity)
	{
		// 第一步 申请更大内存空间 新空间是旧空间的两倍
		int* newSpace = (int*)malloc(sizeof(int) * array->capacity * 2);
		// 第二步 拷贝数据到新的空间
		memcpy(newSpace, array->pAdder, array->capacity * sizeof(int));
		// 第三步 释放旧空间的内存
		free(array->pAdder);
		// 更新容量
		array->capacity = array->capacity * 2;
		array->pAdder = newSpace;
	}

	// 插入新元素
	array->pAdder[array->size] = value;
	array->size++;
}

// 根据位置删除
void RemoveByPos_Array(Dynamic_Array* array, int pos) {
	if (array == NULL)
	{
		return;
	}

	// 判断位置是否有效
	if (pos < 0 || pos >= array->size)
	{
		return;
	}

	// 删除元素
	for (int i = pos; i < array->size - 1; i++)
	{
		array->pAdder[i] = array->pAdder[i + 1];
	}
	array->size--;
}

// 根据值删除第一次出现的位置
void RemoveByValue_Array(Dynamic_Array* array, int value) {
	if (array == NULL)
	{
		return;
	}
	int pos = Find_Array(array, value);
	RemoveByPos_Array(array, pos);
}

// 查找
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

// 打印
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

// 释放动态数组内存
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

// 清空数组
void Clear_Array(Dynamic_Array* array) {
	if (array == NULL)
	{
		return;
	}
	// pAdder -> 空间


	array->size = 0;
}

// 获得动态数组容量
int Capacity_Array(Dynamic_Array* array) {
	if (array == NULL)
	{
		return -1;
	}

	return array->capacity;

}

// 获得动态数组元素个数
int Size_Array(Dynamic_Array* array) {

	if (array == NULL)
	{
		return -1;
	}

	return array->size;
}

// 根据位置获得元素
int At_Array(Dynamic_Array* array, int pos) {

	return array->pAdder[pos];
}