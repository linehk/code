// 动态规划法构造最佳二叉排序树

#define n 20 // n 为内部结点最大个数
int p[n], q[n+1]; // p q 分别存放内部结点与外部结点的查找概率
void ConBestTree(int c[n+1][n+1], int w[n+1][n+1], int r[n+1][n+1], int n0)
{
        int i, j, k0, k, d, m;
        for (i = 0; i <= n0; i++) { // 初始化，三个矩阵下三角清零
                for (j = 0; j <= i; j++) {
                        c[i][j] = 0;
                        r[i][j] = 0;
                        w[i][j] = 0;
                }
        }
        for (i = 0; i <= n0; i++) { // 构造初始 w[i, j] 矩阵
                w[i][i] = q[i];
                for (j = i+1; j <= n0; j++)
                        w[i][j] = w[i][j-1] + p[j] + q[j];
        }
        for (j = 1; j <= n0; j++) { // 构造一个内部结点的最佳二叉排序树
                c[j-1][j] = w[j-1][j];
                r[j-1][j] = j;
        }
        for (d = 2; d <= n0; d++) { // 构造包括 d 个内部结点的最佳二叉排序树
                for (j = d; j <= n0; j++) {
                        i = j - d;
                        m = c[i+1][j]; // 根为 i+1，右子树花费为 C[i+1, j]
                        k0 = i + 1;
                        for (k = i+2; k <= j; k++) {
                                if (c[i][k-1]+c[k][j] < m) {
                                        m = c[i][k-1] + c[k][j];
                                        k0 = k;
                                }
                        }
                        c[i][j] = w[i][j] + m;
                        r[i][j] = k0;
                }
        }
}