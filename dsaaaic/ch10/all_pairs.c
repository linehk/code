#include <stdio.h>

#define NotAVertex (-1)
typedef int TwoDimArray[4][4];

void AllPairs(TwoDimArray A, TwoDimArray D, TwoDimArray Path, int N)
{
        int i, j, k;

        for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                {
                        D[i][j] = A[i][j];
                        Path[i][j] = NotAVertex;
                }

        for (k = 0; k < N; k++)
                for (i = 0; i < N; i++)
                        for (j = 0; j < N; j++)
                                if (D[i][k] + D[k][j] < D[i][j])
                                {
                                        D[i][j] = D[i][k] + D[k][j];
                                        Path[i][j] = k;
                                }
}