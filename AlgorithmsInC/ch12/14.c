// BST 中的划分操作

link partR(link h, int k)
{
        int t = h->l->N;
        if (t > k) {
                h->l = partR(h->l, k);
                h = rotR(h);
        }
        if (t < k) {
                h->r = partR(h->r, k-t-1);
                h = rotL(h);
        }
}