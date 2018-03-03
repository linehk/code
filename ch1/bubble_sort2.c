#include <stdio.h>

// create a struct for store name and score
struct student {
    char name[21];
    int score;
};

int main() {
    struct student a[100], t;
    int i, j, n;
    scanf("%d", &n); // input a number n

    // loop input n name and score
    for (i = 1; i <= n; i++) {
        scanf("%s %d", a[i].name, &a[i].score);
    }

    // from big to small sort
    for (i = 1; i <= n-1; i++) {
        for (j = 1; j <= n-1; j++) {
            // compare score and swap
            // a[j].score > a[j+1].score from small to big
            // a[j].score < a[j+1].score from big to small
            if (a[j].score < a[j+1].score) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    // print name
    for (i = 1; i <= n; i++) {
        printf("%s\n", a[i].name);
    }

    return 0;
}