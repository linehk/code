// 基于堆的优先队列

#include <stdlib.h>
#include "Item.h"

static Item *pq;
static int N;

void PQinit(int maxN)
{
        pq = malloc((maxN+1)*sizeof(Item));
        N = 0;
}

int PQempty()
{
        return N == 0;
}

void PQinsert(Item v)
{
        pq[++N] = v;
        fixUp(pq, N);
}

Item PQdelmax()
{
        exch(pq[1], pq[N]);
        fixDown(pq, 1, N-1);
        return pq[N--];
}