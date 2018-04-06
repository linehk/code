#include "seqlist.h"

// 顺序查找非递归算法
int seqSearch(seqlist l, datatype key)
{
        int k = l.len - 1;
        while (k>=0 && l.data[k]!=key)
                k--;
        return k;
}