#include "seqstr.h"

// 字符串 KMP 模式匹配算法的实现
int kmp(seqstring t, seqstring p, int next[])
{
        int i, j;
        i = 0;
        j = 0;
        while (i<t.length && j<p.length) {
                if (j==-1 || t.str[i]==p.str[j]) {
                        i++;
                        j++;
                } else {
                        j = next[j];
                }
        }
        if (j == p.length)
                return (i-p.length);
        else
                return -1;
}