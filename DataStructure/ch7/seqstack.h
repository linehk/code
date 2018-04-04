#include <stdlib.h>
#include "bilink1.h"

// 顺序栈的头文件
typedef struct stack { // 栈结构定义
        bintree data[100];
        int tag[100]; // 为栈中每个元素设置的标记，用于后序遍历
        int top; // 栈顶指针
} seqstack;

// 进栈
void push(seqstack *s, bintree t)
{
        s->data[s->top] = t;
        s->top++;
}

// 出栈
bintree pop(seqstack *s)
{
        if (s->top != 0) {
                s->top--;
                return s->data[s->top];
        } else {
                return NULL;
        }
}