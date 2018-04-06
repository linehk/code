#include "bstree.h"
// 基于二叉排序树的检索算法

// 二叉排序树的非递归查找算法
// p 返回待查结点 x 在二叉排序树中的地址，*f 返回待查结点 x 的父结点地址
void bssearch1(bstree t, datatype x, bstree *f, bstree *p)
{
        *f = NULL;
        *p = t;
        while (*p) {
                if (x == (*p)->key)
                        return;
                *f = *p;
                *p = (x<(*p)->key) ? (*p)->lchild : (*p)->rchild;
        }
        return;
}

// 二叉排序树的递归查找算法
bstree bssearch2(bstree t, datatype x)
{
        if (t==NULL || x==t->key)
                return t;
        if (x < t->key)
                return bssearch2(t->lchild, x); // 递归地在左子树中检索
        else
                return bssearch2(t->rchild, x); // 递归地在右子树中检索
}