#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int BTData;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTData data;
}BTNode;

//ǰ�к��� -- ������ȱ���
//ǰ�� -- �ȸ�����
extern void PrevOrder(BTNode* root);

//���� -- �и�����
extern void InOrder(BTNode* root);

//���� -- �������
extern void PostOrder(BTNode* root);

//���ڵ�
int TreeSize(BTNode* root);

//Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root);

//������� -- �ǵݹ� -- ������ȱ���
//�������е��Ƚ��ȳ�
void LevelOrder(BTNode* root);