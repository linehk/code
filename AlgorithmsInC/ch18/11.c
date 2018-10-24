// 随机队列实现

#include <stdlib.h>
#include "CQ.h"
static Item *s;
static int N;

void RQinit(int maxN)
{
        s = malloc(maxN * sizeof(Item));
        N = 0;
}

int RQempty() {
        return N == 0;
}

void RQput(Item x)
{
        s[N++] = x;
}

void RQupdate(Item x)
{
}

Item RQget() {
        Item t;
        int i = N * (rand() / (RAND_MAX + 1.0));
        t = s[i];
        s[i] = s[N - 1];
        s[N - 1] = t;
        return s[--N];
}