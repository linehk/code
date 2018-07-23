// 链表类型接口定义

typedef struct node *link;

struct node {
        Item item;
        link next;
};

link NEW(Item, link);
link init(int);
void show(link);
link sort(link);