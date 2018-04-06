#include "linklist.h"

// 基于带头结点的单链表的顺序查找算法
linklist linkSearch(linklist head, datatype key)
{
        linklist p = head->next; // p 指向带头结点的单链表的第一个结点
        while (p && p->data!=key)
                p = p->next;
        return p;
}