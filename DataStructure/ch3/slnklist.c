#include <stdio.h>
#include <stdlib.h>
#include "slnklist.h"

// 建立一个空的单链表
node *init()
{
        return NULL;
}

// 输出单链表中各个结点的值
void display(node *head)
{
        node *p;
        p = head;
        if (!p) {
                printf("\n单链表是空的！");
        } else {
                printf("\n单链表各个结点的值为：\n");
                while (p) {
                        printf("%5d", p->info);
                        p = p->next;
                }
        }
}

// 在单链表中查找第 i 个结点的存放地址
node *find(node *head, int i)
{
        int j = 1;
        node *p = head;
        if (i < 1)
                return NULL;
        while (p && i!=j) {
                p = p->next;
                j++;
        }
        return p;
}

// 单链表第 i 个结点后插入值为 x 的新结点
node *insert(node *head, datatype x, int i)
{
        node *p, *q;
        q = find(head, i); // 查找第 i 个结点
        if (!q && i!=0) {
                printf("\n找不到第 %d 个结点，不能插入 %d！", i, x);
        } else {
                p = (node*)malloc(sizeof(node)); // 分配空间
                p->info = x; // 设置新结点
                if (i == 0) { // 插入的结点作为单链表的第一个结点
                        p->next = head; // 插入 (1)
                        head = p; // 插入 (2)
                } else {
                        p->next = q->next; // 插入 (1)
                        q->next = p; // 插入 (2)
                }
        }
        return head;
}

// 在单链表中删除一个值为 x 的结点
node *dele(node *head, datatype x)
{
        node *pre = NULL, *p;
        if (!head) {
                printf("单链表是空的！");
                return head;
        }
        p = head;
        while (p && p->info!=x) { // 没有找到并且没有找完
                pre = p;
                p = p->next; // pre 指向 p 的前驱结点
        }
        if (p) {
                if (!pre) {
                        head = head->next; // 要删除的是第一个结点
                } else {
                        pre->next = p->next;
                }
                free(p);
        }
        return head;
}