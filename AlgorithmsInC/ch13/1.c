// 平衡一棵 BST

link balanceR(link h)
{
        if (h->N < 2) {
                return h;
        }
        h = partR(h, h->N/2);
        h->l = balanceR(h->l);
        h->r = balanceR(h->r);
        return h;
}