// 中序穿线二叉树链式存储的头文件
typedef char datatype; // 树中结点值的类型
typedef struct node {
        datatype data;
        int ltag, rtag; // 左、右标志位
        struct node *lchild, *rchild;
} binthrnode;
typedef binthrnode *binthrtree;