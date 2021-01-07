#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<Windows.h>
using namespace std;

void HeapBuild(int arr[], int root, int length) {
	int lChild = root * 2 + 1;
	if (lChild < length)
	{
		int flag = lChild;
		int rChild = lChild + 1;
		if (rChild < length) {
			if (arr[rChild] > arr[flag]) {
				flag = rChild;
			}
		}
		if (arr[root] < arr[flag]) {
			swap(arr[root], arr[flag]);
			HeapBuild(arr, flag, length);
		}
	}
}

void HeapSort(int arr[], int length) {
	for (int i = length / 2; i >= 0; --i) {
		HeapBuild(arr, i, length);
	}

	for (int j = length - 1; j > 0; --j) {
		swap(arr[0], arr[j]);
		HeapBuild(arr, 0, j);
	}

}

int main() {

	clock_t Start_time = clock();
	int a[10] = { 12,45,748,12,56,3,89,4,48,2 };
	HeapSort(a, 10);
	for (size_t i = 0; i != 10; ++i)
	{
		cout << a[i] << " ";
	}
	clock_t End_time = clock();
	cout << endl;
	cout << "Total running time is: " << static_cast<double>(End_time - Start_time) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	cin.get();
	return 0;
}