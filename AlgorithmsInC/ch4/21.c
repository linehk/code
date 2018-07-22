// 多项式客户程序（二项系数）

#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"

main(int argc, char *argv[])
{
        int N = atoi(argv[1]);
        float p = aotf(argv[2]);
        Poly t, x;
        int i, j;
        printf("Binomial coefficients\n");
        t = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
        for (i = 0, x = t; i < N; i++) {
                x = POLYmult(t, x);
                showPOLY(x);
        }
        printf("%f\n", POLYeval(x, p));
}