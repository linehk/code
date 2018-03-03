#include <stdio.h>

int main() {
    int a[100], i, j, t, n;
    scanf("%d", &n); // input n, next have n numbers

    // loop input n numbers to array a
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // bubble_sort core part
    for (i = 1; i <= n-1; i++) { // sort n numbers, run n-1 times
    // start at first number to last number did't set
        for (j = 1; j <= n-i; j++) {
            // compare size and swap
            // a[j] > a[j+1] from small to big
            // a[j] < a[j+1] from big to small
            if (a[j] < a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    // print result
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}