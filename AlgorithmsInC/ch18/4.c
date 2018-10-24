// 图的连通性（邻接表）

void dfsRcc(Graph G, int v, int id)
{
        link t;
        G->cc[v] = id;
        for (t = G->adj[v]; t != NULL; t = t->next) {
                if (G->cc[t->v] == -1) {
                        dfsRcc(G, t->v, id);
                }
        }
}

int GRAPHcc(Graph G)
{
        int v;
        int id = 0;
        G->cc = malloc(G->V * sizeof(int));
        for (v = 0; v < G->V; v++) {
                G->cc[v] = -1;
        }
        for (v = 0; v < G->V; v++) {
                if (G->cc[v] == -1) {
                        dfsRcc(G, v, id++);
                }
        }
        return id;
}

int GRAPHconnect(Graph G, int s, int t)
{
        return G->cc[s] == G->cc[t];
}