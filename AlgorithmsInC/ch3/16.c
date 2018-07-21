// 二维数组分配

int **a = malloc2d(M, N);

int **malloc2d(int r, int c)
{
        int i;
        int **t = malloc(r * sizeof(int *));

        for (i = 0; i < r; i++) {
                t[i] = malloc(c * sizeof(int));
        }
        return t;
}