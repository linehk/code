#include <stdio.h>
#include "seqstack.h"
#include "bilink1.h"

// 二叉树中序遍历非递归算法的实现
void inorder1(bintree t)
{
        seqstack s;
        s.top = 0;
        while (t!=NULL || s.top!=0) {
                if (t) {
                        push(&s, t);
                        t = t->lchild;
                } else {
                        t = pop(&s);
                        printf("%c ", t->data);
                        t = t->rchild;
                }
        }
}