// backet_sort O(M+N)
#include <stdio.h>

int main() {
    int a[11], i, j, t;

    //initialization to zero
    for (i = 0; i <= 10; i++) {
        a[i] = 0;
    }

    //loop input five numbers
    for (i = 1; i <= 5; i++) {
        scanf("%d", &t); //input to t
        a[t]++; //count it
    }

    // i = 0; i <= 10; i++ from small to big
    // i = 10; i >= 0; i-- from big to small
    for (i = 0; i <= 10; i++) { // order judge a[0]~a[10]
        for (j = 1; j <= a[i]; j++) { // decide print times
            printf("%d ", i);
        }
    }
    
    return 0;
}