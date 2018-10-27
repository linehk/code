// 沿着环增大

int lca(int st[], int u, int v)
{
        int i;
        int j;
        mark[u] = ++valid;
        mark[v] = valid;
        while (u != v) {
                u = ST(u);
                v = ST(v);
                if (u != ST(u) && mark[u] == valid) {
                        return u;
                }
                mark[u] = valid;
                if (v != ST(v) && mark[v] == valid) {
                        return v;
                }
                mark[v] = valid;
        }
        return u;
}

link augment(link st[], link x)
{
        link u;
        link cyc[maxV];
        int d;
        int N;
        int t;
        int i = x->v;
        int j = x->dup->v;
        t = lca(st, i, j);
        cyc[0] = x;
        N = 1;
        while (i != t) {
                cyc[N++] = st[i]->dup;
                i = ST(i);
        }
        while (j != t) {
                cyc[N++] = st[j];
                j = ST(j);
        }
        for (i = 0, d = C; i < N; i++) {
                u = cyc[i];
                d = Q > d ? d : Q;
        }
        for (i = 0; i < N; i++) {
                addflow(cyc[i], d);
        }
        for (i = 0; i < N - 1; i++) {
                u = cyc(N - 1 - i);
                if (Q == 0) {
                        return u;
                }
        }
}