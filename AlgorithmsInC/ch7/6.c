// 选择算法

select(Item a[], int l, int r, int k)
{
        int i;
        if (r <= l) {
                return;
        }
        i = partition(a, l, r);
        if (i > k) {
                select(a, l, i-1, k);
        }
        if (i < k) {
                select(a, i+1, r, k);
        }
}