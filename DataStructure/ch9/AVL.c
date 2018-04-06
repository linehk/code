// 平衡二叉树相关算法
#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

// 对 AVL 树进行左改组
void lchange(bstree *t)
{
        bstree p1, p2;
        p1 = (*t)->lchild;
        if (p1->bal == 1) { // LL 改组
                (*t)->lchild = p1->rchild;
                p1->rchild = *t;
                (*t)->bal = 0;
                (*t) = p1;
        } else { // LR 改组
                p2 = p1->rchild;
                p1->rchild = p2->lchild;
                p2->lchild = p1;
                (*t)->lchild = p2->rchild;
                p2->rchild = *t;
                if (p2->bal == 1) {
                        (*t)->bal = -1;
                        p1->bal = 0; // 调整平衡度
                } else {
                        (*t)->bal = 0;
                        p1->bal = 1;
                }
                (*t) = p2;
        }
        (*t)->bal = 0;
}

// 对 AVL 树进行右改组
void rchange(bstree *t)
{
        bstree p1, p2;
        p1 = (*t)->rchild;
        if (p1->bal == 1) { // RR 改组
                (*t)->rchild = p1->lchild;
                p1->lchild = *t;
                (*t)->bal = 0;
                (*t) = p1;
        } else { // RL 改组
                p2 = p1->lchild;
                p1->lchild = p2->rchild;
                p2->rchild = p1;
                (*t)->rchild = p2->lchild;
                p2->lchild = (*t);
                if (p2->bal == -1) {
                        (*t)->bal = 1;
                        p1->bal = 0; // 调整平衡度
                } else {
                        (*t)->bal = 0;
                        p1->bal = -1;
                }
                (*t) = p2;
        }
        (*t)->bal = 0;
}

// 平衡二叉树的插入算法
void InsertAvlTree(datatype x, bstree *t, int *h)
{
        if (*t == NULL) {
                *t = (bstree)malloc(sizeof(bsnode)); // 生成根结点
                (*t)->key = x;
                (*t)->bal = 0;
                *h = 1;
                (*t)->lchild = (*t)->rchild = NULL;
        } else if (x < (*t)->key) { // 在左子树中插入新结点
                InsertAvlTree(x, &(*t)->lchild, h);
                if (*h) {
                        switch ((*t)->bal) {
                        case -1:
                                (*t)->bal = 0;
                                *h = 0;
                                break;
                        case 0:
                                (*t)->bal = 1;
                                break;
                        case 1: // 进行左改组
                                lchange(t);
                                *h = 0;
                                break; 
                        }
                }
        } else if (x > (*t)->key) { // 在右子树中插入新结点
                InsertAvlTree(x, &(*t)->rchild, h);
                if (*h) { // 右子树中插入了新结点
                        switch ((*t)->bal) {
                        case 1:
                                (*t)->bal = 0;
                                *h = 0;
                                break;
                        case 0:
                                (*t)->bal = 1;
                                break;
                        case -1: // 进行右改组
                                rchange(t);
                                *h = 0;
                                break;
                        }
                }
        } else {
                *h = 0;
        }
}