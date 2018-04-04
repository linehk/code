#include <stdio.h>
#include "chtree1.h"

// 实现树的前序遍历
void preorder(tree p) // p 为指向树根结点的指针
{
        int i;
        if (p != NULL) { // 树不为空
                printf("%c", p->data); // 输出根结点的值
                for (i = 0; i < m; ++i) // 依次递归实现各子树的前序遍历
                        preorder(p->child[i]);
        }
}