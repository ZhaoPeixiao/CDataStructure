#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE 1

// 二叉树节点
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lChile;
	struct BINARYNODE* rChile;

}BinaryNode;

typedef struct BITREESTACKNODE
{
	LinkNode node;
	BinaryNode* treeNode;
	int flag;

}BiTreeStackNode;

BiTreeStackNode* createStackNode(BinaryNode* root, int flag)
{
	BiTreeStackNode* stackNode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	stackNode->treeNode = root;
	stackNode->flag = flag;

	return stackNode;
}

// 非递归遍历
void NonRecursion(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	LinkStack* stack = Init_LinkStack();
	BiTreeStackNode* stackNode = createStackNode(root, MY_FALSE);
	Push_LinkStack(stack, (LinkNode*)stackNode);
	while (Size_LinkStack(stack) > 0)
	{
		BiTreeStackNode* topNode = (BiTreeStackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		if (topNode->treeNode == NULL)
		{
			continue;
		}

		if (topNode->flag == MY_TRUE)
		{
			printf("%c", topNode->treeNode->ch);
		}
		else
		{
			BinaryNode* rChild = topNode->treeNode->rChile;
			BiTreeStackNode* rightNode = createStackNode(rChild, MY_FALSE);
			Push_LinkStack(stack, (LinkNode*)rightNode);

			BinaryNode* lChild = topNode->treeNode->lChile;
			BiTreeStackNode* leftNode = createStackNode(lChild, MY_FALSE);
			Push_LinkStack(stack, (LinkNode*)leftNode);

			topNode->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)topNode);
		}
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

	NonRecursion(&node1);
}


int main(void)
{

	CreateBinaryTree();

	printf("\n");
	system("pause");

	return 0;
}