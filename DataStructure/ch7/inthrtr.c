#include <stdio.h>
#include "threadtr.h"

// 寻找结点 p 在中序遍历下的后继结点
binthrtree insuccnode(binthrtree p)
{
        binthrtree q;
        if (p->rtag == 1) { // p 的右指针为线索，恰巧指向 p 的后继结点
                return p->rchild;
        } else {
                q = p->rchild; // 寻找 p 的右子树中最左下的结点
                while (q->ltag == 0)
                        q = q->lchild;
                return q;
        }
}

// 中序遍历中序穿线二叉树
void inthrtree(binthrtree p)
{
        if (p) {
                while (p->ltag == 0)
                        p = p->lchild; // 求 p 中序遍历下的第一个结点
                do {
                        printf("%c ", p->data);
                        p = insuccnode(p); // 求 p 中序遍历下的后继结点
                } while (p);
        }
}