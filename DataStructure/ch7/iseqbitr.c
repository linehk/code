#include <stdlib.h>
#include "bilink1.h"

// 判断两颗给定二叉树是否等价
int isequal(bintree t1, bintree t2)
{
        int t;
        t = 0;
        if (t1 == NULL && t2 == NULL) { // t1 和 t2 均为空，则二者等价
                t = 1;
        }
        else if (t1 != NULL && t2 != NULL) {
                if (t1->data == t2->data) {
                        if (isequal(t1->lchild, t2->lchild)) {
                                t = isequal(t1->rchild, t2->rchild);
                        }
                }
        }
        return t;
}