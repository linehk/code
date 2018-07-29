// 随机化 BST 组合

link joinR(link a, link b)
{
        if (a == z) {
                return b;
        }
        b = insertR(b, a->item);
        b->l = STjoin(a->l, b->l);
        b->r = STjoin(a->r, b->r);
        fixN(b);
        free(a);
        return b;
}

link STjoin(link a, link b)
{
        if (rand() / (RAND_MAX/(a->N+b->N)+1) < a->N) {
                joinR(a, b);
        } else {
                joinR(b, a);
        }
}