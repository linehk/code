#include <stdio.h>

int main() {
    int data[101], right[101];
    int i, n, t, len;
    // input already have numbers
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
    }
    len = n;

    // init array right
    for (i = 1; i <= n; i++) {
        if (i != n) {
            right[i] = i + 1;
        } else {
            right[i] = 0;
        }
    }

    // add a number at array data last
    len++;
    scanf("%d", &data[len]);

    // range from linked_list head
    t = 1;
    while (t != 0) {
        // if current node next node value > insert
        // insert to middle
        if (data[right[t]] > data[len]) {
            //TOOD // new insert number next node sub = current node 
            right[len] = right[t];
            right[t] = len;
            break; // insert already break
        }
        t = right[t];
    }

    // print all linked_list numbers
    t = 1;
    while (t != 0) {
        printf("%d ", data[t]);
        t = right[t];
    }

    return 0;
}