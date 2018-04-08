#include "table.h"

// 二分法插入排序算法
void binarysort(table *tab)
{
        int i, j, left, right, mid;
        for (i = 2; i <= tab->length; i++) { // 依次插入从第 2 个开始的所有元素
                tab->r[0] = tab->r[i]; // 保存待插入的元素
                left = 1;
                right = i - 1; // 设置查找范围的左、右位置值
                while (left < right) {
                        mid = (left+right) / 2;
                        if (tab->r[i].key < tab->r[mid].key)
                                right = mid - 1;
                        else
                                left = mid + 1; // 插入位置为 left
                }
                for (j = i-1; j >= left; j--)
                        tab->r[j+1] = tab->r[j]; // 后移，空出插入位置
                tab->r[left] = tab->r[0]; // 插入第 i 个元素的副本
        }
}