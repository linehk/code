// 二叉排序树的头文件
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node { // 二叉排序树结点定义
        datatype key; // 结点值
        struct node *lchild, *rchild; // 左、右孩子指针
} bsnode;
typedef bsnode *bstree;