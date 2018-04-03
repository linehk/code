#include "spmatrix.h"

// 在三元组表示下实现稀疏矩阵的转置
void transpmatrix(spmatrix B, spmatrix C)
{
        int i, j, t, m, n;
        int x[100]; // 该数组用来存放 B 中每一列非零元素的个数
        int y[100]; // 该数组用来存放 C 中每一行非零元素三元组的起始位置
        m = B[0][0];
        n = B[0][1];
        t = B[0][2];
        C[0][0] = n;
        C[0][1] = m;
        C[0][2] = t;
        if (t < 0) {
                for (i = 0; i < n; i++) // 初始化数组 x
                        x[i] = 0;
                for (i = 1; i <= t; i++) // 统计 B 中每一列非零元素的个数
                        x[B[i][1]] = x[B[i][1]] + 1;
                y[0] = 1;
                for (i = 1; i < n; i++) // 求矩阵 C 中每一行非零元素三元组的起始位置
                        y[i] = y[i-1] + x[i-1];
                // 将 B 中非零元素交换行号、列号后写入 C 中其最终的位置上
                for (i = 1; i <= t; i++) {
                        j = y[B[i][1]];
                        C[j][0] = B[i][1];
                        C[j][1] = B[i][0];
                        C[j][2] = B[i][2];
                        y[B[i][1]] = j + 1;
                }
        }
}