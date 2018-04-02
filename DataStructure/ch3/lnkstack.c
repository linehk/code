#include <stdio.h>
#include <stdlib.h>
#include "slnklist.h"

// 建立一个空的链式栈
node *init()
{
        return NULL;
}

// 判断链式栈是否为空
int empty(node *top)
{
        return (top ? 0 : 1);
}

// 读链式栈的栈顶结点值
datatype read(node *top)
{
        if (!top) {
                printf("\n链式栈是空的！");
                exit(1);
        }
        return (top->info);
}

// 输出链式栈中各个结点的值
void display(node *top)
{
        node *p;
        p = top;
        printf("\n");
        if (!p)
                printf("\n链式栈是空的！");
        while (p) {
                printf("%5d", p->info);
                p = p->next;
        }
}

// 向链式栈插入值为 x 的结点 (进栈)
node *push(node *top, datatype x)
{
        node *p;
        p = (node*)malloc(sizeof(node)); // 分配空间
        p->info = x; // 设置新结点的值
        p->next = top; // 插入 (1)
        top = p; // 插入 (2)
        return top;
}

// 删除链式栈的栈顶结点 (出栈)
node *pop(node *top)
{
        node *q;
        if (!top) {
                printf("\n链式栈是空的！");
                return NULL;
        }
        q = top; // 指向被删除的结点 (1)
        top = top->next; // 删除栈顶结点 (2)
        free(q);
        return top;
}