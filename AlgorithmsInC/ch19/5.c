// 用二叉 DAG 来表示一个二叉树

int compressR(link h)
{
        int l;
        int r;
        int t;
        if (h == NULL) {
                return 0;
        }
        l = compressR(h->l);
        r = compressR(h->r);
        t = STindex(l * VMax + r);
        adj[t].l = l;
        adj[t].r = r;
        return t;
}