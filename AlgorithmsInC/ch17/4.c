// 邻接矩阵分配和初始化

int **MATRIXint(int r, int c, int val)
{
        int i;
        int j;
        int **t = malloc(r * sizeof(int *));
        for (i = 0; i < r; i++) {
                t[i] = malloc(c * sizeof(int));
        }
        for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                        t[i][j] = val;
                }
        }
        return t;
}