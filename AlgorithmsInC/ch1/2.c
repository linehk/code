// 连通问题的快速合并解法

#include <stdio.h>

#define N 10000

main()
{
        int i, p, q, j, id[N];

        for (i = 0; i < N; i++) {
                id[i] = i;
        }

        while (scanf("%d %d\n", &p, &q) == 2) {
                for (i = p; i != id[i]; i = id[i]) {
                        ;
                }
                for (j = q; j != id[j]; j = id[j]) {
                        ;
                }
                if (i == j) {
                        continue;
                }
                id[i] = j;
                printf(" %d %d\n", p, q);
        }
}