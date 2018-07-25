// Batcher 奇偶排序（非递归版本）

void batchersort(itemType a[], int l, int r)
{
        int i, j, k, p, N = r-l+1;
        for (p = 1; p < N; p += p) {
                for (k = p; k > 0; k /= 2) {
                        for (j = k%p; j+k < N; j += (k+k)) {
                                for (i = 0; i < k; i++) {
                                        if (j+i+k < N) {
                                                if ((j+i)/(p+p) == (j+i+k)/(p+p)) {
                                                        compexch(a[l+j+i], a[l+j+i+k]);
                                                }
                                        }
                                }
                        }
                }
        }
}