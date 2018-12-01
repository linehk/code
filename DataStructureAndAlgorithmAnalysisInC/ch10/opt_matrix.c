// 找出矩阵优化相乘顺序

#include <stdio.h>
#include <limits.h>

typedef long int TwoDimArray[5][5];
#define Infinity INT_MAX

void OptMatrix(const long C[], int N, TwoDimArray M, TwoDimArray LastChange)
{
        int i, k, Left, Right;
        long ThisM;

        for (Left = 1; Left <= N; Left++)
                M[Left][Left] = 0;
        for (k = 1; k < N; k++)
                for (Left = 1; Left <= N - k; Left++)
                {
                        Right = Left + k;
                        M[Left][Right] = Infinity;
                        for (i = Left; i < Right; i++)
                        {
                                ThisM = M[Left][i] + M[i + 1][Right]
                                        + C[Left - 1] * C[i] * C[Right];
                                if (ThisM < M[Left][Right])
                                {
                                        M[Left][Right] = ThisM;
                                        LastChange[Left][Right] = i;
                                }
                        }
                }
}