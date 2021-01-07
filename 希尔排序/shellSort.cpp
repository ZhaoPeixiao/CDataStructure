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


void shellSort(int arr[], int length)
{
	for (int d = length / 2; d > 0; d /= 2)
	{
		for (int i = d; i < length; i++)
		{
			int insertNum = arr[i];
			int insertIndex;
			for (insertIndex = i - d; insertIndex >= 0 && arr[insertIndex] > insertNum; insertIndex -= d)
			{
				swap(&arr[insertIndex + d], &arr[insertIndex]);
			}
			arr[insertIndex + d] = insertNum;
		}
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
	shellSort(arr, MAX);
	//long t_end = getSystemTime();
	printf("After-------\n");
	//printf("Time for %d nums is:  %ld\n", MAX, (t_end - t_start));
	printArray(arr, MAX);
	// time: O(n^1.3) space: O(1) ²»ÎÈ¶¨
	system("pause");

	return 0;
}