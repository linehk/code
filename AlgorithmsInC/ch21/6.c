// 无环网中的最长路径

static int ts[maxV];
void GRAPHlpt(Graph G, int s, int st[], double wt[])
{
        int i;
        int v;
        int w;
        link t;
        GRAPHts(G, ts);
        for (v = ts[i = 0]; i < G->V; v = ts[i++]) {
                for (t = G->adj[v]; t != NULL; t = t->next) {
                        if (wt[w = t->v] < wt[v] + t->wt) {
                                st[w] = v;
                                wt[w] = wt[v] + t->wt;
                        }
                }
        }
}