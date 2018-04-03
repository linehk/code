#include <stdio.h>
#include <stdlib.h>
#include "matrixlk.h"

// 创建稀疏矩阵的十字链表表示
void Createspmatrix(headspmatrix h)
{
        int m, n, t, s, i, r, c, v;
        spmatrix p, q;
        printf("矩阵的行数、列数和非零元素的个数：");
        scanf("%d%d%d", &m, &n, &t);
        p = (spmatrix)malloc(sizeof(matrixnode));
        h[0] = p; // h[0] 为表头环形链表的表头结点
        p->row = m;
        p->col = n;
        s = m > n ? m : n;
        for (i = 1; i <= s; ++i) { // 初始化表头环形链表及各行、各列的环形链表
                p = (spmatrix)malloc(sizeof(matrixnode));
                h[i] = p;
                h[i-1]->tag.next = p;
                p->row = p->col = 0;
                p->down = p->right = p;
        }
        h[s]->tag.next = h[0];
        for (i = 1; i <= t; ++i) { // 依次读入非零元素加入十字链表中
                printf("输入非零元素的行号、列号和值：");
                scanf("%d%d%d", &r, &c, &v);
                p = (spmatrix)malloc(sizeof(matrixnode)); // 形成非零元素结点
                p->row = r;
                p->col = c;
                p->tag.val = v;
                q = h[r]; // 将非零元素插入到其所在行的环形链表
                while (q->right!=h[r] && q->right->col<c)
                        q = q->right;
                p->right = q->right;
                q->right = p;
                q = h[c]; // 将非零元素插入到其所在列的环形链表
                while (q->down!=h[c] && q->down->row<r)
                        q = q->down;
                p->down = q->down;
                q->down = p;
        }
}