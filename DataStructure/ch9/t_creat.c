// 二叉排序树的建立算法
#include "bstree.h"
#include "t_insert.c"

bstree CreatBstree(void)
{
        bstree t = NULL;
        datatype key;
        printf("\n请输入一个以 -1 为结束标记的结点序列：\n");
        scanf("%d", &key); // 输入一个关键字
        while (key != -1) {
                InsertBstree(&t, key); // 将 key 插入二叉排序树 t
                scanf("%d", &key);
        }
        return t; // 返回建立的二叉排序树的根地址
}