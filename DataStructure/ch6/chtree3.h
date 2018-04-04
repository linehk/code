// 树的孩子表示法 (链表方式) 的头文件
#define MAXSIZE 50
typedef char datatype;
typedef struct chnode { // 孩子结点的类型
        int child;
        struct chnode *next;
} chnode, *chpoint;
typedef struct { // 树中每个结点的类型
        datatype data;
        chpoint firstchild; // 指向第 1 个子女结点的指针
} node;
typedef struct { // 树的类型
        node treelist[MAXSIZE];
        int length, root; // 树中实际所含结点的个数和根结点的位置
} tree;