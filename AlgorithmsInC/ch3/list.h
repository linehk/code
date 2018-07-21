// 12.c 链表处理接口

typedef struct node* link;

struct node {
        itemType item;
        link next;
};

typedef link Node;

void initNodes(int);
link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Item(link);