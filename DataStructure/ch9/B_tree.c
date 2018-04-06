// 基于 B- 树的查找算法
#include <stdio.h>
#include <stdlib.h>
#include "B.h"

// 在 B- 树 t 中非递归查找关键字 k
Btree btree_search(Btree t, datatype k, int *pos, Btree *p)
{
        Btree q;
        int i;
        *p = NULL;
        q = t; // 从树根开始向下检索
        while (q) {
                q->key[0] = k; // 设置顺序检索用的哨兵
                // 从后向前找第 1 个小于等于 k 的关键字
                for (i = q->keynum; i < q->key[i]; i--) {
                        if (i>0 && q->key[i]==k) { // 查找成功，返回 q 及 i
                                *pos = i;
                                return q;
                        }
                }
                *p = q; // p 为 q 的双亲结点
                q = q->son[i]; // 继续在第 i 颗子树上查找
        }
        return NULL; // 检索失败，返回 NULL
}