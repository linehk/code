#include <stdio.h>
#include <stdlib.h>
#include "seqstr.h"

// 顺序串的连接
seqstring *strconcat(seqstring S1, seqstring S2)
{
        int i;
        seqstring *r;
        if (S1.length+S2.length > MAXSIZE-1) { // 处理字符数组空间不够使用的情况
                printf("\n无法连接！");
                return NULL;
        } else {
                r = (seqstring*)malloc(sizeof(seqstring));
                for (i = 0; i < S1.length; i++) // 将 S1 复制到 r 字符数组的前端
                        r->str[i] = S1.str[i];
                for (i = 0; i < S2.length; i++) // 将 S2 复制到 r 字符数组的后端
                        r->str[S1.length+i] = S2.str[i];
                r->length = S1.length + S2.length;
                r->str[r->length] = '\0';
        }
        return r;
}