#define _CRT_SECURE_NO_WARNINGS
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

int getPivotIndex(int array[], int i, int j) {
    // 基准数据
    int key = array[i];
    while (i < j) {
        // 因为默认基准是从左边开始，所以从右边开始比较
        // 当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针
        while (i < j && array[j] >= key) {
            j--;
        }
        // 当找到比 array[i] 小的时，就把后面的值 array[j] 赋给它
        if (i < j) {
            array[i] = array[j];
        }
        // 当队首元素小于等于基准数据 时,就一直向后挪动 i 指针
        while (i < j && array[i] <= key) {
            i++;
        }
        // 当找到比 array[j] 大的时，就把前面的值 array[i] 赋给它
        if (i < j) {
            array[j] = array[i];
        }
    }
    // 跳出循环时 i 和 j 相等,此时的 i 或 j 就是 key 的正确索引位置
    // 把基准数据赋给正确位置
    array[i] = key;
    return i;
}

void QuickSort(int array[], int low, int high) {
    // 开始默认基准为 low
    if (low < high) {
        // 分段位置下标
        int standard = getPivotIndex(array, low, high);
        // 递归调用排序
        // 左边排序
        QuickSort(array, low, standard - 1);
        // 右边排序
        QuickSort(array, standard + 1, high);
    }
}


int main()
{

	int myArr[] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
	int len = sizeof(myArr) / sizeof(int);
	printArray(myArr, len);
    QuickSort(myArr, 0, len - 1);
	printArray(myArr, len);
    // time: O(n*logn) space: O(logn) 不稳定
	system("pause");

	return 0;
}