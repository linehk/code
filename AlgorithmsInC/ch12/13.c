// BST 中的选择操作

Item selectR(link h, int k)
{
        int t;
        if (h == z) {
                return NULLitem;
        }
        t = (h->l == z) ? 0 : h->l->N;
        if (t > k) {
                return selectR(h->l, k);
        }
        if (t < k) {
                return selectR(h->r, k-t-1);
        }
        return h->item;
}

Item STselect(int k)
{
        return selectR(head, k);
}