
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

//初始化
extern SLNode* Init(SLTData x);

//打印
extern void Print(SLNode* const phead);

//尾插
extern void Push_Back(SLNode** pphead, SLTData x);

//头插
extern void Push_Front(SLNode** pphead, SLTData x);

//尾删
extern void Pop_Back(SLNode** pphead);

//头删
extern void Pop_Front(SLNode** pphead);

//查找
extern SLNode* Find(SLNode* phead, SLTData x);

//指定插入 -- 前导
extern void Insert_Prev(SLNode** pphead, SLNode* pos, SLTData x);

//指定删除 -- 前导
extern void Erase_Prev(SLNode** pphead, SLNode* pos);

//指定插入
extern void Insert(SLNode* phead, SLTData index, SLTData insert_val);

//指定删除
extern void Erase(SLNode* phead, SLTData index);

#endif // !__SLIST__H__

