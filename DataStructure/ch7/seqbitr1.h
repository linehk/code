// 二叉树顺序存储的头文件
#define MAXSIZE 20
typedef char datatype; // 结点值的类型
typedef struct {
        datatype data;
        int lchild, rchild; // 存放左、右子女的下标
} node; // 二叉树结点的类型
node tree[MAXSIZE];
int n; // 树中实际所含结点的个数
int root; // 存放根结点的下标