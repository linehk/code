#include <stdio.h>
#include <stdlib.h>
#include "linkstr.h"

// 求给定链式串的子串
linkstring substring(linkstring S, int i, int len)
{
        int k;
        linkstring p, q, r, t;
        p = S;
        k = 1;
        while (p && k<i) { // 用 p 查找 S 中第 i 个字符
                p = p->next;
                k++;
        }
        if (!p) { // 处理 S 中第 i 个字符不存在的情况
                printf("错误\n");
                return NULL;
        } else {
                r = (linkstring)malloc(sizeof(linkstrnode));
                r->data = p->data;
                r->next = NULL;
                k = 1;
                q = r; // 用 q 始终指向子串的最后一个字符的位置
                while (p->next && k<len) { // 取长度为 len 的子串
                        p = p->next;
                        k++;
                        t = (linkstring)malloc(sizeof(linkstrnode));
                        t->data = p->data;
                        q->next = t;
                        q = t;
                }
                if (k < len) {
                        printf("错误\n");
                        return NULL;
                } else { // 处理子串的尾部
                        q->next = NULL;
                        return r;
                }
        }
}