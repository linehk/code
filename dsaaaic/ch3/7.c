#include "6.h"
#include <stdlib.h>

// 测试是否为空栈
int
IsEmpty(Stack S)
{
        return S->Next == NULL;
}

// 建立空栈 链表实现
Stack
CreateStack(void)
{
        Stack S;

        S = malloc(sizeof(struct Node));
        if (S == NULL)
                FatalError("Out of space!!!");
        S->Next == NULL;
        MakeEmpty(S);
        return S;
}

void
MakeEmpty(Stack S)
{
        if (S == NULL)
                Error("Must use CreateStack first");
        else
                while (!IsEmpty(S))
                        Pop(S);
}

// Push
void
Push(ElementType X, Stack S)
{
        PtrToNode TmpCell;

        TmpCell = malloc(sizeof(struct Node));
        if (TmpCell == NULL)
                FatalError("Out of space!!!");
        else
        {
                TmpCell->Element = X;
                TmpCell->Next = S->Next;
                S->Next = TmpCell;
        }
}

// Top
ElementType
Top(Stack S)
{
        if (!IsEmpty(S))
                return S->Next->Element;
        Error("Empty stack");
        return 0;
}

// Pop
void
Pop(Stack S)
{
        PtrToNode FirstCell;
        if (IsEmpty(S))
                Error("Empty stack");
        else
        {
                FirstCell = S->Next;
                S->Next = S->Next->Next;
                free(FirstCell);
        }
}