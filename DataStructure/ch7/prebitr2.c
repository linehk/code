#include <stdio.h>
#include "seqstack.h"
#include "bilink1.h"

// 二叉树前序遍历非递归算法的实现
void preorder1(bintree t)
{
        seqstack s;
        s.top = 0;
        while (t || s.top!=0) { // 当前处理的子树不为空
                if (t) {
                        printf("%c ", t->data);
                        push(&s, t);
                        t = t->lchild;
                } else {
                        t = pop(&s);
                        t = t->rchild;
                }
        }
}