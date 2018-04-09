#include "table.h"

// 快速排序算法
void quicksort(table *tab, int left, int right)
{
        int i, j;
        if (left < right) {
                i = left;
                j = right;
                 // 准备以本次最左边的元素值为标准进行划分，先保存其值
                tab->r[0] = tab->r[i];
                do {
                        while (tab->r[j].key>tab->r[0].key && i<j)
                                j--; // 从右向左找第 1 个不小于标准值的位置 j
                        if (i < j) { // 找到了，位置为 j
                                tab->r[i].key = tab->r[j].key;
                                i++; // 将第 j 个元素置于左端并重置 i
                        }
                        while (tab->r[i].key<tab->r[0].key && i<j)
                                i++; // 从左向右找第 1 个不大于标准值的位置 i
                        if (i < j) { // 找到了，位置为 i
                                tab->r[j].key = tab->r[i].key;
                                j--; // 将第 i 个元素置于右端并重置 j
                        }
                } while (i != j);
                tab->r[i] = tab->r[0]; // 将标准值放入它的最终位置，本次划分结束
                quicksort(tab, left, i-1); // 对标准值的左半部递归调用本函数
                quicksort(tab, i+1, right); // 对标准值的右半部递归调用本函数
        }
}