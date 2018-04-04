#include <stdlib.h>
#include "bilink1.h"

// 实现二叉树的查找
bintree locate(bintree t, datatype x)
{
        bintree p;
        if (t == NULL) {
                return NULL;
        } else if (t->data == x) {
                return t;
        } else {
                p = locate(t->lchild, x);
                if (p)
                        return p;
                else
                        return locate(t->rchild, x);
        }
}