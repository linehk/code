// cat map6 | ./a.out
#include <stdio.h>

int main() {
    int n, m, i, k;

    int u[6], v[6], w[6];

    int first[5], next[5];

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        first[i] = -1;
    }

    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    k = first[1];
    while (k != -1) {
        printf("%d %d %d\n", u[k], v[k], w[k]);
        k = next[k];
    }

    for (i = 1; i <= n; i++) {
        k = first[i];
        while (k != -1) {
            printf("%d %d %d\n", u[k], v[k], w[k]);
            k = next[k];
        }
    }
    return 0;
}