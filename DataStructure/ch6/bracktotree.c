#define m 3 // 树的度数
#define MAXSIZE 20 // 树的孩子表示法对应的数组大小
#define BMAXSIZE 50 // 树的括号表示对应的数组大小
typedef char datatype; // 树中结点值的类型
typedef struct node { // 树的孩子表示法中结点的类型
        datatype data;
        int child[m];
} treenode;
treenode tree[MAXSIZE]; // 树孩子表示法的存储数组
int root; // 根结点的下标
int length; // 树中实际所含结点的个数
char p[BMAXSIZE]; // 存放树括号表示的数组

// 将树的括号表示转换成树的孩子表示 (数组方式)
void bracktotree(char p[], int *root, int *length, treenode tree[])
{
        int stack[MAXSIZE]; // 存储树或子树根结点的栈
        int top; // 栈顶指针
        int i, j, k, l, done; // done 为程序结束的标志
        k = 0;
        j = 0;
        *root = 0;
        top = 0;
        done = 1; // 栈和标志的初始化
        tree[j].data = p[k]; // 产生孩子表示法中的根结点
        ++k;
        for (i = 0; i < m; ++i)
                tree[j].child[i] = -1;
        while (done) {
                if (p[k] == '(') { // 遇到左括号，则其前面的元素对应的结点进栈
                        stack[top] = j;
                        ++top;
                        ++k;
                } else if (p[k] == '(') { // 遇到右括号，栈顶元素出栈
                        --top;
                        if (top == 0)
                                done = 0;
                        else
                                ++k;
                } else if (p[k] == ',') {
                        ++k;
                } else { // 将当前被扫描的元素作为栈顶元素的子女
                        ++j;
                        tree[j].data = p[k];
                        for (i = 0; i < m; ++i)
                                tree[j].child[i] = -1;
                        l = stack[top-1];
                        i = 0;
                        while (tree[l].child[i] != -1)
                                ++i; // 寻找栈顶元素当前的第 1 个空子女
                        tree[l].child[i] = j;
                        ++k;
                }
        }
        *length = j + 1;
}