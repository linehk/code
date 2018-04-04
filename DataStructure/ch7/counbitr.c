#include <stdlib.h>
#include "bilink1.h"

// 统计二叉树的结点个数
int numofnode(bintree t)
{
        if (t == NULL)
                return 0;
        else
                return (numofnode(t->lchild)+numofnode(t->rchild)+1);
}