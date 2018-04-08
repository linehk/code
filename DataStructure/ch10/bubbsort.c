#include "table.h"

// 冒泡排序算法
void bubblesort(table *tab)
{
        int i, j, done;
        i = 1;
        done = 1;
        // 最多进行 tab->length 次冒泡，如没有发生交换则结束
        while (i<=tab->length && done) {
                done = 0;
                for (j = 1; j <= tab->length-i; j++) {
                        // 相邻两记录的排序码不符合排序要求，则进行交换
                        if (tab->r[j+1].key < tab->r[j].key) {
                                // 以第 0 个元素作为中间单元进行交换
                                tab->r[0] = tab->r[j];
                                tab->r[j] = tab->r[j+1];
                                tab->r[j+1] = tab->r[0];
                                done = 1;
                        }
                }
                i++;
        }
}