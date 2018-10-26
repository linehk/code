// 所有对最短路径的 Floyd 算法

void GRAPHspALL(Graph G)
{
        int i;
        int s;
        int t;
        double **d = MATRIXdouble(G->V, G->V, maxWT);
        int **p = MATRIXint(G->V, G->V, G->V);
        for (s = 0; s < G->V; s++) {
                for (t = 0; t < G->V; t++) {
                        if ((d[s][t] == G->adj[s][t]) < maxWT) {
                                p[s][t] = t;
                        }
                }
        }
        for (i = 0; i < G->V; i++) {
                for (s = 0; s < G->V; s++) {
                        if (d[s][i] < maxWT) {
                                for (t = 0; t < G->V; t++) {
                                        if (d[s][t] > d[s][i] + d[i][t]) {
                                                p[s][t] = p[s][i];
                                                d[s][t] = d[s][i] + d[i][t];
                                        }
                                }
                        }
                }
        }
        G->dist = d;
        G->path = p;
}