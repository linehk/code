// 栈操作 数组实现

#include "stack_array.h"
#include "fatal.h"
#include <stdlib.h>

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
        int Capacity;
        int TopOfStack;
        ElementType *Array;
};

// 检测是否为空
int IsEmpty(Stack S)
{
        return S->TopOfStack == EmptyTOS;
}

// 检测是否为满
int IsFull(Stack S)
{
        return S->TopOfStack == S->Capacity - 1;
}

// 栈的创建
Stack CreateStack(int MaxElements)
{
        Stack S;
        if (MaxElements < MinStackSize)
                Error("Stack size is too small");

        S = malloc(sizeof(struct StackRecord));
        if (S == NULL)
                FatalError("Out of space!!!");

        S->Array = malloc(sizeof(ElementType) * MaxElements);
        if (S->Array == NULL)
                FatalError("Out of space!!!");
        S->Capacity = MaxElements;
        MakeEmpty(S);
        return S;
}

// 释放栈
void DisposeStack(Stack S)
{
        if (S != NULL)
        {
                free(S->Array);
                free(S);
        }
}


// 创建一个空栈
void MakeEmpty(Stack S)
{
        S->TopOfStack = EmptyTOS;
}

// 进栈
void Push(ElementType X, Stack S)
{
        if (IsFull(S))
                Error("Full stack");
        else
                S->Array[++S->TopOfStack] = X;
}

// 将栈顶返回
ElementType
Top(Stack S)
{
        if (!IsEmpty(S))
                return S->Array[S->TopOfStack];
        Error("Empty stack");
        return 0;
}

// 弹出
void Pop(Stack S)
{
        if (IsEmpty(S))
                Error("Empty stack");
        else
                S->TopOfStack--;
}

// 给出并弹出
ElementType TopAndPop(Stack S)
{
        if (!IsEmpty(S))
                return S->Array[S->TopOfStack--];
        Error("Empty stack");
        return 0;
}