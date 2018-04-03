#include "linkstr.h"

// 链式串的连接
void strconcat(linkstring *S1, linkstring S2)
{
        linkstring p;
        if (!(*S1)) { // 考虑串 S1 为空串的情况
                *S1 = S2;
                return;
        } else {
                if (S2) { // S1 和 S2 均不为空串的情况
                        p = *S1; // 用 p 查找 S1 的最后一个字符的位置
                        while (p->next)
                                p = p->next;
                        p->next = S2; // 将串 S2 连接到 S1 之后
                }
        }
}