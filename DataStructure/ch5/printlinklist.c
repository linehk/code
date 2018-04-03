#include <stdio.h>
#include "hlnklist.h"

// 从左到右输出带头结点的单链表中所指元素的值
void plefttoright(linklist head)
{
        if (head->next) {
                printf("%5d", head->next->data); // 输出链表的第一个结点
                plefttoright(head->next); // 递归输出后序结点
        }
}

// 从右到左输出带头结点的单链表中所指元素的值
void prighttoleft(linklist head)
{
        if (head->next) {
                prighttoleft(head->next); // 递归输出后序结点
                printf("%d", head->next->data); // 输出链表的第一个结点
        }
}