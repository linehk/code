// 自顶向下的归并排序

void mergesort(Item a[], int l, int r)
{
        int m = (r+l) / 2;
        if (r <= l) {
                return;
        }
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
}