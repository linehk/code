#include <stdio.h>
#include "seqstr.h"

// 顺序串的插入
void strinsert(seqstring *S, int i, seqstring T)
{
        int k;
        if (i<1 || i>S->length+1 || S->length+T.length>MAXSIZE) { // 非法情况的处理
                printf("无法插入\n");
        } else {
                for (k = S->length-1; k >= i-1; k--) // S 中从第 i 的元素开始后移
                        S->str[T.length+k] = S->str[k];
                for (k = 0; k <T.length; k++) // 将 T 写入 S 中第 i 个字符开始的位置
                        S->str[i+k-1] = T.str[k];
                S->length = S->length + T.length;
                S->str[S->length] = '\0'; // 设置字符串 S 新的结束符
        }
}