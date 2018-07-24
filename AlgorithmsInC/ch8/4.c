// 没有复制的归并排序

Item aux[maxN];

void mergesortABr(Item a[], Item b[], int l, int r)
{
        int m = (l+r) / 2;
        if (r-l <= 10) {
                insertion(a, l, r);
                return;
        }
        mergesortABr(b, a, l, m);
        mergesortABr(b, a, m+1, r);
        mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
}

void mergesortAB(Item a[], int l, int r)
{
        int i;
        for (i = l; i <= r; i++) {
                aux[i] = a[i];
        }
        mergesortABr(a, aux, l, r);
}