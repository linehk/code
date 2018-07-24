// 归并

mergeAB(Item c[], Item a[], int N, Item b[], int M)
{
        int i, j, k;
        for (i = 0, j = 0, k = 0; k < M+N; k++) {
                if (i == N) {
                        c[k] = b[j++];
                        continue;
                }
                if (j == M) {
                        c[k] = a[i++];
                        continue;
                }
                c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
        }
}