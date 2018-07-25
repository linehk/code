// Batcher 奇偶归并（非递归版本）

mergeBU(itemType a[], int l, int r)
{
        int i, j, k, N = r-l+1;
        for (k = N/2; k > 0; k /= 2) {
                for (j = k%(N/2); j+k < N; j += (k+k)) {
                        for (i = 0; i < k; i++) {
                                compexch(a[l+j+i], a[l+j+i+k]);
                        }
                }
        }
}