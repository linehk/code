#include <stdio.h>
#include "seqstr.h"

// 顺序串的删除
void strdelete(seqstring *S, int i, int len)
{
        int k;
        if (i<1 || i>S->length || i+len-1>S->length) { // 非法情况的处理
                printf("无法删除！\n");
        } else {
                for (k = i+len-1; k < S->length; k++)
                // S 中从下标为 i+len-1开始的元素前移
                        S->str[k-len] = S->str[k];
                S->length = S->length - len;
                S->str[S->length] = '\0'; // 置字符串 S 新的结束符
        }
}