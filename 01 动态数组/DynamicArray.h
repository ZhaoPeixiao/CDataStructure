#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 动态增长内存 策略 将存放数据的内存放到堆上
// 申请内存 -> 拷贝数据 -> 释放内存 低效
// capacity 先申请大空间 然后满了再申请更大空间
// size 记录当前数组具体的元素个数


typedef struct DYNAMICARRAY {

	int* pAdder;		// 存放数据的地址
	int size;			// 当前元素个数
	int capacity;		// 容量

}Dynamic_Array;

// 一系列相关对结构体操作的函数
// 初始化
Dynamic_Array* Init_Array();
// 插入
void PushBack_Array(Dynamic_Array* array, int value);
// 根据位置删除
void RemoveByPos_Array(Dynamic_Array* array, int pos);
// 根据值删除
void RemoveByValue_Array(Dynamic_Array* array, int value);
// 查找
int Find_Array(Dynamic_Array* array, int value);
// 打印
void Print_Array(Dynamic_Array* array);
// 释放动态数组内存
void FreeSpace_Array(Dynamic_Array* array);
// 清空数组
void Clear_Array(Dynamic_Array* array);
// 获得动态数组容量
int Capacity_Array(Dynamic_Array* array);
// 获得动态数组元素个数
int Size_Array(Dynamic_Array* array);
// 根据位置获得元素
int At_Array(Dynamic_Array* array, int pos);

#endif
