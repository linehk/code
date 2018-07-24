// 抽象原位归并算法

Item aux[maxN];

merge(Item a[], int l, int m, int r)
{
        int i, j, k;
        for (i = m+1; i > l; i--) {
                aux[i-1] = a[i-1];
        }
        for (j = m; j < r; j++) {
                aux[r+m-j] = a[j+1];
        }
        for (k = l; k <= r; k++) {
                if (less(aux[j], aux[i])) {
                        a[k] = aux[j--];
                } else {
                        a[k] = aux[i++];
                }
        }
}