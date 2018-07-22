// 一级队列的链表实现
#include <stdlib.h>
#include "Item.h"
#include "18.c"
// #include "QUEUE.h"

typedef struct QUEUEnode* link;
struct QUEUEnode {
        Item item;
        link next;
};

struct queue {
        link head;
        link tail;
};

link NEW(Item item, link next)
{
        link x = malloc(sizeof *x);
        x->item = item;
        x->next = next;
        return x;
}

Q QUEUEinit(int maxN)
{
        Q q = malloc(sizeof *q);
        q->head = NULL;
        return q;
}

int QUEUEempty(Q q)
{
        return q->head == NULL;
}

void QUEUEput(Q q, Item item)
{
        if (q->head == NULL) {
                q->tail = NEW(item, q->head);
                q->head = q->tail;
                return;
        }
        q->tail->next = NEW(item, q->tail->next);
        q->tail = q->tail->next;
}

Item QUEUEget(Q q)
{
        Item item = q->head->item;
        link t = q->head->next;
        free(q->head);
        q->head = t;
        return item;
}
