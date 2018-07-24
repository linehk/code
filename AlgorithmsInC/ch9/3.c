// 自底向上堆化

fixUp(Item a[], int k)
{
        while (k > 1 && less(a[k/2], a[k])) {
                exch(a[k], a[k/2]);
                k = k / 2;
        }
}