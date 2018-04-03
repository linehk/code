#include <stdio.h>
#include "linkstr.h"

// 链式串的插入
void strinsert(linkstring *S, int i, linkstring T)
{
        int k;
        linkstring p, q;
        p = *S;
        k = 1;
        while (p && k<i-1) { // 用 p 查找 S 中第 i-1 个元素的位置
                p = p->next;
                k++;
        }
        if (!p) { // 第 i-1 个元素不存在，则出错
                printf("错误\n");
        } else {
                q = T;
                while (q && q->next) // 用 q 查找 T 中最后一个元素的位置
                        q = q->next;
                q->next = p->next; // 将 T 连接到 S 中的第 i 个位置上
                p->next = T;
        }
}