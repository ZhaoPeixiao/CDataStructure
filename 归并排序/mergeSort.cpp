#include<iostream>
using namespace std;


void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



void Merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int* temp = new(nothrow) int[high - low + 1]; 
    if (!temp) { 
        cout << "error";
        return;
    }
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
    delete[]temp;
}


void MergeSort(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}


void MergeSort2(int arr[], int n) {
    int size = 1, low, mid, high;
    while (size <= n - 1)
    {
        low = 0;
        while (low + size <= n - 1) {
            mid = low + size - 1;
            high = mid + size;
            if (high > n - 1) {
                high = n - 1;
            }
            Merge(arr, low, mid, high);
            low = high + 1;
        }
        size *= 2;
    }
}


int main() {

	int myArr[] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
	int len = sizeof(myArr) / sizeof(int);
	MergeSort(myArr, 0, len - 1);
	printArray(myArr, len);

    int a[10] = { 5,1,9,3,7,4,8,6,2,0 };
    MergeSort2(a, 10);
    printArray(a, 10);
	system("pause");
    // time: O(n*logn) space: O(n) Œ»∂®
	return 0;
}