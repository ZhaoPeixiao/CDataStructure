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
    // ��׼����
    int key = array[i];
    while (i < j) {
        // ��ΪĬ�ϻ�׼�Ǵ���߿�ʼ�����Դ��ұ߿�ʼ�Ƚ�
        // ����β��Ԫ�ش��ڵ��ڻ�׼���� ʱ,��һֱ��ǰŲ�� j ָ��
        while (i < j && array[j] >= key) {
            j--;
        }
        // ���ҵ��� array[i] С��ʱ���ͰѺ����ֵ array[j] ������
        if (i < j) {
            array[i] = array[j];
        }
        // ������Ԫ��С�ڵ��ڻ�׼���� ʱ,��һֱ���Ų�� i ָ��
        while (i < j && array[i] <= key) {
            i++;
        }
        // ���ҵ��� array[j] ���ʱ���Ͱ�ǰ���ֵ array[i] ������
        if (i < j) {
            array[j] = array[i];
        }
    }
    // ����ѭ��ʱ i �� j ���,��ʱ�� i �� j ���� key ����ȷ����λ��
    // �ѻ�׼���ݸ�����ȷλ��
    array[i] = key;
    return i;
}

void QuickSort(int array[], int low, int high) {
    // ��ʼĬ�ϻ�׼Ϊ low
    if (low < high) {
        // �ֶ�λ���±�
        int standard = getPivotIndex(array, low, high);
        // �ݹ��������
        // �������
        QuickSort(array, low, standard - 1);
        // �ұ�����
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
    // time: O(n*logn) space: O(logn) ���ȶ�
	system("pause");

	return 0;
}