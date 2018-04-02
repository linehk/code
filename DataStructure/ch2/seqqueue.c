#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

// 队列 (顺序存储) 初始化
void init(sequence_queue *sq)
{
        sq->front = sq->rear = 0;
}

// 判断队列 (顺序存储) 是否为空
int empty(sequence_queue sq)
{
        return (sq.front == sq.rear ? 1 : 0);
}

// 打印队列 (顺序存储) 的结点值
void display(sequence_queue sq)
{
        int i;
        if (empty(sq)) {
                printf("\n顺序队列是空的！");
        } else {
                for (i = sq.front; i < sq.rear; i++) {
                        printf("%5d", sq.a[i]);
                }
        }
}

// 取得队列 (顺序存储) 的队首结点值
datatype get(sequence_queue sq)
{
        if (empty(sq)) {
                printf("\n顺序队列是空的！无法取得队首结点值！");
                exit(1);
        }
        return sq.a[sq.front];
}

// 队列 (顺序存储) 的插入 (进队) 操作
void insert(sequence_queue *sq, datatype x)
{
        if (sq->rear == MAXSIZE) {
                printf("\n顺序队列是满的！");
                exit(1);
        }
        sq->a[sq->rear] = x;
        sq->rear = sq->rear + 1;
}

// 队列 (顺序存储) 的删除 (出队) 操作
void dele(sequence_queue *sq)
{
        if (sq->front == sq->rear) {
                printf("\n顺序队列是空的！不能进行删除操作！");
                exit(1);
        }
        sq->front++;
}