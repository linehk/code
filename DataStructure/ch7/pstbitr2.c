#include <stdio.h>
#include "seqstack.h"
#include "bilink1.h"

// 二叉树后序遍历非递归算法的实现
void postorder1(bintree t)
{
        seqstack s;
        s.top = 0;
        while (t || s.top!=0) {
                if (t) {
                        s.data[s.top] = t;
                        s.tag[s.top] = 0;
                        s.top++;
                        t = t->lchild;
                } else if (s.tag[s.top-1] == 1) {
                        s.top--;
                        t = s.data[s.top];
                        printf("%c ", t->data);
                        t = NULL;
                } else {
                        t = s.data[s.top-1];
                        s.tag[s.top-1] = 1;
                        t = t->rchild;
                }
        }
}