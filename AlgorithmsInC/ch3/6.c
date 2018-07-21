// 数组的动态存储分配

#include <stdio.h>
#include <stdlib.h>

main(int argc, int *argv[])
{
        long int i, j, N = atol(argv[1]);
        int *a = malloc(N*sizeof(int));
        if (a == NULL) {
                printf("Insufficient memory.\n");
                return;
        }
        for (i = 2; i < N; i++) {
                a[i] = 1;
        }
        for (i = 2; i < N; i++) {
                if (a[i]) {
                        for (j = i; i*j < N; j++) {
                                a[i*j] = 0;
                        }
                }
        }
        for (i = 2; i < N; i++) {
                if (a[i]) {
                        printf("%4d ", i);
                }
        }
        printf("\n");
}