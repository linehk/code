// 求有向图的逆图（邻接表）

Graph GRAPHreverse(Graph G)
{
        int v;
        link t;
        Graph R = GRAPHinit(G->V);
        for (v = 0; v < G->V; v++) {
                for (t = G->adj[v]; t != NULL; t = t->next) {
                        GRAPHinsertE(R, EDGE(t->v, v));
                }
        }
        return R;
}