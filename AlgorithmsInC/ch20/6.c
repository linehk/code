// Boruvka MST 算法

Edge nn[maxV];
Edge a[maxE];
void GRAPHmstE(Graph G, Edge mst[])
{
        int h;
        int i;
        int j;
        int k;
        int v;
        int w;
        int N;
        Edge e;
        int E = GRAPHedges(a, G);
        for (UFinit(G->V); E != 0; E = N) {
                for (k = 0; k < G->V; k++) {
                        nn[k] = EDGE(G->V, G->V, maxWT);
                }
                for (h = 0, N = 0; h < E; h++) {
                        i = find(a[h].v);
                        j = find(a[h].w);
                        if (i == j) {
                                continue;
                        }
                        if (a[h].wt < nn[i].wt) {
                                nn[i] = a[h];
                        }
                        if (a[h].wt < nn[j].wt) {
                                nn[j] = a[h];
                        }
                        a[N++] = a[h];
                }
                for (k = 0; k < G->V; k++) {
                        e = nn[k];
                        v = e.v;
                        w = e.w;
                        if ((v != G->V) && !UFfind(v, w)) {
                                UFunion(v, w);
                                mst[k] = e;
                        }
                }
        }
}