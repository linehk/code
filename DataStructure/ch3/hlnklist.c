#include <stdio.h>
#include <stdlib.h>
#include "slnklist.h"

// 建立一个空的带头结点的单链表
node *init()
{
        node *head;
        head = (node*)malloc(sizeof(node));
        head->next = NULL;
        return head;
}

// 在带头结点的单链表中查找第 i 个结点地址
node *find(node *head, int i)
{
        int j = 0;
        node *p = head;
        if (i < 0) {
                printf("\n带头结点的单链表不存在第 %d 个结点！", i);
                return NULL;
        } else if (i == 0) {
                return p; // 此时 p 指向的是头结点
        }
        while (p && i!=j) { // 没有查找完并且还没有找到
                p = p->next;
                j++; // 继续向后 (左)查找，计数器加 1
        }
        return p; // 返回结果，i = 0 时，p 指示的是头结点
}

// 在带头结点的单链表中第 i 个结点后插入一个值为 x 的新结点
node *insert(node *head, datatype x, int i)
{
        node *p, *q;
        q = find(head, i); // 查找带头结点的单链表中的第 i 个结点
        if (!p) {
                printf("\n带头结点的单链表不存在第 %d 个结点！不能插入 %d！", i, x);
                return head;
        }
        p = (node*)malloc(sizeof(node)); // 为准备插入的新结点分配空间
        p->info = x; // 为新结点设置值 x
        p->next = q->next; // 插入 (1)
        q->next = p;
        // 插入 (2)，当 i = 0时，由于 q 指向的是头结点，本语句等价于 head->next = p
        return head;
}

// 在带头结点的单链表中删除一个值为 x 的结点
node *dele(node *head, datatype x)
{
        node *pre = head, *q; // 首先 pre 指向头结点
        q = head->next; // q 从带头结点的第一个实际结点开始找值为 x 的结点
        while (q && q->info!=x) { // 没有查找完并且还没有找到
                pre = q;
                q = q->next; // 继续查找，pre 指向 q 的前驱
        }
        if (q) {
                pre->next = q->next; // 删除
                free(q); // 释放空间
        }
        return head;
}