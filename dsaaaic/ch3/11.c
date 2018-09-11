#include "10.h"

// 队列数组实现操作

// 测试队列是否为空
int
IsEmpty(Queue Q)
{
        return Q->Size == 0;
}

// 构造空队列
void
MakeEmpty(Queue Q)
{
        Q->Size = 0;
        Q->Front = 1;
        Q->Rear = 0;
}

// 是否有
static int
Succ(int Value, Queue Q)
{
        if (++Value == Q->Capacity)
                Value = 0;
        return Value;
}

// 入队
void
Enqueue(ElementType X, Queue Q)
{
        if (IsFull(Q))
                Error("Full queue");
        else
        {
                Q->Size++;
                Q->Rear = Succ(Q->Rear, Q);
                Q->Array[Q->Rear] = X;
        }
}