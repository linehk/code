// 两棵 BST 的连接

link STjoin(link a, link b)
{
        if (b == z) {
                return a;
        }
        if (a == z) {
                return b;
        }
        b = insertT(b, a->item);
        b->l = STjoin(a->l, b->l);
        b->r = STjoin(a->r, b->r);
        free(a);
        return b;
}