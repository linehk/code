#include "table.h"
#include "mergpass.c"

// 归并排序算法
void mergesort(table *tab)
{
        int len;
        table temp; // 中间变量
        len = 1; // 初始时有序段的长度为 1
        while (len < tab->length) { // 有序段的长度小于待排序元素的个数，继续归并
                mergepass(tab, &temp, len); // 一趟归并，结果在 temp 中
                len = 2 * len; // 有序段的长度翻倍
                mergepass(&temp, tab, len); // 一趟归并，结果在 tab 中
                len = 2 * len; // 有序段的长度翻倍
        }
}