// 队列 ADT 操作

#include "queue.h"
#include "fatal.h"
#include <stdlib.h>

#define MinQueueSize (5)

struct QueueRecord
{
        int Capacity;
        int Front;
        int Rear;
        int Size;
        ElementType *Array;
};

// 测试队列是否为空
int IsEmpty(Queue Q)
{
        return Q->Size == 0;
}

// 测试队列是否满
int IsFull(Queue Q)
{
        return Q->Size == Q->Capacity;
}

// 创建队列
Queue CreateQueue(int MaxElements)
{
        Queue Q;

        if (MaxElements < MinQueueSize)
                Error("Queue size if too small");
        
        Q = malloc(sizeof(struct QueueRecord));
        if (Q == NULL)
                FatalError("Out of space!!!");

        Q->Array = malloc(sizeof(ElementType) * MaxElements);
        if (Q->Array == NULL)
                FatalError("Out of space!!!");
        Q->Capacity = MaxElements;
        MakeEmpty(Q);

        return Q;
}

// 构造空队列
void MakeEmpty(Queue Q)
{
        Q->Size = 0;
        Q->Front = 1;
        Q->Rear = 0;
}

// 销毁队列
void DisposeQueue(Queue Q)
{
        if (Q != NULL)
        {
                free(Q->Array);
                free(Q);
        }
}

// 是否有
static int Succ(int Value, Queue Q)
{
        if (++Value == Q->Capacity)
                Value = 0;
        return Value;
}

// 入队
void Enqueue(ElementType X, Queue Q)
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

ElementType Front(Queue Q)
{
        if (!IsEmpty(Q))
                return Q->Array[Q->Front];
        Error("Empty queue");
        return 0;
}

void Dequeue(Queue Q)
{
        if (IsEmpty(Q))
                Error("Empty queue");
        else
        {
                Q->Size--;
                Q->Front = Succ(Q->Front, Q);
        }
}

ElementType FrontAndDequeue(Queue Q)
{
        ElementType X = 0;

        if (IsEmpty(Q))
                Error("Empty queue");
        else
        {
                Q->Size--;
                X = Q->Array[Q->Front];
                Q->Front = Succ(Q->Front, Q);
        }
        return X;
}