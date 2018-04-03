#include <stdio.h>
#include <stdlib.h>
#include "seqstr.h"

// 求给定顺序串的子串
seqstring *substring(seqstring S, int i, int len)
{
        int k;
        seqstring *r;
        if (i<1 || i>S.length || i+len-1>S.length) { // 处理非法情况
                printf("\n发生错误！\n");
                return NULL;
        } else {
                r = (seqstring*)malloc(sizeof(seqstring));
                for (k = 0; k < len; k++) // 复制子串到 r 的字符数组
                        r->str[k] = S.str[i+k-1];
                r->length = len;
                r->str[r->length] = '\0';
        }
        return r;
}