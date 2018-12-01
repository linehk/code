#include <stdio.h>
#include <string.h>

int main() {
    char a[101], s[101];
    int i, len, mid, next, top;

    /*
    example a = aahaa
    len = 5; mid = 1; next = 3;
    */
    gets(a); // input one line string
    len = strlen(a); // get string length
    mid = len / 2 - 1; // get string midpoint

    top = 0; // init stack

    // order add char before mid to stack
    for (i = 0; i <= mid; i++) {
        s[++top] = a[i];
    }

    // judge odd or even and find need to match char sub
    if (len % 2 == 0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }

    // start match
    for (i = next; i <= len-1; i++) {
        if (a[i] != s[top]) {
            break;
        }
        top--;
    }

    // when top == 0, stack char been match one-by-one
    if (top == 0) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}