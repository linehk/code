// BST 中的根输入

link insertT(link h, Item item)
{
        Key v = key(item);
        if (h == z) {
                return NEW(item, z, z, 1);
        }
        if (less(v, key(h->item))) {
                h->l = insertT(h->l, item);
                h = rotR(h);
        } else {
                h->r = insertT(h->r, item);
                h = rotL(h);
        }
        return h;
}

void STinsert(Item item)
{
        head = insertT(head, item);
}