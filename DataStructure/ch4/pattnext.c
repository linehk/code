#include <stdio.h>
#include "seqstr.h"

// 根据模式 p 的组成求对应的 next 数组值
void getnext(seqstring p, int next[])
{
        int i, j;
        next[0] = -1;
        i = 0;
        j = -1;
        while (i < p.length) {
                if (j==-1 || p.str[i]==p.str[j]) {
                        ++i;
                        ++j;
                        next[i] = j;
                } else {
                        j = next[j];
                }
        }
        for (i = 0; i < p.length; i++)
                printf("%d", next[i]);
}