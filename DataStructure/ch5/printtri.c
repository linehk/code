#include <stdio.h>

// 打印输出数学三角形
void print(int n)
{
        int i;
        if (n != 0) {
                print(n-1);
                for (i = 1; i <= n; i++)
                        printf("%d", n);
                printf("\n");
        }
}