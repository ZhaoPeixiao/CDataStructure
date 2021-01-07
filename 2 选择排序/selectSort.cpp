#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 20000

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

void selectSort(int arr[], int length)
{
	int minIndex;
	for (int index = 0; index < length - 1; index++)
	{
		minIndex = index;
		for (int i = index + 1; i < length; i++)
		{
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
		}
		if (index != minIndex)
		{
			swap(&arr[index], &arr[minIndex]);
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

	//printf("Before\n");
	//printArray(arr, MAX);
	long t_start = getSystemTime();
	selectSort(arr, MAX);
	long t_end = getSystemTime();
	//printf("After-------\n");
	printf("Time for %d nums is:  %ld\n", MAX, (t_end - t_start));
	// Time for 10000 nums is:  105
	// Time for 20000 nums is:  406
	// time: O(n^2) space: O(1) ²»ÎÈ¶¨
	//printArray(arr, MAX);
	system("pause");

	return 0;
}
