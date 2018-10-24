// Warshall 算法

void GRAPHtc(Graph G)
{
        int i;
        int s;
        int t;
        G->tc = MATRIXint(G->V, G->V, 0);
        for (s = 0; s < G->V; s++) {
                for (t = 0; t < G->V; t++) {
                        G->tc[s][t] = G->adj[s][t];
                }
        }
        for (s = 0; s < G->V; s++) {
                G->tc[s][s] = 1;
        }
        for (i = 0; i < G->V; i++) {
                for (s = 0; s < G->V; s++) {
                        if (G->adj[s][i] == 1) {
                                for (t = 0; t < G->V; t++) {
                                        if (G->tc[i][t] == 1) {
                                                G->tc[s][t] = 1;
                                        }
                                }
                        }
                }
        }
}

int GRAPHreach(Graph G, int s, int t) {
        return G->tc[s][t];
}