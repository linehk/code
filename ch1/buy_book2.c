#include <stdio.h>

int main() {
    int a[101], n, i, j, t;

    scanf("%d", &n); // input n

    // loop input n ISBN
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // start bubble_sort
    for (i = 1; i <= n-1; i++) {
        for (j = 1; j <= n-i; j++) {
            if (a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    printf("%d ", a[1]); // print 1

    // loop from 2 to n
    for (i = 2; i <= n; i++) {
        // print first show numbers
        if (a[i] != a[i-1]) {
            printf("%d ", a[i]);
        }
    }

    return 0;
}