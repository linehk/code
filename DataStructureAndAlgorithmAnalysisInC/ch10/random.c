#include <stdio.h>

static unsigned long Seed = 1;

#define A 48271L
#define M 2147483647L

double Random(void)
{
    Seed = (A * Seed) % M;
    return (double)Seed / M;
}

void Initialize(unsigned long InitVal)
{
    Seed = InitVal;
}