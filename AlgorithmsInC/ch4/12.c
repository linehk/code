// 有下标且无重复项的栈

#include <stdlib.h>

static int *s, *t;
static int N;

void STACKinit(int maxN)
{
        int i;
        s = malloc(maxN * sizeof(int));
        t = malloc(maxN * sizeof(int));

        for (i = 0; i < maxN; i++) {
                t[i] = 0;
        }
        N = 0;
}

int STACKempty()
{
        return !N;
}

void STACKpush(int item)
{
        if (t[item] == 1) {
                return;
        }
        s[N++] = item;
        t[item] = 1;
}

int STACKpop()
{
        N--;
        t[s[N]] = 0;
        return s[N];
}