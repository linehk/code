// 改进快速排序

#define M 10

void quicksort(Item a[], int l, int r)
{
        int i;
        if (r-l <= M) {
                return;
        }
        exch(a[(l+r)/2], a[r-1]);
        compexch(a[l], a[r-1]);
        compexch(a[l], a[r]);
        compexch(a[r-1], a[r]);
        i = partition(a, l+1, r-1);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
}

void sort(Item a[], int l, int r)
{
        quicksort(a, l, r);
        insertsort(a, l, r);
}