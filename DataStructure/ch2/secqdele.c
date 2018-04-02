#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

// 循环队列 (顺序存储) 的删除操作
void dele_sequence_cqueue(sequence_queue *sq)
{
        if (sq->front == sq->rear) {
                printf("\n循环队列是空的！无法进行删除操作！");
                exit(1);
        }
        sq->front = (sq->front+1) % MAXSIZE;
}