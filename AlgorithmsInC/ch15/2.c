// 线索搜索

Item searchR(link h, Key v, int w)
{
        if (h == z) {
                return NULLitem;
        }
        if ((h->l == z) && (h->r == z)) {
                return eq(v, key(h->item)) ? h->item : NULLitem;
        }
        if (digit(v, w) == 0) {
                return searchR(h->l, v, w+1);
        } else {
                return searchR(h->r, v, w+1);
        }
}

Item STsearch(Key v)
{
        return searchR(head, v, 0);
}