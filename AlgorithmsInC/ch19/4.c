// 基于 DFS 的传递闭包

void TCdfsR(Graph G, Edge e)
{
        link t;
        G->tc[e.v][e.w] = 1;
        for (t = G->adj[e.w]; t != NULL; t = t->next) {
                if (G->tc[e.v][t->v] == 0) {
                        TCdfsR(G, EDGE(e.v, t->v));
                }
        }
}

void GRAPHtc(Graph G, Edge e)
{
        int v;
        int w;
        G->tc = MATRIXint(G->V, G->V, 0);
        for (v = 0; v < G->V; v++) {
                TCdfsR(G, EDGE(v, v));
        }
}

int GRAPHreach(Graph G, int s, int t)
{
        return G->tc[s][t];
}