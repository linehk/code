// 链式串的头文件
typedef struct node {
        char data; // 用于存放字符串中的每个字符
        struct node *next; // 用于指向本字符的下一个对应的结点的指针
} linkstrnode;
typedef linkstrnode *linkstring;