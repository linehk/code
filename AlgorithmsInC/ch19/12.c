// 强分量（Gabow 算法）

void SCdfsR(Graph G, int w)
{
        link t;
        int v;
        pre[w] = cnt0++;
        s[N++] = w;
        path[p++] = w;
        for (t = G->adj[w]; t != NULL; t = t->next) {
                if (pre[t->v] == -1) {
                        SCdfsR(G, t->v);
                } else if (G->sc[t->v] == -1) {
                        while (pre[path[p - 1]] > pre[t->v]) {
                                p--;
                        }
                }
        }
        if (path[p - 1] != w) {
                return;
        } else {
                p--;
        }
        do {
                G->sc[s[--N]] = cnt1;
        } while (s[N] != w);
        cnt1++;
}