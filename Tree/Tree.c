#include "Tree.h"

//ǰ�� -- �ȸ�����
void PrevOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

//���� -- �и�����
void InOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}	
	InOrder(root->_left);
	printf("%c ", root->data);
	InOrder(root->_right);
}

//���� -- �������
void PostOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->data);
}

//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	static int size = 0;
//	++size;
//
//	TreeSize(root->_left);
//	TreeSize(root->_right);
//	return size;
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return;
//	else
//		(*psize)++;
//
//	TreeSize(root->_left, psize);
//	TreeSize(root->_right, psize);
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :\
		TreeSize(root->_left) + TreeSize(root->_right) + 1;
}

//Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL 
		&& root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left)
		+ TreeLeafSize(root->_right);
}