#include "matrixlk.h"

// 稀疏矩阵十字链表的查找
int locatespmatrix(headspmatrix h, int x, int *rows, int *cols)
{
        spmatrix p, q;
        p = h[0]->tag.next; // p 指向第 1 行(列)的表头结点
        while (p != h[0]) { // 按顺序在每行中查找值为 x 的结点
                q = p->right; // q 指向本行的第 1 个非零元素的结点
                while (p != q) {
                        if (q->tag.val == x) { // 找到 x 后将其行号和列号返回
                                *rows = q->row;
                                *cols = q->col;
                                return 1;
                        }
                        q = q->right;
                }
                p = p->tag.next; // 准备进入下一行查找
        }
        return 0;
}