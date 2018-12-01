// 链表操作

#include "list.h"
#include <stdlib.h>
#include "fatal.h"

struct Node
{
        ElementType Element;
        Position Next;
};

List MakeEmpty(List L)
{
        if (L != NULL)
                DeleteList(L);
        L = malloc(sizeof(struct Node));
        if (L == NULL)
                FatalError("Out of memory!");
        L->Next = NULL;
        return L;
}

// 测试是否为空
int IsEmpty(List L)
{
        return L->Next == NULL;
}

// 测试当前是否为链表末尾
int IsLast(Position P, List L)
{
        return P->Next == NULL;
}

// Find
Position Find(ElementType X, List L)
{
        Position P;

        P = L->Next;
        while (P != NULL && P->Element != X)
                P = P->Next;
        return P;
}

// 返回元素的前一个位置
Position FindPrevious(ElementType X, List L)
{
        Position P;

        P = L;
        while (P->Next != NULL && P->Next->Element != X)
                P = P->Next;
        return P;
}

// 链表删除
void Delete(ElementType X, List L)
{
        Position P, TmpCell;

        P = FindPrevious(X, L);
        if (!IsLast(P, L))
        {
                TmpCell = P->Next;
                P->Next = TmpCell->Next;
                free(TmpCell);
        }
}

// 链表插入
void Insert(ElementType X, List L, Position P)
{
        Position TmpCell;

        TmpCell = malloc(sizeof(struct Node));
        if (TmpCell == NULL)
                FatalError("Out of space!!!");

        TmpCell->Element = X;
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
}

// 不正确删除表
void DeleteList(List L)
{
        Position P;
        P = L->Next;
        L->Next = NULL;
        while (P != NULL)
        {
                free(P);
                P = P->Next;
        }
}

// 正确删除表
void DeleteList(List L)
{
        Position P, Tmp;

        P = L->Next;
        L->Next = NULL;
        while (P != NULL)
        {
                Tmp = P->Next;
                free(P);
                P = Tmp;
        }
}

Position Header(List L)
{
        return L;
}

Position First(List L)
{
        return L->Next;
}

Position Advance(Position P)
{
        return P->Next;
}

ElementType Retrieve(Position P)
{
        return P->Element;
}