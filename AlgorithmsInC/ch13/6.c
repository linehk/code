// 红黑 BST 中的插入

link RBinsert(link h, Item item, int sw)
{
        Key v = key(item);
        if (h == z) {
                return NEW(item, z, z, 1, 1);
        }
        if ((hl->red) && (hr->red)) {
                h->red = 1;
                hl->red = 0;
                hr->red = 0;
        }
        if (less(v, key(h->item))) {
                hl = RBinsert(hl, item, 0);
                if (h->red && hl->red && sw) {
                        h = rotR(h);
                }
                if (hl->red && hll->red) {
                        h = rotR(h);
                        h->red = 0;
                        hr->red = 1;
                }
        } else {
                hr = RBinsert(hr, item, 1);
                if (h->red && hr->red && !sw) {
                        h = rotL(h);
                }
                if (hr->red && hrr->red) {
                        h = rotL(h);
                        h->red = 0;
                        hl->red = 1;
                }
        }
        fixN(h);
        return h;
}

void STinsert(Item item)
{
        head = RBinsert(head, item, 0);
        head->red = 0;
}