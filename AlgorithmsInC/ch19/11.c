// 强分量（Tarjan 算法）

void SCdfsR(Graph G, int w)
{
        link t;
        int v;
        int min;
        pre[w] = cnt0++;
        low[w] = pre[w];
        min = low[w];
        s[N++] = w;
        for (t = G->adj[w]; t != NULL; t = t->next) {
                if (pre[t->v] == -1) {
                        SCdfsR(G, t->v);
                }
                if (low[t->v] < min) {
                        min = low[t->v];
                }
        }
        if (min < low[w]) {
                low[w] = min;
                return;
        }
        do {
                G->sc[(v = s[--N])] = cnt1;
                low[v] = G->V;
        } while (s[N] != w);
        cnt1++;
}