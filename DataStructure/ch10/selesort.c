#include "table.h"

// 直接选择排序算法
void simpleselectsort(table *tab)
{
        int i, j, k;
        // 每次选择一个最小的元素 (的位置) ，和第 i 个元素交换
        for (i = 1; i <= tab->length-1; i++) {
                k = i; // 记下当前最小元素的位置
                // 向右查找更小的元素
                for (j = i+1; j <= tab->length; j++) {
                        if (tab->r[j].key < tab->r[k].key)
                                k = j; // 修改当前最小元素的位置
                }
                 // 如果第 i 次选到的最小元素位置 k 不等于 i，则将第 k i 个元素交换
                if (k != i) {
                        // 以没有用到的第 0 个元素作为中间单元进行交换
                        tab->r[0] = tab->r[k];
                        tab->r[k] = tab->r[i];
                        tab->r[i] = tab->r[0];
                }
        }
}