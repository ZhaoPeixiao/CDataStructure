#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 20000

void swap(int* a, int* b);

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);

	return tb.time * 1000 + tb.millitm;
}

int flag = 0; // 提前终止标记

void bubbleSort(int arr[], int length)
{
	for (int i = 0; i < length - 1 && flag == 0; i++)
	{
		flag = 1;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(&arr[j + 1], &arr[j]);
				flag = 0;
			}
		}
	}
}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	//printf("Before\n");
	//printArray(arr, MAX);
	long t_start = getSystemTime();
	bubbleSort(arr, MAX);
	long t_end = getSystemTime();
	//printf("After-------\n");
	printf("Time for %d nums is:  %ld\n", MAX, (t_end - t_start));
	// Time for 10000 nums is:  640
	// Time for 20000 nums is:  2623
	// time: O(n^2) space: O(1) 稳定
	//printArray(arr, MAX);
	system("pause");

	return 0;
}