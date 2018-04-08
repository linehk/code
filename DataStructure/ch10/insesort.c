#include "table.h"

// 直接插入排序算法
void insertsort(table *tab)
{
        int i, j;
        for (i = 2; i <= tab->length; i++) { // 依次插入从第 2 个开始的所有元素
                j = i - 1;
                tab->r[0] = tab->r[i]; // 设置哨兵，准备找插入位置
                while (tab->r[0].key < tab->r[j].key) { // 排序码比较找插入位置并后移
                        tab->r[j+1] = tab->r[j]; // 记录后移
                        j = j - 1; // 继续向前 (左) 查找
                }
                tab->r[j+1] = tab->r[0]; // 插入第 i 个元素的副本，即前面设置的哨兵
        }
}
