// 可扩展散列法的目录插入

void insertDIR(link t, int k)
{
        int i, m, x = bits(t->b[0], 0, k);
        while (d < k) {
                link *old = dir;
                d += 1;
                D += D;
                dir = malloc(D*(sizeof *dir));
                for (i = 0; i < D; i++) {
                        dir[i] = old[i/2];
                }
                if (d < k) {
                        dir(bits(x, 0, d) ^ 1) = NEW();
                }
        }
        for (m = 1; k < d; k++) {
                m *= 2;
        }
        for (i = 0; i < m; i++) {
                dir[x*m+i] = t;
        }
}