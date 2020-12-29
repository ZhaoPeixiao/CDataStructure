#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"DynamicArray.h"

void test01() {
	// 初始化动态数组
	Dynamic_Array* myArray = Init_Array();
	// 容量
	printf("数组容量:%d\n", Capacity_Array(myArray));
	printf("数组大小:%d\n", Size_Array(myArray));
	// 插入元素
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(myArray, i);
	}
	// 打印
	Print_Array(myArray);
	// 容量
	//printf("数组容量:%d\n", Capacity_Array(myArray));
	//printf("数组大小:%d\n", Size_Array(myArray));
	// 删除
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	Print_Array(myArray);
	// 查找
	int pos = Find_Array(myArray, 5);
	printf("位置:%d, 值:%d\n", pos, At_Array(myArray, pos));

	// 释放
	FreeSpace_Array(myArray);
}


int main(void)
{

	test01();

	system("pause");
	return 0;
}


