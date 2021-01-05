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

// 先序
void Recursion1(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->ch);

	if (root->lChile != NULL)
	{
		Recursion1(root->lChile);
	}

	if (root->rChile != NULL)
	{
		Recursion1(root->rChile);
	}

}

// 中序
void Recursion2(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	if (root->lChile != NULL)
	{
		Recursion2(root->lChile);
	}

	printf("%c ", root->ch);


	if (root->rChile != NULL)
	{
		Recursion2(root->rChile);
	}

}

// 后序
void Recursion3(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	if (root->lChile != NULL)
	{
		Recursion3(root->lChile);
	}


	if (root->rChile != NULL)
	{
		Recursion3(root->rChile);
	}


	printf("%c ", root->ch);
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

	printf("先序");
	Recursion1(&node1);
	printf("\n");
	printf("中序");
	Recursion2(&node1);
	printf("\n");
	printf("后序");
	Recursion3(&node1);

}


int main(void)
{

	CreateBinaryTree();

	printf("\n");
	system("pause");

	return 0;
}