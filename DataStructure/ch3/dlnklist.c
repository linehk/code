#include <stdio.h>
#include <stdlib.h>
#include "dlnklist.h"

// 建立一个空的双链表
dnode *init()
{
        return NULL;
}

// 输出双链表中各个结点的值
void display(dnode *head)
{
        dnode *p;
        printf("\n");
        p = head;
        if (!p) {
                printf("\n双链表是空的！\n");
        } else {
                printf("\n双链表中各个结点的值为：\n");
                while (p) {
                        printf("%5d", p->info);
                        p = p->rlink;
                }
        }
}

// 在双链表中查找第 i 的结点的存储地址
dnode *find(dnode *head, int i)
{
        int j = 1;
        dnode *p = head;
        if (i < 1) {
                printf("\n第 %d 个结点不存在！\n", i);
                return NULL;
        }
        while (p && i!=j) { // 没有找完整个表并且没有找到
                p = p->rlink;
                j++; // 继续沿着右指针向后查找，计数器加 1
        }
        if (!p) {
                printf("\n第 %d 个结点不存在！\n", i);
                return NULL;
        }
        return p;
}

// 双链表第 i 个结点后插入值为 x 的新结点
dnode *insert(dnode *head, datatype x, int i)
{
        dnode *p, *q;
        p = (dnode*)malloc(sizeof(dnode)); // 分配空间
        p->info = x; // 设置新结点的值
        if (i == 0) { // 在最前面插入一个值为 x 的新结点
                p->llink = NULL; // 新插入的结点没有前驱
                p->rlink = head; // 新插入的结点的后继是原来双链表中的第一个结点
                if (!head) { // 原表为空
                        head = q;
                } else {
                        head->llink = p; // 原来双链表第一个结点的前驱是新插入的结点
                        head = p; // 新结点成为双链表中第一个结点
                }
                return head;
        }
        q = find(head, i); // 查找第 i 个结点
        if (!q) { // 第 i 个结点不存在
                printf("第 %d 个结点不存在，无法进行插入", i);
                free(p);
                return head;
        }
        if (q->rlink == NULL) { // 在最后一个结点后插入
                p->rlink = q->rlink; // 即为 NULL，新插入的结点没有后继。插入操作 (1)
                p->llink = q; // 插入操作 (2)
                q->rlink = p; // 插入操作 (4)
                // 注意不能和下面的一般情况一样处理，这里如果执行下面的 (3) 将出错！
        } else { // 一般情况下的插入
                p->rlink = q->rlink; // 插入操作 (1)
                p->llink = q; // 插入操作 (2)
                q->rlink->llink = p; // 插入操作 (3)
                q->rlink = p; // 插入操作 (4)
        }
        return head;
}

// 在双链表中删除一个值为 x 的结点
dnode *dele(dnode *head, datatype x)
{
        dnode *q;
        if (!head) { // 双链表为空，无法进行删除操作
                printf("双链表为空，无法进行删除操作");
                return head;
        }
        q = head;
        while (q && q->info!=x)
                q = q->rlink; // 循环结束后 q 指向的是值为 x 的结点
        if (!q)
                printf("\n没有找到值为 %d 的结点！不做删除操作！", x);
        if (q==head && head->rlink) { // 被删除的结点是第一个结点并且表中不止一个结点
                head = head->rlink;
                head->llink = NULL;
                free(q);
                return head;
        }
        if (q==head && !head->rlink) { // 被删除的结点是第一个结点并且表中只有这一个结点
                free(q);
                return NULL;
        } else {
                if (!q->rlink) { // 被删除的结点是双链表中最后一个结点
                        q->llink->rlink = NULL;
                        free(q);
                        return head;
                } else { // q 是有 2 个以上结点的双链表中的一个非开始、也非终端的结点
                        q->llink->rlink = q->rlink;
                        q->rlink->llink = q->llink;
                        free(q);
                        return head;
                }
        }
}