// 生成树替换

int onpath(link st[], int a, int b, int c)
{
        int i;
        for (i = a; i != c; i = ST(i)) {
                if (i == b) {
                        return 1;
                }
        }
        return 0;
}

int reverse(link st[], int u, int x)
{
        int i;
        while (i != st[x]->v) {
                i = st[u]->v;
                st[i] = st[u]->dup;
                u = i;
        }
}

int update(link st[], link w, link y)
{
        int t;
        int u = y->v;
        int v = y->dup->v;
        int x = w->v;
        if (st[x] != w->dup) {
                x = w->dup->v;
        }
        t = lca(st, u, v);
        if (onpath(st, u, x, t)) {
                st[u] = y;
                reverse(st, u, x);
                return;
        }
        if (onpath(st, v, x, t)) {
                st[v] = y->dup;
                reverse(st, v, x);
                return;
        }
}