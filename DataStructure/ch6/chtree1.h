// 树的孩子表示法 (指针方式) 的头文件
#define m 3 // 树的度数
typedef char datatype; // 结点值的类型
typedef struct node { // 结点的类型
        datatype data;
        struct node *child[m]; // 指向子女的指针数组
} node, *tree;
tree root;