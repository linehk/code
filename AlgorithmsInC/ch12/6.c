// （基于数组的符号表的）二分搜索

#include <stdlib.h>
#include "Item.h"
#include "ST.h"

Item search(int l, int r, Key v)
{
        int m = (l+r) / 2;
        // 插值搜索
        // m = 1 + (v - key(a[1]))((r-l)/(key(a[r]) - key(a[l])));
        if (l > r) {
                return NULLitem;
        }
        if eq(v, key(st[m])) {
                return st[m];
        }
        if (l == r) {
                return NULLitem;
        }
        if less(v, key(st[m])) {
                return search(l, m-1, v);
        } else {
                return search(m+1, r, v);
        }
}

Item STsearch(Key v)
{
        return search(0, N-1, v);
}