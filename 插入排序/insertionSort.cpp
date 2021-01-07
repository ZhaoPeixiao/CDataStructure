#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 20

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);

	return tb.time * 1000 + tb.millitm;
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


void insertionSort(int arr[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int insertNum = arr[i];
		int insertIndex;
		for (insertIndex = i - 1; insertIndex >= 0 && arr[insertIndex] > insertNum; insertIndex--)
		{
			swap(&arr[insertIndex + 1], &arr[insertIndex]);
		}
		arr[insertIndex + 1] = insertNum;
	}
}



int main(void)
{
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	printf("Before\n");
	printArray(arr, MAX);
	//long t_start = getSystemTime();
	insertionSort(arr, MAX);
	//long t_end = getSystemTime();
	printf("After-------\n");
	//printf("Time for %d nums is:  %ld\n", MAX, (t_end - t_start));
	printArray(arr, MAX);
	// time: O(n^2) space: O(1) ÎÈ¶¨
	system("pause");

	return 0;
}