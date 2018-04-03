#include "seqstr.h"

// 字符串朴素模式匹配算法的实现
// 寻找模式 p 在正文 t 中首次出现的起始位置
int index(seqstring p, seqstring t)
{
        int i, j, succ;
        i = 0, succ = 0; // 用 i 扫描正文 t，succ 为匹配成功的标志
        while ((i<=t.length-p.length) && (!succ)) {
                j = 0;
                succ = 1; // 用 j 扫描模式 p
                while ((j<=p.length-1) && succ) {
                        if (p.str[j] == t.str[i+j])
                                j++;
                        else
                                succ = 0;
                }
                ++i;
        }
        if (succ)
                return (i-1);
        else
                return -1;

}