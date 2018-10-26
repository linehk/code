// 无环网中的所有最短路径

void SPdfsR(Graph G, int s)
{
        link u;
        int i;
        int t;
        double wt;
        int **p = G->path;
        double **d = G->dist;
        for (u = G->adj[s]; u != NULL; u = u->next) {
                t = u->v;
                wt = u->wt;
                if (d[s][t] > wt) {
                        d[s][t] = wt;
                        p[s][t] = t;
                }
                if (d[t][t] == maxWT) {
                        SPdfsR(G, t);
                }
                for (i = 0; i < G->V; i++) {
                        if (d[t][i] < maxWT) {
                                if (d[s][i] > wt + d[t][i]) {
                                        d[s][i] = wt + d[t][i];
                                        p[s][i] = t;
                                }
                        }
                }
        }
}

void GRAPHspALL(Graph G)
{
        int v;
        G->dist = MATRIXdouble(G->V, G->V, maxWT);
        G->path = MATRIXint(G->V, G->V, G->V);
        for (v = 0; v < G->V; v++) {
                if (G->dist[v][v] == maxWT) {
                        SPdfsR(G, v);
                }
        }
}