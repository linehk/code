// 基于二叉排序树的结点删除算法
#include "t_search.c"

// 在二叉排序树 t 中删除结点值为 x 的结点
bstree DelBstree(bstree t, datatype x)
{
        bstree p, q, child;
        bssearch1(t, x, &p, &q); // 查找被删结点
        if (q) { // 找到了待删除结点
                if (q->lchild==NULL && q->rchild==NULL) { // 情况一，被删结点为叶结点
                        if (p) { // 待删除结点有双亲
                                if (p->lchild == q)
                                        p->lchild = NULL;
                                else
                                        p->rchild = NULL;
                        } else {
                                t = NULL; // 被删结点为树根
                        }
                        free(q);
                // 情况二，被删结点的右子树为空，用被删结点的左子树替代该结点
                } else if (q->rchild == NULL) {
                        if (p) { // 被删结点的双亲结点不为空
                                if (p->lchild == q) // q 是其双亲结点的左儿子
                                        p->lchild = q->lchild;
                                else // q 是其双亲结点的右儿子
                                        p->rchild = q->lchild;
                        } else {
                                t = q->lchild;
                        }
                        free(q);
                // 情况三，被删结点的左子树为空，用被删结点的右子树替代该结点
                } else if (q->lchild == NULL) {
                        if (p) { // 被删结点的双亲结点不为空
                                if (p->lchild == q) // q 是其双亲结点的左儿子
                                        p->lchild = q->rchild;
                                else // q 是其双亲结点的右儿子
                                        p->rchild = q->rchild;
                        } else {
                                t = q->rchild;
                        }
                        free(q);
                } else { // 情况四，被删结点的左右子树均不为空，用右子树代替被删结点，
                         // 同时将被删结点的左子树收为右子树中序首点的左儿子
                        child = q->rchild;
                        while (child->lchild) // 找被删结点右子树中的中序首点
                                child = child->lchild;
                        // 收被删结点的左子树收为 child 的左孩子
                        child->lchild = q->lchild;
                        if (p) { // 被删结点不是树根
                                if (p->lchild == q)
                                        p->lchild = q->rchild;
                                else
                                        p->rchild = q->rchild;
                        } else {
                                t = q->rchild; // 被删结点为树根
                        }
                        free(q);
                }
        }
        return t;
}