// 二叉排序树的插入算法
#include "bstree.h"

// 在二叉排序树中插入结点值为 x 的结点
void InsertBstree(bstree *t, datatype x) 
{
        bstree f = NULL, p;
        p = *t;
        while (p) { // 查找插入位置
                if (x == p->key) // 若二叉排序树 t 中已有 key，则无需插入
                        return;
                f = p; // f 用于保存新结点的最终插入位置
                p = (x<p->key) ? p->lchild : p->rchild;
        }
        p = (bstree)malloc(sizeof(bsnode)); // 生成待插入的新结点
        p->key = x;
        p->lchild = p->rchild = NULL;
        if (*t == NULL) { // 原树为空
                *t = p;
        } else {
                if (x < f->key)
                        f->lchild = p;
                else
                        f->rchild = p;
        }
}