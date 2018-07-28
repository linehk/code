// 在 BST 中删除一个给定关键字的节点

link joinLR(link a, link b)
{
        if (b == z) {
                return a;
        }
        b = partR(b, 0);
        b->l = a;
        return b;
}

link deleteR(link h, Key v)
{
        link x;
        Key t = key(h->item);
        if (h == z) {
                return z;
        }
        if (less(v, t)) {
                h->l = deleteR(h->l, v);
        }
        if (less(t, v)) {
                h->r = deleteR(h->r, v);
        }
        if (eq(v, t)) {
                x = h;
                h = joinLR(h->l, h->r);
                free(x);
        }
        return h;
}

void STdelete(Key v)
{
        head = deleteR(head, v);
}