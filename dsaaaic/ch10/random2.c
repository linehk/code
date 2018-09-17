#include <stdio.h>

static unsigned long Seed = 1;

#define A 48271L
#define M 2147483647L
#define Q (M / A)
#define R (M % A)

double Random(void)
{
        long TmpSeed;

        TmpSeed = A * (Seed % Q) - R * (Seed / Q);
        if (TmpSeed >= 0)
                Seed = TmpSeed;
        else
                Seed = TmpSeed + M;

        return (double)Seed / M;
}

void Initialize(unsigned long InitVal)
{
        Seed = InitVal;
}