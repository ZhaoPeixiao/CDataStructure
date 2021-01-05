#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 二叉树节点
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lChile;
	struct BINARYNODE* rChile;

}BinaryNode;

BinaryNode* copyBinaryTree(BinaryNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	BinaryNode* lChile = copyBinaryTree(root->lChile);
	BinaryNode* rChile = copyBinaryTree(root->rChile);

	BinaryNode* newRoot = (BinaryNode*)malloc(sizeof(BinaryNode));
	newRoot->ch = root->ch;
	newRoot->lChile = lChile;
	newRoot->rChile = rChile;

	return newRoot;
}


// 先序
void Recursion(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->ch);

	if (root->lChile != NULL)
	{
		Recursion(root->lChile);
	}

	if (root->rChile != NULL)
	{
		Recursion(root->rChile);
	}

}

void CreateBinaryTree()
{
	// 创建节点
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	// 建立节点关系
	node1.lChile = &node2;
	node1.rChile = &node6;

	node2.rChile = &node3;

	node3.lChile = &node4;
	node3.rChile = &node5;

	node6.rChile = &node7;

	node7.lChile = &node8;


	BinaryNode* root = copyBinaryTree(&node1);

	Recursion(&node1);
	printf("\n");
	Recursion(root);
}


int main(void)
{

	CreateBinaryTree();

	printf("\n");
	system("pause");

	return 0;
}