// BST 中的伸展插入

link splay(link h, Item item)
{
        Key v = key(item);
        if (h == z) {
                return NEW(item, z, z, 1);
        }
        if (less(v, key(h->item))) {
                if (hl == z) {
                        return NEW(item, z, h, h->N+1);
                }
                if (less(v, key(hl->item))) {
                        hll = splay(hll, item);
                        h = rotR(h);
                } else {
                        hlr = splay(hlr, item);
                        hl = rotL(hl);
                }
                return rotR(h);
        } else {
                if (hr == z) {
                        return NEW(item, h, z, h->N+1);
                }
                if (less(key(hr->item), v)) {
                        hrr = splay(hrr, item);
                        h = rotL(h);
                } else {
                        hrl = splay(hrl, item);
                        hr = rotR(h);
                }
                return rotL(h);
        }
}

void STinsert(Item item)
{
        head = splay(head, item);
}