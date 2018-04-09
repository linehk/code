#include "table.h"

// 一次归并算法，将有序段 tabs[u...m] 和 tabs[m+1...v] 合并成有序段 tabg[u...v]
void merge(table *tabs, table *tabg, int u, int m, int v)
{
        int i, j, k, t;
        i = u; // i 从第 1 段的起始位置开始，一直到最终位置 m
        j = m + 1; // j 从第 2 段的起始位置开始，一直到最终位置 v
        k = u; // k 表示的是目标 tabg 的起始位置
        while (i<=m && j<=v) { // 将两段有序元素中元素值较小的元素依次放入目标 tabg 中
                if (tabs->r[i].key <= tabs->r[j].key) {
                        tabg->r[k] = tabs->r[i];
                        i++;
                } else {
                        tabg->r[k] = tabs->r[j];
                        j++;
                }
                k++;
        }
        if (i <= m) { // 将第 1 段剩余元素放到目标 tabg 中
                for (t = i; t <= m; t++)
                        tabg->r[k+t-i] = tabs->r[t];
        } else { // 将第 2 段剩余元素放到目标 tabg 中
                for (t = j; t <= v; t++)
                        tabg->r[k+t-j] = tabs->r[t];
        }
}