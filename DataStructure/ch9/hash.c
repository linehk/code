// 基于散列表的插入与查找算法
#include <stdio.h>

// 运用除余法构造散列函数并用拉链法解决地址冲突的散列表构造及检索算法
#define Max 6
#define Hashmax 5
int data[Max]; // 数据数组
struct list { // 声明列表结构
        int key; // 键值
        struct list *next;
};
typedef struct list node;
typedef node *link;
link hashtab[Hashmax]; // Hash 链表表头指针数组
int counter = 1; // 计数器

// 求余法散列函数
int hash_mod(int key)
{
        return key % Hashmax;
}

// 散列表插入运算
void insert_hash(int key)
{
        link p, new;
        int index;
        new = (link)malloc(sizeof(node)); // 生成新结点
        new->key = key;
        new->next = NULL;
        index = hash_mod(key); // 插入到所在的链表表头
        new->next = hashtab[index];
        hashtab[index] = new;
}

// 基于 Hash 链表的查找
int hash_search(int key)
{
        link p;
        int index;
        counter = 0; // 查找次数初始化
        index = hash_mod(key); // 取得数据位置
        p = hashtab[index]; // 散列表起始指针
        printf("Data[%d]:", index);
        while (p) {
                counter++;
                printf("[%d]", p->key);
                if (p->key == key) // 查找到数据
                        return 1;
                else
                        p = p->next; // 指向下一个结点
        }
        return 0;
}