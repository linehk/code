#include <stdio.h>
#include <stdlib.h>
#include "chtree1.h"

// 根据树的前序遍历结果建立一颗 3 度树
tree createtree()
{
        int i;
        char ch;
        tree t;
        if ((ch=getchar()) == '#') {
                t = NULL;
        } else {
                t = (tree)malloc(sizeof(node));
                t->data = ch;
                for (i = 0; i < m; ++i)
                        t->child[i] = createtree();
        }
        return t;
}