// B 树搜索

Item searchR(link h, Key v, int H)
{
        int j;
        if (H == 0) {
                for (j = 0; j < h->m; j++) {
                        if (eq(v, h->b[j].key)) {
                                return h->b[j].ref.item;
                        }
                }
        }
        if (H != 0) {
                for (j = 0; j < h->m; j++) {
                        if ((j+1 == h->m) || less(v, h->b[j+1].key)) {
                                return searchR(h->b[j].ref.next, v, H-1);
                        }
                }
        }
        return NULLitem;
}

Item STsearch(Key v)
{
        return searchR(head, v, H);
}