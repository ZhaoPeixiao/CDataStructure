#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lChile;
	struct BINARYNODE* rChile;

}BinaryNode;


void recursion(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->ch);

	if (root->lChile != NULL)
	{
		recursion(root->lChile);
	}

	if (root->rChile != NULL)
	{
		recursion(root->rChile);
	}

}


BinaryNode* createBinaryTree()
{
	fflush(stdin);
	char ch;
	scanf("%c", &ch);

	BinaryNode* node;

	if (ch == '#')
	{
		node = NULL;
	}
	else
	{
		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		node->ch = ch;
		node->lChile = createBinaryTree();
		node->rChile = createBinaryTree();
	}

	return node;
}


int main(void)
{
	BinaryNode* root = createBinaryTree();
	recursion(root);

	printf("\n");
	system("pause");

	return 0;
}