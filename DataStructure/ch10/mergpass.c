#include "table.h"
#include "merge.c"

// 一趟归并算法，将 tabs 中 长度为 len 的连续有序段使用 merge() 函数
// 归并成长度为 2*len 的有序段存入 tabg 中
void mergepass(table *tabs, table *tabg, int len)
{
        int i, j, n;
        n = tabg->length = tabs->length;
        i = 1;
        // 将以 i 为起点，长度为 len 的相邻两个有序段依次进行归并
        while (i <= n-2*len+1) {
                merge(tabs, tabg, i, i+len-1, i+2*len-1); // 一次归并
                i = i + 2 * len; // 置下一个一次归并的起始位置
        }
        // 对剩下的 1 个长为 len，另一个长度不足 len，终点为 n 的两个有序段归并
        if (i+len-1 < n) {
                merge(tabs, tabg, i, i+len-1, n);
        } else { // 对剩下的 1 个长不超过 len，终点为 n 的有序段进行处理
                for (j = i; j <= n; j++)
                        tabg->r[j] = tabs->r[j];
        }
} // 本算法结束后 tabg 中的有序段的长度为 2*len