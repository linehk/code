#include <stdio.h>
#include "bilink1.h"

// 前序遍历二叉树递归算法的实现
void preorder(bintree t)
{
        if (t) {
                printf("%c", t->data);
                preorder(t->lchild);
                preorder(t->rchild);
        }
}