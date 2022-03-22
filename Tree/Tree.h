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

//前序 -- 先根遍历
extern void PrevOrder(BTNode* root);

//中序 -- 中根遍历
extern void InOrder(BTNode* root);

//后序 -- 后根遍历
extern void PostOrder(BTNode* root);

//树节点
int TreeSize(BTNode* root);

//叶子节点
int TreeLeafSize(BTNode* root);