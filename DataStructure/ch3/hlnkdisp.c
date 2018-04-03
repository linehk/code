#include <stdio.h>
#include "slnklist.h"

// 输出带头结点的单链表中各个结点的值
void display(node *head)
{
        node *p;
        p = head->next; // 从第一个 (实际) 结点开始
        if (!p) {
                printf("\n带头结点的单链表是空的！");
        } else {
                printf("\n带头结点的单链表各个结点的值为：\n");
                while (p) {
                        printf("%5d", p->info);
                        p = p->next;
                }
        }
}
