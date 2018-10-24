// 边连通性（邻接表）

void bridgeR(Graph G, Edge e)
{
        link t;
        int v;
        int w = e.w;
        pre[w] = cnt++;
        low[w] = pre[w];
        for (t = G->adj[w]; t != NULL; t = t->next) {
                if (pre[v = t->v] == -1) {
                        bridgeR(G, EDGE(w, v));
                        if (low[w] > low[v]) {
                                low[w] = low[v];
                        }
                        if (low[v] == pre[v]) {
                                bcnt++;
                                printf("%d-%d\n", w, v);
                        }
                } else if (v != e.v) {
                        if (low[w] < pre[v]) {
                                low[w] = pre[v];
                        }
                }
        }
}