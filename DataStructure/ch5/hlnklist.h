// 带头结点的单链表存储结构定义
typedef int datatype; // 预定义的数据类型
typedef struct node {
        datatype data; // 结点数据域
        struct node *next;
} linknode;
typedef linknode *linklist;