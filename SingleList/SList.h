
#ifndef __SLIST__H__
#define __SLIST__H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int SLTData;

typedef struct SListNode
{
	SLTData data;
	struct SListNode* next;
}SLNode;

typedef enum SListMenu
{
	EXIT,
	PUSHBACK,
	PUSHFRONT,
	POPBACK,
	POPFRONT,
	FIND,
	PRINT,
	INSERT,
	ERASE
}Menu;

//��ʼ��
extern SLNode* Init(SLTData x);

//��ӡ
extern void Print(SLNode* const phead);

//β��
extern void Push_Back(SLNode** pphead, SLTData x);

//ͷ��
extern void Push_Front(SLNode** pphead, SLTData x);

//βɾ
extern void Pop_Back(SLNode** pphead);

//ͷɾ
extern void Pop_Front(SLNode** pphead);

//����
extern SLNode* Find(SLNode* phead, SLTData x);

//ָ������ -- ǰ��
extern void Insert_Prev(SLNode** pphead, SLNode* pos, SLTData x);

//ָ��ɾ�� -- ǰ��
extern void Erase_Prev(SLNode** pphead, SLNode* pos);

//ָ������
extern void Insert(SLNode* phead, SLTData index, SLTData insert_val);

//ָ��ɾ��
extern void Erase(SLNode* phead, SLTData index);

#endif // !__SLIST__H__

