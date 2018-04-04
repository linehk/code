#define m 3 // 树的度数
#define MAXSIZE 20 // 数组元素个数的最大值
typedef char datatype; // 树中结点值的类型
typedef struct node { // 树的扩充孩子表示法中结点的类型
        datatype data;
        int child[m];
        int parent;
} treenode;
typedef struct { // 层号表示法中结点的类型
        datatype data;
        int lev; // 存储结点的层号
} levelnode;
treenode tree[MAXSIZE]; // 树的扩充孩子表示法的存储数组
int root; // 根结点的下标
int length; // 树中实际所含结点的个数
levelnode ltree[MAXSIZE]; // 树层号表示法的数组

// 将树的层号表示法转换成树的扩充孩子表示
void leveltotree(int length, levelnode ltree[], int *root, treenode tree[])
{
        int i, j, k;
        for (i = 0; i < length; ++i) {
                for (j = 0; j < m; ++j)
                        tree[i].child[j] = -1;
        }
        *root = 0; // 第 1 个元素为根结点
        tree[0].data = ltree[0].data;
        tree[0].parent = -1; // 根结点的双亲为空
        for (i = 1; i < length; ++i) {
                tree[i].data = ltree[i].data;
                j = i - 1;
                // 结点 i 为其前一个元素 j 的第 1 个子女
                if (ltree[i].lev > ltree[j].lev) {
                        tree[i].parent = j;
                        tree[j].child[0] = i;
                } else {
                        while (ltree[i].lev < ltree[j].lev) // 寻找结点 i 的兄弟
                                j = tree[j].parent;
                         // 结点 i 和结点 j 的双亲相同        
                        tree[i].parent = tree[j].parent;
                        j = tree[j].parent;
                        k = 0; // 将结点 i 挂到双亲结点上
                        while (tree[j].child[k] != -1)
                                ++k;
                        tree[j].child[k] = i;
                }
        }
}