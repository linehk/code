// 多路堆 PQ 实现

fixUp(Item a[], int k)
{
        while (k > 1 && less(a[(k + d - 2) / d], a[k])) {
                exch(a[k], a[(k + d - 2)]);
                k = (k + d - 2) / d;
        }
}

fixDown(Item a[], int k, int N)
{
        int i;
        int j;
        while ((d * (k - 1) + 2) < N) {
                j = d * (k - 1) + 2;
                for (i = j + 1; (i < j + d) && (i <= N); i++) {
                        if (less(a[j], a[i])) {
                                j = i;
                        }
                }
                if (!less(a[k], a[j])) {
                        break;
                }
                exch(a[k], a[j]);
                k = j;
        }
}