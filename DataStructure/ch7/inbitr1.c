#include <stdio.h>
#include "bilink1.h"

// 中序遍历二叉树递归算法的实现
void inorder(bintree t)
{
        if (t) {
                inorder(t->lchild);
                printf("%c", t->data);
                inorder(t->rchild);
        }
}