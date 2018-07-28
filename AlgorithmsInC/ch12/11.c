// BST 中的旋转

link rotR(link h)
{
        link x = h->l;
        h->l = x->r;
        x->r = h;
        return x;
}

link rotL(link h)
{
        link x = h->r;
        h->r = x->l;
        x->l = h;
        return x;
}