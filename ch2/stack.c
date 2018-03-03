#include <stdio.h>
#include <string.h>

int main() {
    char a[101], s[101];
    int i, len, mid, next, top;

    gets(a);
    len = strlen(a);
    mid = len / 2 - 1;
    top = 0;
    for (i = 0; i <= mid; i++) {
        s[++top] = a[i];
    }

    if (len % 2 == 0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }

    for (i = next; i <= len-1; i++) {
        if (a[i] != s[top]) {
            break;
        }
        top--;
    }

    if (top == 0) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}