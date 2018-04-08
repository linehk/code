#include "table.h"

// 筛选算法
void sift(table *tab, int k, int m)
{
        int i, j, finished;
        i = k;
        j = 2 * i;
        tab->r[0] = tab->r[k];
        finished = 0;
        while (j<=m && !finished) {
                if (j<m && tab->r[j+1].key<tab->r[j].key)
                        j++;
                if (tab->r[0].key <= tab->r[j].key) {
                        finished = 1;
                } else {
                        tab->r[i] = tab->r[j];
                        i = j;
                        j = 2 * j;
                }
        }
        tab->r[i] = tab->r[0];
}