// 二进制数字搜索树

Item searchR(link h, Key v, int w)
{
        Key t = key(h->item);
        if (h == z) {
                return NULLitem;
        }
        if eq(v, t) {
                return h->item;
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