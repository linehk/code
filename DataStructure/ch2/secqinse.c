#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

// 循环队列 (顺序存储) 的插入操作
void insert_sequence_cqueue(sequence_queue *sq, datatype x)
{
        if ((sq->rear+1)%MAXSIZE == sq->front) {
                printf("\n顺序循环队列是满的！无法进行插入操作！");
                exit(1);
        }
        sq->a[sq->rear] = x;
        sq->rear = (sq->rear+1) % MAXSIZE;
}