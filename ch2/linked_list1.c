#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p; // define a ptr p
    // ptr p get dynamic allocation of memory address
    p = (int *)malloc(sizeof(int));
    *p = 10; // put 10 to *p point memory space
    printf("%d", *p); // print value what *p point to
    return 0;
}