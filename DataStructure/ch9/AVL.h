// AVL 树使用的头文件
typedef int datatype;
typedef struct node {
        datatype key;
        struct node *lchild, *rchild;
        int bal; // 结点的平衡度
} bsnode;
typedef bsnode *bstree;