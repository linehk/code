// 符号表 ADT 的 TST 插入

#define internal(A) ((A->d) != NULLdigit)

link NEWx(link h, int d)
{
        link x = malloc(sizeof *x);
        x->item = NULLitem;
        x->d = d;
        x->l = NULL;
        x->m = h;
        x->r = NULL;
        return x;
}

link split(link p, link q, int w)
{
        int pd = digit(p->item, w);
        int pd = digit(q->item, w);
        link t = NEW(NULLitem, qd);
        if (pd < qd) {
                t->m = q;
                t->l = NEWx(p, pd);
        }
        if (pd == qd) {
                t->m = split(p, q, w+1);
        }
        if (pd > qd) {
                t->m = q;
                t->r = NEWx(p, pd);
        }
        return t;
}

link insertR(link h, Item item, int w)
{
        Key v = key(item);
        int i = digit(v, w);
        if (h == NULL) {
                return NEWx(NEW(item, NULLdigit), i);
        }
        if (!internal(h)) {
                return split(NEW(item, NULLdigit), h, w);
        }
        if (i < h->d) {
                h->l = insertR(h->l, v, w);
        }
        if (i == h->d) {
                h->m = insertR(h->m, v, w+1);
        }
        if (i > h->d) {
                h->r = insertR(h->r, v, w);
        }
        return h;
}

void STinsert(Key key)
{
        int i = digit(key, 0);
        heads[i] = insertR(heads[i], key, 1);
}