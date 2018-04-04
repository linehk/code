#include <stdio.h>
#include "bilink1.h"

// 后序遍历二叉树递归算法的实现
void postorder(bintree t)
{
        if (t) {
                postorder(t->lchild);
                postorder(t->rchild);
                printf("%c", t->data);
        }
}