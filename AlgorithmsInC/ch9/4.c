// 自顶向下堆化

fixDown(Item a[], int k, int N)
{
        int j;
        while (2*k <= N) {
                j = 2 * k;
                if (j < N && less(a[j], a[j+1])) {
                        j++;
                }
                if (!less(a[k], a[j])) {
                        break;
                }
                exch(a[k], a[j]);
                k = j;
        }
}