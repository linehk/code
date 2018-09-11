#include "4.h"

// 链表操作 游标实现

// 测试链表是否为空
int
IsEmpty(List L)
{
        return CursorSpace[L].Next == 0;
}

// 测试是否为链表末尾
int
IsLast(Position P, List L)
{
        return CursorSpace[P].Next == 0;
}

// Find
Position
Find(ElementType X, List L)
{
        Position P;

        P = CursorSpace[L].Next;
        while (P && CursorSpace[P].Element != X)
                P = CursorSpace[P].Next;
        return P;
}

// 删除
void
Delete(ElementType X, List L)
{
        Position P, TmpCell;

        P = FindPrevious(X, L);

        if (!IsLast(P, L))
        {
                TmpCell = CursorSpace[P].Next;
                CursorSpace[P].Next = CursorSpace[TmpCell].Next;
                CursorFree(TmpCell);
        }
}

// 插入
void
Insert(ElementType X, List L, Position P)
{
        Position TmpCell;

        TmpCell = CursorAlloc();
        if (TmpCell == 0)
                FatalError("Out of space!!!");
        
        CursorSpace[TmpCell].Element = X;
        CursorSpace[TmpCell].Next = CursorSpace[P].Next;
        CursorSpace[P].Next = TmpCell;
}