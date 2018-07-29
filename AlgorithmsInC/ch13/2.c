// 随机化 BST 插入

link insertR(link h, Item item)
{
        Key v = key(item), t = key(h->item);
        if (h == z) {
                return NEW(item, z, z, 1);
        }
        if (rand() < RAND_MAX/(h->N+1)) {
                return insertT(h, item);
        }
        if less(v, t) {
                h->l = insertR(h->l, item);
        } else {
                h->r = insertR(h->r, item);
        }
        (h->N)++;
        return h;
}

void STinsert(Item item)
{
        head = insertR(head, item);
}