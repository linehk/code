// 稀疏矩阵十字链表表示的头文件
typedef struct matrixnode { // 十字链表中结点的结构
        int row, col;
        struct matrixnode *right, *down;
        union {
                int val;
                struct matrixnode *next;
        } tag;
} matrixnode;
typedef matrixnode *spmatrix;
typedef spmatrix headspmatrix[100]; // 指针数组，每个元素指向一个表头结点