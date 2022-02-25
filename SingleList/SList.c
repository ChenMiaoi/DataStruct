#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//��ʼ��
SLNode* Init(SLTData x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->next = NULL;
	newnode->data = x;

	return newnode;
}

//��ӡ
void Print(SLNode* const phead)
{
	SLNode* head = phead;
	while (head != NULL)
	{
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

//β��
void Push_Back(SLNode** pphead, SLTData x)
{
	SLNode* newnode = Init(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newnode;
	}
}

//ͷ��
void Push_Front(SLNode** pphead, SLTData x)
{
	SLNode* newnode = Init(x);
	
	newnode->next = *pphead;
	*pphead = newnode;
}

//βɾ
void Pop_Back(SLNode** pphead)
{
	if (*pphead == NULL)
	{
		perror("Pop Back Is Fail:Empty");
		exit(-1);
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* tail = *pphead;
		SLNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

//ͷɾ
void Pop_Front(SLNode** pphead)
{
	if (*pphead != NULL)
	{
		SLNode* head = (*pphead)->next;
		free(*pphead);
		*pphead = head;
	}
	else
	{
		perror("Pop Front Is Fail:Empty");
		exit(-1);
	}
}

//����
SLNode* Find(SLNode* const phead, SLTData x)
{
	SLNode* pos = phead;
	while (pos != NULL)
	{
		if (x == pos->data)
			return pos;
		pos = pos->next;
	}
	return NULL;
}

//ָ������ -- ǰ��
void Insert_Prev(SLNode** pphead, SLNode* pos, SLTData x)
{
	if (*pphead == pos)
	{
		Push_Front(pphead, x);
	}
	else
	{
		SLNode* newnode = Init(x);
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

//ָ��ɾ�� -- ǰ��
void Erase_Prev(SLNode** pphead, SLNode* pos)
{
	if (*pphead == pos)
	{
		Pop_Front(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

//ָ������
void Insert(SLNode* phead, SLTData index, SLTData insert_val)
{
	SLNode* pos = Find(phead, index);
	if (pos != NULL)
		Insert_Prev(&phead, pos, insert_val);
	else
	{
		perror("Insert Is Fail:Pos NULL");
		exit(-1);
	}
}

//ָ��ɾ��
void Erase(SLNode* phead, SLTData index)
{
	SLNode* pos = Find(phead, index);
	if (pos != NULL)
		Erase_Prev(&phead, pos);
}

