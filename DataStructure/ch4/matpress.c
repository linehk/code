#include "spmatrix.h"

// 产生系数矩阵的三元组表示
void compressmatrix(matrix A, spmatrix B)
{
        int i, j, k = 1;
        for (i = 0; i < A.m; i++) {
                for (j = 0; j < A.n; j++) {
                        if (A.data[i][j] != 0) { // 产生非零元素的三元组表示
                                B[k][0] = i;
                                B[k][1] = j;
                                B[k][2] = A.data[i][j];
                                k++;
                        }
                }
        }
        B[0][0] = A.m; // 三元组数组中第 1 行存放稀疏矩阵行数、列数和非 0 元素的个数
        B[0][1] = A.n;
        B[0][2] = k - 1;
}