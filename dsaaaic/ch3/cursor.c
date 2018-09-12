// 链表操作 游标实现
#include "cursor.h"
#include <stdlib.h>
#include "fatal.h"

struct Node
{
        ElementType Element;
        Position Next;
};

struct Node CursorSpace[SpaceSize];

// 分配和回收游标空间
static Position CursorAlloc(void)
{
        Position P;

        P = CursorSpace[0].Next;
        CursorSpace[0].Next = CursorSpace[P].Next;
        return P;
}

static void CursorFree(Position P)
{
        CursorSpace[P].Next = CursorSpace[0].Next;
        CursorSpace[0].Next = P;
}

void InitializeCursorSpace(void)
{
        int i;

        for (i = 0; i < SpaceSize; i++)
                CursorSpace[i].Next = i + 1;
        CursorSpace[SpaceSize - 1].Next = 0;
}

// 创建实例
List MakeEmpty(List L)
{
        if (L != NULL)
                DeleteList(L);
        L = CursorAlloc();
        if (L == 0)
                FatalError("Out of memory!");
        CursorSpace[L].Next = 0;
        return L;
}

// 测试链表是否为空
int IsEmpty(List L)
{
        return CursorSpace[L].Next == 0;
}

// 测试是否为链表末尾
int IsLast(Position P, List L)
{
        return CursorSpace[P].Next == 0;
}

// Find
Position Find(ElementType X, List L)
{
        Position P;

        P = CursorSpace[L].Next;
        while (P && CursorSpace[P].Element != X)
                P = CursorSpace[P].Next;
        return P;
}

// 找到被删元素前一个节点
Position FindPrevious(ElementType X, List L)
{
        Position P;

        P = L;
        while (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
                P = CursorSpace[P].Next;
        
        return P;
}

// 删除
void Delete(ElementType X, List L)
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
void Insert(ElementType X, List L, Position P)
{
        Position TmpCell;

        TmpCell = CursorAlloc();
        if (TmpCell == 0)
                FatalError("Out of space!!!");

        CursorSpace[TmpCell].Element = X;
        CursorSpace[TmpCell].Next = CursorSpace[P].Next;
        CursorSpace[P].Next = TmpCell;
}

// 删除列表
void DeleteList(List L)
{
        Position P, Tmp;

        P = CursorSpace[L].Next;
        CursorSpace[L].Next = 0;
        while (P != 0)
        {
                Tmp = CursorSpace[P].Next;
                CursorFree(P);
                P = Tmp;
        }
}

Position Header(List L)
{
        return L;
}

Position First(List L)
{
        return CursorSpace[L].Next;
}

Position Advance(Position P)
{
        return CursorSpace[P].Next;
}

ElementType Retrieve(Position P)
{
        return CursorSpace[P].Element;
}