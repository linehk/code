#include <stdio.h>
#include <stdlib.h>
#include "lnkqueue.h"

// 建立一个空的链式队列
queue *init()
{
        queue *qu;
        qu = (queue*)malloc(sizeof(queue)); // 分配空间
        qu->front = NULL; // 队首指针设置为空
        qu->rear = NULL; // 队尾指针设置为空
        return qu;
}

// 判断链式队列是否为空
int empty(queue qu)
{
        return (qu.front ? 0 : 1);
}

// 输出链式队列中各个结点的值
void display(queue *qu)
{
        node *p;
        printf("\n");
        p = qu->front;
        if (!p)
                printf("\n链式队列为空！\n");
        while (p) {
                printf("%5d", p->info);
                p = p->next;
        }
}

// 取得链式队列的队首结点值
datatype read(queue qu)
{
        if (!qu.front) {
                printf("\n链式队列为空！\n");
                exit(1);
        }
        return (qu.front->info);
}

// 向链式队列中插入一个值为 x 的结点
queue *insert(queue *qu, datatype x)
{
        node *p;
        p = (node*)malloc(sizeof(node)); // 分配空间
        p->info = x; // 设置新结点的值
        p->next = NULL;
        if (qu->front == NULL) { // 当前队列为空，新插入的结点为队列中唯一一个结点
                qu->front = qu->rear = p;
        } else {
                qu->rear->next = p; // 队尾插入
                qu->rear = p;
        }
        return qu;
}

// 删除链式队列中的队首结点
queue *dele(queue *qu)
{
        node *q;
        if (!qu->front) {
                printf("队列为空，无法删除！");
                return qu;
        }
        q = qu->front; // q 指向队首结点 (1)
        qu->front = q->next; // 队首结点指向下一个结点 (2)
        free(q); // 释放原队首结点空间
        if (qu->front == NULL)
                qu->rear = NULL; // 队列中的唯一结点删除后，队列变空 (3)
        return qu;
}