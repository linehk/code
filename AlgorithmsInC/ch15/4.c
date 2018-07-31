// 帕氏线索搜索

Item searchR(link h, Key v, int w)
{
        if (h->bit <= w) {
                return h->item;
        }
        if (digit(v, h->bit) == 0) {
                return searchR(h->l, v, h->bit);
        } else {
                return searchR(h->r, v, h->bit);
        }
}

Item STsearch(Key v)
{
        Item t = searchR(head->l, v, -1);
        return eq(v, key(t)) ? t : NULLitem;
}