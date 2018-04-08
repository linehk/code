#include "table.h"

// Shell 插入排序算法
void shellinsertsort(table *tab)
{
        int i, j, d;
        d = tab->length / 2;
        while (d >= 1) {
                // 从第 d+1 个元素开始，将所有元素有序插入相应分组中
                for (i = d+1; i <= tab->length; i++) {
                        tab->r[0] = tab->r[i]; // 保存第 i 个元素
                        j = i - d; // 向前找插入位置
                        // 排序码比较找插入位置并后移
                        while (j>0 && tab->r[0].key<tab->r[j].key) {
                                tab->r[j+d] = tab->r[j]; // 记录后移
                                j = j - d; // 继续向前查找
                        }
                        tab->r[j+d] = tab->r[0]; // 插入第 i 个元素的副本
                }
                d = d / 2;
        }
}