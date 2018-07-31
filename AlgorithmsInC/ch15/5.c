// 帕氏线索插入

void STinit()
{
        head = NEW(NULLitem, 0, 0, -1);
        head->l = head;
        head->r = head;
}

link insertR(link h, Item item, int w, link p)
{
        link x;
        Key v = key(item);
        if ((h->bit >= w) || (h->bit <= p->bit)) {
                x = NEW(item, 0, 0, w);
                x->l = digit(v, x->bit) ? h : x;
                x->r = digit(v, x->bit) ? x : h;
                return x;
        }
        if (digit(v, h->bit) == 0) {
                h->l = insertR(h->l, item, w, h);
        } else {
                h->r = insertR(h->r, item, w, h);
        }
        return h;
}

void STinsert(Item item)
{
        int i;
        Key v = key(item);
        Key t = key(searchR(head->l, v, -1));
        if (v == t) {
                return;
        }
        for (i = 0; digit(v, i) == digit(t, i); i++) {
                ;
        }
        head->l = insertR(head->l, item, i, head);
}