#include <stdio.h>

int a[101], n;

void quicksort(int left, int right) {
    int i, j, t, temp;
    if (left > right) {
        return;
    }

    temp = a[left]; // temp is benchmark numbers
    i = left;
    j = right;
    while (i != j) {
        /* from big to small
        a[j] <= temp 
        a[i] >= temp
        */

        /* from small to big
        a[j] >= temp
        a[i] <= temp
        */

        // first right to left
        while (a[j] >= temp && i < j) {
            j--;
        }
        // then left to right
        while (a[i] <= temp && i < j) {
            i++;
        }

        // swap that two numbers at array
        if (i < j) { // when i j didn't meet
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    // last set benchmark
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i-1); // continue deal left
    quicksort(i+1, right); // continue deal right
}

int main() {
    int i, j, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(1, n);

    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}