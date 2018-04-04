#include <stdio.h>
#include <stdlib.h>
#include "bilink1.h"

// 根据前序遍历结果创建一颗给定二叉树
bintree createbintree()
{
        char ch;
        bintree t;
        if ((ch=getchar()) == '#') {
                t = NULL;
        } else {
                t = (bintnode*)malloc(sizeof(bintnode));
                t->data = ch;
                t->lchild = createbintree();
                t->rchild = createbintree();
        }
        return t;
}