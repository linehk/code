// 2-可着色性

int dfsRcolor(Graph G, int v, int c)
{
        link t;
        G->color[v] = 1 - c;
        for (t = G->adj[v]; t != NULL; t = t->next) {
                if (G->color[t->v] == -1) {
                        if (!dfsRcolor(G, t->v, 1 - c)) {
                                return 0;
                        }
                } else if (G->color[t->v] != c) {
                        return 0;
                }
        }
        return 1;
}

int GRAPHtwocolor(Graph G)
{
        int v;
        int id = 0;
        G->color = malloc(G->V * sizeof(int));
        for (v = 0; v < G->V; v++) {
                G->color[v] = -1;
        }
        for (v = 0; v < G->V; v++) {
                if (G->color[v] == -1) {
                        if (!dfsRcolor(G, v, 0)) {
                                return 0;
                        }
                }
        }
        return 1;
}