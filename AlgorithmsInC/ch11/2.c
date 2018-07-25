// Batcher 奇偶归并（递归版本）

mergeTD(itemType a[], int l, int r)
{
        int i, m = (l+r) / 2;
        if (r == l+1) {
                compexch(a[l], a[r]);
        }
        if (r < l+2) {
                return;
        }
        unshuffle(a, l, r);
        mergeTD(a, l, m);
        mergeTD(a, m+1, r);
        shuffle(a, l, r);
        for (i = l+1; i < r; i += 2) {
                compexch(a[i], a[i+1]);
        }
}