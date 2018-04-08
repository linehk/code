#include "table.h"
#include "sift.c"

// 堆排序算法
void heapsort(table *tab)
{
        int i;
        for (i = tab->length/2; i >= 1; i--) // 对所有元素建堆
                sift(tab, i, tab->length);
        for (i = tab->length; i >= 2; i--) {
                // 将堆中最小元素和最后一个元素交换
                tab->r[0] = tab->r[i];
                tab->r[i] = tab->r[1];
                tab->r[1] = tab->r[0];
                sift(tab, 1, i-1);
        }
}