// 树的孩子兄弟表示法的头文件
typedef char datatype; // 树中结点值的类型
typedef struct node { // 树中每个结点的类型
        datatype data;
        struct node *firstchild, *rightsibling;
} node, *pnode;
pnode root; // 指向树根结点的指针