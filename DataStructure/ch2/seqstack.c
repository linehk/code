#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

// 栈 (顺序存储) 初始化
void init(sequence_stack *st)
{
        st->top = 0;
}

// 判断栈 (顺序存储) 是否为空
int empty(sequence_stack st)
{
        return (st.top ? 0 : 1);
}

// 读栈顶 (顺序存储) 结点值
datatype read(sequence_stack st)
{
        if (empty(st)) {
                printf("\n栈是空的！");
                exit(1);
        }
        else {
                return st.a[st.top - 1];
        }
}

// 栈 (顺序存储) 的插入 (进栈) 操作
void push(sequence_stack *st, datatype x)
{
        if (st->top == MAXSIZE) {
                printf("\n栈是满的！");
                exit(1);
        }
        st->a[st->top] = x;
        st->top++;
}

// 栈 (顺序存储) 的删除 (出栈) 操作
void pop(sequence_stack *st)
{
        if (st->top == 0) {
                printf("\n栈是空的！");
                exit(1);
        }
        st->top--;
}