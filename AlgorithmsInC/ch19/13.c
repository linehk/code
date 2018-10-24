// 基于强向量的传递闭包

Dag K;
void GRAPHtc(Graph G)
{
        int v;
        int w;
        link t;
        int *sc = G->sc;
        K = DAGinit(GRAPHsc(G));
        for (v = 0; v < G->V; v++) {
                for (t = G->adj[v]; t != NULL; t = t->next) {
                        DAGinsertE(K, dagEDGE(sc[v], st[t->v]));
                }
        }
        DAGtc(K);
}

int GRAPHreach(Graph G, int s, int t)
{
        return DAGreach(K, G->sc[s], G->sc[t]);
}