// 丰满树构造算法
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node { // 二叉树结点定义
        datatype data;
        struct node *lchild, *rchild;
} bintnode;
typedef bintnode *bintree;

// 平分法创建一颗丰满树
bintree creatfulltree(int node[], int low, int high)
{
        int mid;
        bintree s;
        if (low < high) {
                mid = (low+high) / 2;
                s = (bintree)malloc(sizeof(bintnode)); // 生成一个新结点
                s->data = node[mid];
                s->lchild = creatfulltree(node, low, mid-1); // 平分法建左子树
                s->rchild = creatfulltree(node, mid+1, high); // 平分法建右子树
                return s;
        } else {
                return NULL;
        }
}