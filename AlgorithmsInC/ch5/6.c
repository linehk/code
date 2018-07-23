// 利用分治法求最大值

Item max(Item a[], int l, int r)
{
        Item u, v;
        int m = (l+r) / 2;
        if (l == r) {
                return a[l];
        }
        u = max(a, l, m);
        v = max(a, m+1, r);
        if (u > v) {
                return u;
        } else {
                return v;
        }
}