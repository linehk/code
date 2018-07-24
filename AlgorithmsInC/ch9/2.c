// 优先队列数组实现

#include <stdlib.h>
#include "Item.h"

static Item *pq;
static int N;

void PQinit(int maxN)
{
        pq = malloc(maxN*sizeof(Item));
        N = 0;
}

void PQempty()
{
        return N == 0;
}

void PQinsert(Item v)
{
        pq[N++] = v;
}

Item PQdelmax()
{
        int j, max = 0;
        for (j = 1; j < N; j++) {
                if (less(pq[max], pq[j])) {
                        max = j;
                }
        }
        exch(pq[max], pq[N-1]);
        return pq[--N];
}