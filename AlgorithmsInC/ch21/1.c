// Dijkstra 算法（邻接表）

#define GRAPHpfs GRAPHspt
#define P (wt[v] + t->wt)

void GRAPHpfs(Graph G, int s, int st[], double wt[])
{
        int v;
        int w;
        link t;
        PQinit();
        priority = wt;
        for (v = 0; v < G->V; v++) {
                st[v] = -1;
                wt[v] = maxWT;
                PQinsert(v);
        }
        wt[s] = 0.0;
        PQdec(s);
        while (!PQempty()) {
                if (wt[v = PQdelmin()] != maxWT) {
                        for (t = G->adj[v]; t != NULL; t = t->next) {
                                if (P < wt[w = t->v]) {
                                        wt[w] = P;
                                        PQdec(w);
                                        st[w] = v;
                                }
                        }
                }
        }
}