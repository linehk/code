// backet_sort O(M+N)
#include <stdio.h>

int main() {
    int book[1001], i, j, t, n;
    for (i = 0; i <= 1000; i++) {
        book[i] = 0;
    }

    // input n, next have n numbers
    scanf("%d", &n);
    
    // loop input n numbers
    for (i = 1; i <= n; i++) {
        scanf("%d", &t); // input to t
        book[t]++; // count
    }

    // i = 0; i <= 1000; i++ from small to big
    // i = 1000; i >= 0; i-- from big to small
    for (i = 1000; i >= 0; i--) { // order judge numbers 1000~0
        for (j = 1; j <= book[i]; j++) { // decide print times
            printf("%d ", i);
        }
    }

    return 0;
}