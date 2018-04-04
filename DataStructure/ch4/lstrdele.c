#include <stdio.h>
#include "linkstr.h"

// 链式串的删除
void strdelete(linkstring *S, int i, int len)
{
        int k;
        linkstring p, q, r;
        p = *S;
        q = NULL;
        k = 1;
        while (p && k<i) {
                q = p;
                p = p->next;
                k++;
        } // 用 p 查找 S 的第 i 个元素，q 始终跟踪 p 的前驱
        if (!p) { // S 的第 i 个元素不存在，则出错
                printf("错误\n");
        } else {
                k = 1;
                while (k<len && p) { // p 从第 i 个元素开始查找长度为 len 子串的最后元素
                        p = p->next;
                        k++;
                }
                if (!p) {
                        printf("错误\n");
                } else {
                        if (!q) { // 被删除的子串位于 S 的最前面
                                r = *S;
                                *S = p->next;
                        } else { // 被删除的子串位于 S 的中间或最后的情况
                                r = q->next;
                                q->next = p->next;
                        }
                        p->next = NULL;
                        while (r != NULL) { // 回收被删除的子串所占用的空间
                                p = r;
                                r = r->next;
                                free(p);
                        }
                }
        }
}