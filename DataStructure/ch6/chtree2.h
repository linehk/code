// 树的孩子表示法 (数组方式) 的头文件
#define m 3 // 树的度数
#define MAXSIZE 20 // 存放树结点的数组大小
typedef char datatype; // 树中结点值的类型
typedef struct node { // 树中结点的类型
        datatype data;
        int child[m];
} treenode;
treenode tree[MAXSIZE]; // 存储树结点的数组
int root; // 树结点的下标
int length; // 树中实际所含结点的个数