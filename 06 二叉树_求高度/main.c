#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �������ڵ�
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lChile;
	struct BINARYNODE* rChile;

}BinaryNode;


int getHeight(BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int left = getHeight(root->lChile);
	int right = getHeight(root->rChile);
	int maxH = left > right ? left : right;
	return maxH + 1;

}




void CreateBinaryTree()
{
	// �����ڵ�
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	// �����ڵ��ϵ
	node1.lChile = &node2;
	node1.rChile = &node6;

	node2.rChile = &node3;

	node3.lChile = &node4;
	node3.rChile = &node5;

	node6.rChile = &node7;

	node7.lChile = &node8;

	int height = getHeight(&node1);

	printf("%d", height);
}


int main(void)
{

	CreateBinaryTree();

	printf("\n");
	system("pause");

	return 0;
}