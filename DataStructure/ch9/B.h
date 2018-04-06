// B- 树头文件
#define m 20
typedef int datatype;
typedef struct node {
        int keynum; // 结点中当前拥有的关键字的个数
        datatype key[m]; // 关键字向量为 key[1...keynum]，key[0] 不用
        struct node *parent; // 双亲指针
        struct node *son[m]; // 孩子指针向量
} Btreenode;
typedef Btreenode *Btree;