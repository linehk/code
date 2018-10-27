// 归约到最大流的可行流

void insertSTlinks(Graph G, int s, int t)
{
        int i;
        int sd;
        for (i = 0; i < G->V; v++) {
                if ((sd = G->sd[i]) >= 0) {
                        GRAPHinsertE(G, EDGE(s, i, sd, 0, 0));
                }
        }
        for (i = 0; i < G->V; i++) {
                if ((sd = G->sd[i]) < 0) {
                        GRAPHinsertE(G, EDGE(i, t, -sd, 0, 0));
                }
        }
}

void removeSTlinks(Graph G)
{
        int i;
        for (i = 0; i < G->V; i++) {
                G->adj[i] = G->adj[i]->next;
        }
}

int GRAPHfeasible(Graph G)
{
        int s = G->V;
        int t = G->V + 1;
        int sd = 0;
        int link u;
        insertSTlinks(G, s, t);
        G->V += 2;
        GRAPHmaxflow(G, s, t);
        for (u = G->adj[s]; u != NULL; u = u->next) {
                sd += u->cap - u->flow;
        }
        for (u = G->adj[t]; u != NULL; u = u->next) {
                sd += u->cap - u->flow;
        }
        G->V -= 2;
        removeSTlinks(G);
        return sd;
}