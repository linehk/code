#include <stdlib.h>
#include "bilink1.h"

// 求给定二叉树的高度
int depth(bintree t)
{
        int h, lh, rh;
        if (t == NULL) { // 处理空二叉树的情况
                h = 0;
        } else {
                lh = depth(t->lchild); // 求左子树的高度
                rh = depth(t->rchild); // 求右子树的高度
                if (lh >= rh) // 求二叉树 t 的高度
                        h = lh + 1;
                else
                        h = rh + 1;
        }
        return h;
}