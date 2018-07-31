// 线索插入

void STinit()
{
        head = (z = NEW(NULLitem, 0, 0, 0));
}

link split(link p, link q, int w)
{
        link t = NEW(NULLitem, z, z, 2);
        switch (digit(p->item, w)*2 + digit(q->item, w)) {
        case 0:
                t->l = split(p, q, w+1);
                break;
        case 1:
                t->l = p;
                t->r = q;
                break;
        case 2:
                t->r = p;
                t->l = q;
                break;
        case 3:
                t->r = split(p, q, w+1);
                break;
        }
        return t;
}

link insertR(link h, Item item, int w)
{
        Key v = key(item);
        if (h == z) {
                return NEW(item, z, z, 1);
        }
        if ((h->l == z) && (h->r == z)) {
                return split(NEW(item, z, z, 1), h, w);
        }
        if (digit(v, w) == 0) {
                h->l = insertR(h->l, item, w+1);
        } else {
                h->r = insertR(h->r, item, w+1);
        }
        return h;
}

void STinsert(Item item)
{
        head = insertR(head, item, 0);
}