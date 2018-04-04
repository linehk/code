// 树的双亲表示法的头文件
#define MAXSIZE 100 // 树中结点个数的最大值
typedef char datatype; // 结点值的类型
typedef struct node { // 结点的类型
        datatype data;
        int parent; // 结点双亲的下标
} node;
typedef struct tree {
        node treelist[MAXSIZE]; // 存放结点的数组
        int length, root; // 树中实际所含结点的个数及根结点的位置
} tree; // 树的类型