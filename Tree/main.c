#include "Tree.h"

void test1()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->_left = NULL;
	A->_right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->_left = NULL;
	B->_right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->_left = NULL;
	C->_right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->_left = NULL;
	D->_right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->_left = NULL;
	E->_right = NULL;

	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");

	printf("%d\n", TreeSize(A));
	printf("%d\n", TreeSize(B));
	printf("%d\n", TreeLeafSize(A));

}

int main()
{
	test1();
	
}