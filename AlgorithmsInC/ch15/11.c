// 符号表 ADT 的 TST 搜索

Item searchR(link h, Key v, int w)
{
        int i = digit(v, w);
        if (h == NULL) {
                return NULLitem;
        }
        if (internal(h)) {
                if (i < h->d) {
                        return searchR(h->l, v, w);
                }
                if (i == h->d) {
                        return searchR(h->m, v, w+1);
                }
                if (i > h->d) {
                        return searchR(h->r, v, w);
                }
        }
        if eq(v, key(h->item)) {
                return h->item;
        }
        return NULLitem;
}

Item STsearch(Key v)
{
        return searchR(heads[digit(v, 0)], v, 1);
}